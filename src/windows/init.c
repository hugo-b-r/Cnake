/*

init.c

function for init and deinit

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_platform() { ; }

void gracefully_shutdown(char *message) {
  printf("%s", message);
  exit(0); 
}
