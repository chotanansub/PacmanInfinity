#include "pacin.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 16

// node for stack
typedef struct StackNode {
  MAP_T *vertex;
  struct StackNode *next;
} StackNode;

// top of stack
typedef struct Stack {
  StackNode *top;
} Stack;

// start create stack
Stack *create_stack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

// check that stack is empty or not
// for stop dfs
bool is_empty(Stack *stack) { return (stack->top == NULL); }

// add node to stack
void push(Stack *stack, MAP_T *vertex) {
  StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
  newNode->vertex = vertex;
  newNode->next = stack->top;
  stack->top = newNode;
}

// delete top node ที่สำรวจจนสุดทางแล้วออกจาก stack
// change top to top next
MAP_T *pop(Stack *stack) {
  if (stack->top == NULL) {
    return NULL;
  }
  MAP_T *vertex = stack->top->vertex;
  StackNode *temp = stack->top;
  stack->top = stack->top->next;
  free(temp);
  return vertex;
}

// random intager
int randint(int lower, int upper) {
  return (rand() % (upper - lower + 1)) + lower;
}

// check input from user (accept only int)
// check numbers of input must equal with num
int checkInput(char *input, int num) {
  char *token = NULL;
  char str[MAX];
  int count = 0;
  strcpy(str, input);
  str[strlen(str) - 1] = '\0';
  token = strtok(str, " ");

  while (token != NULL) {
    if (isdigit(*token) == 0) {
      printf("Input must be number\n");
      return -1;
    }
    token = strtok(NULL, " ");
    count++;
  }

  if (count != num) {
    printf("Wrong Input\n");
    return -1;
  }

  return 0;
}

// initilize map
// allocate memory
// assign value to object of node and add edge for every cell
void initMap(MAP_T **map, int width, int length) {
  *map = (MAP_T *)calloc(width * length, sizeof(MAP_T));
  MAP_T *node = *map;
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      node->cell = i * length + j;
      node->row = i;
      node->col = j;
      node->visited = false;
      node->rightWall = 1; // 1 have wall
      node->downWall = 1;
      node->item = 0;

      // เก็บเป็นทุก cell ใน 1 มิติ แต่ตอนสร้างกราฟและ add edge มองเป็น 2 มิติ
      if (j < length - 1) {
        node->right = node + 1;
      } else { // node ที่อยู่หลักสุดท้ายในตาราง ไม่มี node ข้างเคียงทางด้านขวา
        node->right = NULL;
      }

      if (j > 0) {
        node->left = node - 1;
      } else { // node ที่อยู่หลักแรกในตาราง ไม่มี node ข้างเคียงทางด้านซ้าย
        node->left = NULL;
      }

      if (i < width - 1) {
        node->down = node + length;
      } else { // node ที่อยู่แถวสุดท้ายในตาราง ไม่มี node ข้างเคียงทางด้านล่าง
        node->down = NULL;
      }

      if (i > 0) {
        node->up = node - length;
      } else { // node ที่อยู่แถวบนสุดในตาราง ไม่มี node ข้างเคียงทางด้านบน
        node->up = NULL;
      }
      node++;
    }
  }
}

// เช็คว่า vertex มีเส้นทางสำหรับท่องต่อหรือไม่
bool beforePop(MAP_T *current) {
  MAP_T *upNode = current->up;
  MAP_T *downNode = current->down;
  MAP_T *leftNode = current->left;
  MAP_T *rightNode = current->right;

  // มุม up-left
  if (upNode == NULL && leftNode == NULL) {
    if (downNode->visited == true && rightNode->visited == true) {
      return false;
    }
  }
  // มุม up-right
  else if (upNode == NULL && rightNode == NULL) {
    if (downNode->visited == true && leftNode->visited == true) {
      return false;
    }
  }
  // มุม down-left
  else if (downNode == NULL && leftNode == NULL) {
    if (upNode->visited == true && rightNode->visited == true) {
      return false;
    }
  }
  // มุม down-right
  else if (downNode == NULL && rightNode == NULL) {
    if (upNode->visited == true && leftNode->visited == true) {
      return false;
    }
  }

  // ขอบด้านนอก (ที่ไม่ใช่มุม)
  // up
  else if (upNode == NULL) { // ขอบด้านบน มีเส้นทางให้สำรวจ down left right
    if (downNode->visited == true && leftNode->visited == true &&
        rightNode->visited == true) {
      return false;
    }
  }
  // down
  else if (downNode == NULL) {
    if (upNode->visited == true && leftNode->visited == true &&
        rightNode->visited == true) {
      return false;
    }
  }
  // left
  else if (leftNode == NULL) {
    if (upNode->visited == true && downNode->visited == true &&
        rightNode->visited == true) {
      return false;
    }
  }
  // right
  else if (rightNode == NULL) {
    if (upNode->visited == true && downNode->visited == true &&
        leftNode->visited == true) {
      return false;
    }
  }

  // inside table
  else {
    if (upNode->visited == true && downNode->visited == true &&
        leftNode->visited == true && rightNode->visited == true) {
      return false;
    }
  }
  return true;
}

