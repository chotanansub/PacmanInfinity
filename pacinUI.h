#include "pacin.h"
#ifndef PACINUI_H
#define PACINUI_H

//void printRepeat();
void breakln();
void printWelcome();
void printMainMenu();
void printCreateMap(MAP_T **map, int *width, int *length);
void printEditMap(MAP_T *map, int *width, int *length);
void printDisplayMap(MAP_T *map, int *width, int *length);
void printExportMap(MAP_T *map, int width, int length);
int printExit();

#endif