// execute.c

// Modules:

#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./execute.h"
#include "./cd.h"
#include "./path.h"
#include "./quit.h"

int execute(char **args)
{
  pid_t pid;
  pid_t wpid;
  int status;

  // Check if command is empty
  if (args[0] == NULL) return 1;

  // Execute built-in cd command
  if (!strcmp(args[0], "cd")) cd(args);

  // Execute built-in quit command
  if (!strcmp(args[0], "exit")) quit(args);

  // Execute built-in path command
  if (!strcmp(args[0], "path")) path(args);

  pid = fork();
  if (pid == 0)
  {
    // Inside child process
    char **new_args;

    // Redirect child process output (if necessary)
    int i = 0;
    while (args[i] != NULL)
    {
      if (strcmp(args[i], ">")) new_args[i] = args[i];

      if (!strcmp(args[i], ">"))
      {
        freopen(args[i + 1], "w+", stdout);
        break;
      }

      i += 1;
    }

    if (execvp(new_args[0], new_args) == -1)
    {
      // Report execute error
    }

    freopen("/dev/stdout", "w", stdout);
    exit(EXIT_FAILURE);
  }
  else if (pid < 0)
  {
    // Report fork error
  }
  else
  {
    // Inside parent process

    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

// execute.c ends here