// randomized DFS by using stack
// random start node
// random direction
// 1 is up || 2 is down || 3 is left || 4 is right
void generatePath(MAP_T *maze, int width, int length) {
  MAP_T *map = maze;
  int direc = 0;
  Stack *stack = create_stack();

  // random start node
  int row, col, move;
  row = randint(1, width);
  col = randint(1, length);
  move = (length * (row - 1)) + (col - 1);
  map = map + move;

  // start randomized dfs
  push(stack, map);
  MAP_T *current = map;
  current->visited = true;

  while (!is_empty(stack)) { // เช็คว่ายังเหลือ node อยู่ใน stack ไหม ถ้าเหลือก็ทำต่อ
    current = stack->top->vertex;
    while (beforePop(
        current)) { // เช็คว่าสำรวจจนสุดหรือยัง ถ้าไม่มีทางให้สำรวจต่อก็ออกจากลูป และ pop

      direc = randint(1, 4); // random direction

      // up
      // move current to up and change downWall
      if (direc == 1) {
        if (current->up != NULL && current->up->visited == false) {
          current = current->up;
          current->downWall = 0;
          current->visited = true; // change visited of vertex
          push(stack, current);    // push vertex in stack
        }
      }

      // down
      // change downWall and move current to down
      else if (direc == 2) {
        if (current->down != NULL && current->down->visited == false) {
          current->downWall = 0;
          current = current->down;
          current->visited = true;
          push(stack, current);
        }
      }

      // left
      // move current to left and change rightWall
      else if (direc == 3) {
        if (current->left != NULL && current->left->visited == false) {
          current = current->left;
          current->rightWall = 0;
          current->visited = true;
          push(stack, current);
        }
      }

      // right
      // change rightWall and move current to right
      else if (direc == 4) {
        if (current->right != NULL && current->right->visited == false) {
          current->rightWall = 0;
          current = current->right;
          current->visited = true;
          push(stack, current);
        }
      }
    }
    pop(stack); // pop หลังจากสำรวจเส้นทางนั้น ๆ จนตันแล้ว
  }
}

// random and place item in maze
// 1 -> 🍎 || 2 -> 🍌 || 3 -> 🍊 || 4 -> 🍒
void randomItem(MAP_T *map, int width, int length) {
  int item;
  MAP_T *node = map;

  for (int i = 0; i < length * width - 1; i++) {
    item = randint(0, 20); // ramdom item for each cell
    if (item > 4) {
      item = 0;
    }
    node->item = item; // place item
    node++;
  }
}

void removeAllItem(MAP_T *map, int width, int length) {
  int item;
  MAP_T *node = map;
  for (int i = 0; i < length * width - 1; i++) {
    node->item = -1;
    node++;
  }
  node->item = -1; // last node
}

// input position of cell and type of item from user
// row must less than width and col must less than length
int getRowColItem(int *row, int *col, int *item, int width, int length) {
  char str[MAX];
  int check;

  do {
    do {
      // printf("Enter cell that want place item (row col): ");
      fgets(str, MAX, stdin);
      if (*str == '\n')
        return 0;
      else if (str[0] == '5' && str[1] == '\n')
        return 5;
      check = checkInput(str, 3);
    } while (check == -1);

    sscanf(str, "%d %d %d", row, col, item);
    if (*row > width || *col > length)
      printf("Row or Col input wrong\n");

  } while (*row > width || *col > length);
  return 1;
}

