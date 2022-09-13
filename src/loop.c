// loop.c

// Modules:

#include <stdio.h>
#include <stdlib.h>
#include "./read.h"
#include "./parse.h"
#include "./execute.h"

// Code:

#define SHELL_NAME "witsshell"

void interactive_loop(void)
{
  char *line;
  char ***table;
  int status;

  do {
    printf("%s> ", SHELL_NAME); // Prompt

    line = read_line();
    table = parse(line);
    
    int i = 0;
    while (table[i] != NULL)
    {
      status = execute(table[i]);
      i += 1;
    }

    free(line);
  } while (status);
}

void batch_loop(FILE *batch)
{
  char **lines;
  char ***table;
  int status;

  lines = read_lines(batch);

  int i = 0;
  while (lines[i] != NULL)
  {
    table = parse(lines[i]);

    int j = 0;
    while (table[j] != NULL)
    {
      status = execute(table[j]);
      j += 1;
    }
    i += 1;
  }
}

// loop.c ends here