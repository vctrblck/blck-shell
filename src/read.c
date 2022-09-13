// read.c

// Modules:

#include <stdlib.h>
#include <string.h>
#include "./read.h"

// Code:

#define READ_LINE_BUFFER_SIZE  1024
#define READ_LINES_BUFFER_SIZE 1024 * 40


char *read_line()
{
  char *line = NULL;
  size_t buffer_size = 0;

  if (getline(&line, &buffer_size, stdin) == -1)
  {
    if (feof(stdin)) exit(EXIT_SUCCESS); // Received an EOF
  }

  return line;
}

char **read_lines(FILE *batch)
{
  char **lines = malloc(sizeof(char*) * READ_LINES_BUFFER_SIZE);
  char *line = NULL;
  size_t buffer_size = 0;
  ssize_t line_size = 0;
  int line_position = 0;

  line_size = getline(&line, &buffer_size, batch);
  while (line_size != -1)
  {
    lines[line_position] = strdup(line);
    line_position += 1;
    line_size = getline(&line, &buffer_size, batch);
  }

  return lines;
}

// read.c ends here