// place item or delete item from user
// 0 -> empty || 1 -> 🍎 || 2 -> 🍌 || 3 -> 🍊 || 4 -> 🍒
int placeItem(MAP_T *map, int width, int length, int count) {
  int row, col, item, check;
  int move;
  MAP_T *node = map;

  // ลูปเพื่อรับ item และวาง item ตามจำนวน item ที่ผู้ใช้ต้องการวาง
  for (int i = 0; i < count; i++) {
    node = map;

    // get input from user row, col, type of item
    check = getRowColItem(&row, &col, &item, width, length);

    // check command
    if (check == 0 || check == 5)
      return check;

    // เลื่อนแถวลงมา แล้วบวก col แต่ลบ -1 เพราะบวกจากหลักแรก
    move = (length * (row - 1)) + (col - 1);
    node = node + move;
    node->item = item;
  }

  return 1;
}

// get input for edit wall
// row col side typeWall
// รับตัวเลขครบ 4 ตัวหรือป่าว
int getEditWall(int *row, int *col, int *side, int *typeWall) {
  int check;
  char str[MAX];
  do {
    fgets(str, MAX, stdin);
    if (*str == '\n')
      return 0;
    check = checkInput(str, 4); // input 4 number
  } while (check == -1);
  sscanf(str, "%d %d %d %d", row, col, side, typeWall);

  return 1;
}

// เช็คว่า input ที่รับเข้ามาถูกต้องและสามารถทำได้หรือไม่
// side -> 1 : up | 2 : down | 3 : left | 4 : right
// typeWall -> 0 : space | 1 : wall
int checkWall(int width, int length, int row, int col, int side, int typeWall) {

  if (row > width || col > length || (typeWall != 0 && typeWall != 1)) {
    printf("Wrong Input\n");
    return -1;

  } else if (row == 1 && side == 1) { // cannot open top wall
    printf("Cannot open top wall\n");
    return -1; // cannot do

  } else if (row == width && side == 2) { // cannot open down wall
    printf("Cannot open down wall\n");
    return -1;

  } else if (col == 1 && side == 3) { // cannot open left most wall
    printf("Cannot open left most wall\n");
    return -1;

  } else if (col == length && side == 4) { // cannot open right most wall
    printf("Cannot open right most wall\n");
    return -1;

  } else if (side != 1 && side != 2 && side != 3 && side != 4) {
    printf("Side Input Wrong\n");
    return -1;
  }

  return 1;
}

// side -> 1 : up | 2 : down | 3 : left | 4 : right
// typeWall -> 0 : space | 1 : wall
int editWall(MAP_T *map, int width, int length) {
  int side, row, col, typeWall, move, check;
  MAP_T *node = map;

  // loop until get correct input from user
  while (true) {

    // get input for edit wall
    check = getEditWall(&row, &col, &side, &typeWall);
    if (check == 0) // return to main menu commamnd
      return check;

    // check input before edit wall
    check = checkWall(width, length, row, col, side, typeWall);
    if (check == 1)
      break;
  }

  if (side == 1) { // up
    // cell ที่ต้องการเปลี่ยน -> cell ด้านบนของ cell ที่ต้องการเปลี่ยน -> เปลี่ยน downWall
    // แทน
    move = (length * (row - 1)) + (col - 1);
    node = node + move;
    node = node->up;
    node->downWall = typeWall;

  } else if (side == 2) { // down
    move = (length * (row - 1)) + (col - 1);
    node = node + move;
    node->downWall = typeWall;

  } else if (side == 3) { // left
    // cell ที่ต้องการเปลี่ยน -> cell ด้านซ้ายของ cell ที่ต้องการเปลี่ยน -> เปลี่ยน rigthWall
    // แทน
    move = (length * (row - 1)) + (col - 1);
    node = node + move;
    node = node->left;
    node->rightWall = typeWall;

  } else if (side == 4) { // right
    move = (length * (row - 1)) + (col - 1);
    node = node + move;
    node->rightWall = typeWall;
  }

  return 1;
}

