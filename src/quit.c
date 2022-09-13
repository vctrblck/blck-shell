// quit.c

// Modules:

#include <stdlib.h>
#include "./error.h"
#include "./quit.h"

// Code:

int quit(char **args)
{
  int argc = 0;

  // Count arguments
  while(args[++argc] != NULL);

  // Handle error
  if (argc != 1) {
    die();
  }

  exit(EXIT_SUCCESS);
}

// quit.c ends here