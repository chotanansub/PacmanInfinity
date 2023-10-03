#include <stdbool.h>

#ifndef PACIN_H
#define PACIN_H

typedef struct MAP {
  int cell;
  int row;
  int col;
  bool visited;

  int rightWall; // 0 : space | 1 : wall
  int downWall;  // 0 : space | 1 : wall

  int item; // 1 -> 🍎 || 2 -> 🍌 || 3 -> 🍊 || 4 -> 🍒

  // Direction Links
  struct MAP *up;
  struct MAP *down;
  struct MAP *right;
  struct MAP *left;

} MAP_T;

void initMap(MAP_T **map, int width, int length);
void generatePath(MAP_T *map, int width, int length);
void randomItem(MAP_T *map, int width, int length);
void removeAllItem(MAP_T *map, int width, int length);
int placeItem(MAP_T *map, int width, int length, int count);
int editWall(MAP_T *map, int width, int length);
void printMap(MAP_T *map, int width, int length);
void printMapIndex(MAP_T *map, int width, int length);
void printSampleMaze(int width, int length);
void exportMap(MAP_T *map, int width, int length, char *filename);
void intInput(int *input);

#endif