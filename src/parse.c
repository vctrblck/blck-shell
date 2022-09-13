// parse.c

// Modules:

#include <string.h>
#include <stdlib.h>

// Code:

#define TOKEN_BUFFER_SIZE  64
#define TOKEN_DELIMITER    " \t\r\a\n"
#define TOKENS_BUFFER_SIZE 64 * 1024
#define TOKENS_DELIMITER    "&"


char **parse_args(char *line)
{
  int buffer_size = TOKEN_BUFFER_SIZE;
  char **tokens = malloc(sizeof(char*) * buffer_size);
  int buffer_position = 0;
  char *current_token;

  current_token = strtok(line, TOKEN_DELIMITER);
  while (current_token != NULL)
  {
    tokens[buffer_position] = current_token;
    buffer_position += 1;

    if (buffer_position >= buffer_size)
    {
      buffer_size += TOKEN_BUFFER_SIZE;
      tokens = realloc(tokens, sizeof(char*) * buffer_size);
    }

    current_token = strtok(NULL, TOKEN_DELIMITER);
  }

  tokens[buffer_position] = NULL;
  return tokens;
}

char **parse_commands(char *line)
{
  int buffer_size = TOKENS_BUFFER_SIZE;
  char **commands = malloc(sizeof(char*) * buffer_size);
  int buffer_position = 0;
  char *current_command;

  current_command = strtok(line, TOKENS_DELIMITER);
  while (current_command != NULL)
  {
    commands[buffer_position] = current_command;
    buffer_position += 1;

    if (buffer_position >= buffer_size)
    {
      buffer_size += TOKEN_BUFFER_SIZE;
      commands = realloc(commands, sizeof(char*) * buffer_size);
    }

    current_command = strtok(NULL, TOKENS_DELIMITER);
  }

  commands[buffer_position] = NULL;
  return commands;
}

char ***parse(char *line)
{
  int buffer_size = TOKENS_BUFFER_SIZE;
  char ***table = malloc(sizeof(char*) * buffer_size);
  int table_position = 0;
  char **current_command;
  char **command_strings;

  command_strings = parse_commands(line);
  while (command_strings[table_position] != NULL)
  {
    current_command = parse_args(command_strings[table_position]);
    table[table_position] = current_command;

    table_position += 1;
  }

  return table;
}

// parse.c ends here