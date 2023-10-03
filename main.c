#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// The ad-hoc library we developed
#include "pacin.h"
#include "pacinUI.h"

int main(void) {
  MAP_T *maze = NULL;
  int width, length, cmd, isRunning;
  char input[3];
  isRunning = 1;

  width = 0;
  length = 0;

  printWelcome();
  intInput(&cmd);

  while (isRunning) {
    printMainMenu();
    intInput(&cmd);
    if (cmd == 1) {
      printCreateMap(&maze, &width, &length);

    } else if (cmd == 2) {
      if (maze != NULL) // must create maze before
        printEditMap(maze, &width, &length);

    } else if (cmd == 3) {
      if (maze != NULL) // must create maze before
        printDisplayMap(maze, &width, &length);

    } else if (cmd == 4) {
      if (maze != NULL) // must create maze before
        printExportMap(maze, width, length);

    } else {
      isRunning = printExit();
    }
  }
  return 0;
}
