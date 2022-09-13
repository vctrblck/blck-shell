// main.c

// Modules:

#include <stdio.h>
#include <stdlib.h>
#include "./loop.h"

// Code:

int main(int argc, char **argv)
{
  char *original_path;
  char *initial_path;
  
  // Set initial path
  initial_path = "/bin";
  original_path = getenv("PATH");
  setenv("PATH", initial_path, 1);

  switch(argc)
  {
    case 1:
      interactive_loop();
      break;
    case 2:
      FILE *batch;

      batch = fopen(argv[1], "r");
      batch_loop(batch);
      fclose(batch);
      break;

    default:
      puts("Either you've enterred too many arguments or something's wrong!");
  }

  // Restore original path
  setenv("PATH", original_path, 1);

  return 0;
}

// main.c ends here