void exportMap(MAP_T *map, int width, int length, char *filename) {
  MAP_T *node = map;
  MAP_T *right = map;

  // create and open new file
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Error opening the file %s", filename);
    return;
  }

  fprintf(fp, "%d %d\n", width, length);

  // print top wall only first line
  // loop
  // left wall -> loop (item -> right wall) new line -> down wall new line
  for (int i = 0; i < width; i++) {
    // top wall
    if (i == 0) {
      for (int j = 0; j < length; j++) {
        fprintf(fp, "+");
        fprintf(fp, "---");
      }
      fprintf(fp, "+\n");
    }

    // left wall
    fprintf(fp, "|");

    // items and right walls
    right = node;
    for (int j = 0; j < length; j++) {
      // check item
      if (right->item == 0) {
        fprintf(fp, "   ");
      } else {
        fprintf(fp, " %d ", right->item);
      }

      // right wall
      if (right->rightWall) {
        fprintf(fp, "|");
      } else {
        fprintf(fp, " ");
      }
      right = right->right;
    }
    fprintf(fp, "\n");

    // down wall
    for (int j = 0; j < length; j++) {
      fprintf(fp, "+");
      if (node->downWall) {
        fprintf(fp, "---");
      } else {
        fprintf(fp, "   ");
      }
      node++;
    }

    fprintf(fp, "+\n");
  }

  fclose(fp);

  printf("\n✅ Export Completed ✅\n⭐️ Press Enter to Return to Menu "
         "⭐️\n");
  char enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
}

void printMap(MAP_T *map, int width, int length) {
  MAP_T *node = map;
  MAP_T *right = map;

  // print top wall only first line
  // loop for print
  // [left wall -> loop print in row (item -> right wall) new line
  // -> loop print down wall new line]
  for (int i = 0; i < width; i++) {

    // top wall
    if (i == 0) {
      for (int j = 0; j < length; j++) {
        printf("+");
        printf("---");
      }
      printf("+\n");
    }

    // left wall
    printf("|");

    // items and right walls
    right = node;
    for (int j = 0; j < length; j++) {
      // check item
      if (right->item == 1) {
        printf("🍎 ");
      } else if (right->item == 2) {
        printf("🍌 ");
      } else if (right->item == 3) {
        printf("🍊 ");
      } else if (right->item == 4) {
        printf("🍒 ");
      } else {
        printf("   ");
      }

      // right wall
      if (right->rightWall) {
        printf("|");
      } else {
        printf(" ");
      }
      right = right->right;
    }
    printf("\n");

    // down wall
    for (int j = 0; j < length; j++) {
      printf("+");
      if (node->downWall) {
        printf("---");
      } else {
        printf("   ");
      }
      node++;
    }

    printf("+\n");
  }
}

void printMapIndex(MAP_T *map, int width, int length) {
  MAP_T *node = map;
  MAP_T *right = map;

  // print column numbers
  printf("   ");
  for (int j = 0; j < length; j++) {
    printf("%2d  ", j + 1);
  }
  printf("\n");

  // print top wall
  printf("  +");
  for (int j = 0; j < length; j++) {
    printf("---+");
  }
  printf("\n");

  // loop through the map
  for (int i = 0; i < width; i++) {
    // print row number
    printf("%2d|", i + 1);

    // print items and right walls
    right = node;
    for (int j = 0; j < length; j++) {
      // check item
      if (right->item == 1) {
        printf("🍎 ");
      } else if (right->item == 2) {
        printf("🍌 ");
      } else if (right->item == 3) {
        printf("🍊 ");
      } else if (right->item == 4) {
        printf("🍒 ");
      } else {
        printf("   ");
      }

      // right wall
      if (right->rightWall) {
        printf("|");
      } else {
        printf(" ");
      }
      right = right->right;
    }
    printf("\n");

    // print down walls
    printf("  +");
    for (int j = 0; j < length; j++) {
      if (node->downWall) {
        printf("---+");
      } else {
        printf("   +");
      }
      node++;
    }

    printf("\n");
  }
}

// create sample maze for print in UI
void printSampleMaze(int width, int length) {
  MAP_T *sampleMaze;
  MAP_T *node = sampleMaze;
  int item;

  // create map and random item in map
  initMap(&sampleMaze, width, length);
  srand(time(NULL));
  node = sampleMaze;
  randomItem(node, width, length);

  // dfs for creating maze
  generatePath(sampleMaze, width, length);
  printMap(sampleMaze, width, length);
}

void intInput(int *input) {
  char buffer[MAX];
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = '\0';
  *input = atoi(buffer);
}
