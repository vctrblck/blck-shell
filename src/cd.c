// cd.c

// Modules:

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "./cd.h"
#include "./error.h"

// Code:

int cd(char **args)
{
  char *path = NULL;
  int argc = 0;

  // Count arguments
  while(args[++argc] != NULL);

  // Handle error
  if (argc != 2) {
    die();
  }

  path = args[1];

  chdir(path);

  return 1;
}

// cd.c ends here