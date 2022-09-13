// error.c

// Modules:

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "./error.h"

// Code:

void die()
{
  char error_message[30] = "An error has occurred\n";

  write(STDERR_FILENO, error_message, strlen(error_message));
  exit(0);
}

// error.c ends here