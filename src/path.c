// path.c

// Modules:

#include <stdlib.h>
#include <string.h>
#include "./path.h"

// Code:

#define PATH_SEPARATOR ":"


int path(char **args)
{
  char *path;
  int argc = 0;

  path = getenv("PATH");

  // Count arguments
  while(args[++argc] != NULL);

  for (int i = 1; i < argc; i += 1)
  {
    strcat(path, PATH_SEPARATOR);
    strcat(path, args[i]);
  }

  setenv("PATH", path, 1);

  return 1;
}

// path.c ends here