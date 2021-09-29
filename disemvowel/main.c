#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line;
  size_t size;
  
  size = 100;
  line = (char*) malloc (size + 1);

  while (getline(&line, &size, stdin) > 0) {
    char *disemvowel_string = disemvowel(line);
    printf("%s\n", disemvowel_string);
    free(disemvowel_string);
  }
  free(line);
}
