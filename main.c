// main.c

// A simple command-line interpreter

// Modules:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

// Code:

#define TRUE 1
#define FALSE 0

#define SHELL_NAME "bsh"

#define READ_TOKEN_BUFFER_SIZE 64
#define READ_TOKEN_BUFFER_DELIMITER " \t\r\n\a"

// Parses a command string
// -----------------------
//
// return (char**) a token string array

char **parse(char *line)
{
  int token_buffer_size = READ_TOKEN_BUFFER_SIZE;
  int token_buffer_position = 0;
  char **tokens = malloc(sizeof(char*) * token_buffer_size);
  char *current_token;

  current_token = strsep(&line, READ_TOKEN_BUFFER_DELIMITER);
  while (current_token != NULL)
  {
    tokens[token_buffer_position] = current_token;
    token_buffer_position += 1;

    current_token = strsep(&line, READ_TOKEN_BUFFER_DELIMITER);
  }

  tokens[token_buffer_position] = NULL;
  return tokens;
}

// Reads a command string from STDIN
// ---------------------------------
//
// return: (char*) a command-line string

char *read()
{
  char *line = NULL;
  ssize_t read_buffer_size = 0;

  // Reads command-ling string
  // Assigns string to `line`
  // Assigns buffer size to `read_buffer_size`
  if (getline(&line, &read_buffer_size, stdin) == -1)
  {
    if (feof(stdin))
    {
      exit(EXIT_SUCCESS);
    } 
    else
    {
      perror("readline");
      exit(EXIT_FAILURE);
    }
  }

  return line;
}

// Executes a command, with command arguments
// ------------------------------------------
// 
// return: (int) a status

int execute(char **args)
{
  pid_t pid;
  pid_t wpid;
  int status;

  // Check if command is empty
  if (args[0] == NULL)
  {
    return 1;
  }

  // Execute built-in exit command
  if (!strcmp(args[0], "exit"))
  {
    exit(EXIT_SUCCESS);
  }

  pid = fork();
  if (pid == 0)
  {
    // Inside child process;
    if (execvp(args[0], args) == -1)
    {
      // Report child process creation error
      perror(SHELL_NAME);
    }
    exit(EXIT_FAILURE);
  }
  else if (pid < 0)
  {
    // Report process fork error
    perror(SHELL_NAME);
  }
  else
  {
    // Inside parent process;
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

// Runs an interactive loop
// ------------------------
//
// return: (void)

void interactive_loop()
{
  char *line;
  char **args;
  int status;

  while (status)
  {
    line = read();
    args = parse(line);
    status = execute(args);
    
    free(line);
    free(args);
  }
}

int main()
{
  interactive_loop();

  return 0;
}

// main.c ends here
