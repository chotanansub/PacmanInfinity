#include "pacinUI.h"
#include "pacin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 81

void clearScreen() {
  printf(
      "\033[2J"); // clears the entire screen, including the scrollback buffer
  printf("\033[3J"); // clears the scrollback buffer
  printf("\033[%d;%dH", 0,
         0); // moves the cursor to the top-left corner of the screen
}

void printRepeat(char letter, int num) { // repeat printing same character
  for (int i = 0; i < num; i++) {
    printf("%c", letter);
  }
  printf("\n");
}

void breakln(int type) { // printing break line according to breakline type
  switch (type) {
  case 0:
    printRepeat('=', LINE_LENGTH);
    break;
  case 1:
    printRepeat('_', LINE_LENGTH);
    break;
  case 2:
    printRepeat('-', LINE_LENGTH);
    break;
  }
}

void printHeader() {
  breakln(0);
  printf(
      "▒▒▒▒▒▒▒▒▒▒▒▒\t\t\t\tPacman Infinity | 𝗚𝗿𝗼𝘂𝗽 𝟭𝟱\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒\n");
  breakln(0);
}

void printFooter() {
  breakln(0);
  printf("▒▒▒▒▒▒▒▒▒▒▒▒\t\tCPE112 Programming with Data "
         "Structure\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒\n");
  printf(
      "▒▒▒▒▒▒▒▒▒▒▒▒\t\t\tComputer Engineering, KMUTT\t\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒\n");
  breakln(0);
}



void welcomeTitle(){
  breakln(0);

  printf("   ______                                  _         ___ _       _   "
         "          \n");
  printf("  (_____ \\                                | |       / __|_)     (_) "
         " _         \n");
  printf("   _____) )____  ____ ____  _____ ____    | |____ _| |__ _ ____  _ "
         "_| |_ _   _ \n");
  printf("  |  ____(____ |/ ___)    \\(____ |  _ \\   | |  _ (_   __) |  _ \\| "
         "(_   _) | | |\n");
  printf("  | |    / ___ ( (___| | | / ___ | | | |  | | | | || |  | | | | | | "
         "| |_| |_| |\n");
  printf("  |_|    \\_____|\\____)_|_|_\\_____|_| |_|  |_|_| |_||_|  |_|_| "
         "|_|_|  \\__)\\__  |\n");
  printf("                                                                     "
         "   (____/ \n");
  printf("\n\t`•.,¸¸,.•´¯ CPE112 Programming with Data Structure | GROUP 15 "
         "¯`•.,¸¸,.•´ \n");
  printf("\n• • •\t\t\t\t\t  «« P̲r̲e̲s̲s̲ ̲E̲n̲t̲e̲r̲ ̲t̲o̲ ̲s̲t̲a̲r̲t̲  »»\t\t\t\t\t\t• • •\n\n");

  breakln(0);
}


void mainMenuTitle() {
  clearScreen();
  printHeader();
  printf("\t\t\t\t __  __       _         __  __                   \n");
  printf("\t\t\t\t|  \\/  | __ _(_)_ __   |  \\/  | __ _ _ __  _   _ \n");
  printf("\t\t\t\t| |\\/| |/ _` | | '_ \\  | |\\/| |/ _` | '_ \\| | | |\n");
  printf("\t\t\t\t| |  | | (_| | | | | | | |  | | (_| | | | | |_| |\n");
  printf("\t\t\t\t|_|  |_|\\__,_|_|_| |_| |_|  |_|\\__,_|_| |_|\\__,_|\n\n");
  breakln(0);
}

void createMapTitle() {
  clearScreen();
  printHeader();
  printf("   _____                _         _   _                 __  __     "
         "        \n");
  printf("  / ____|              | |       | \\ | |               |  \\/  |  "
         "          \n");
  printf(" | |     _ __ ___  __ _| |_ ___  |  \\| | _____      __ | \\  / | "
         "__ _ _ __  \n");
  printf(" | |    | '__/ _ \\/ _` | __/ _ \\ | . ` |/ _ \\ \\ /\\ / / | "
         "|\\/| |/ _` | '_ \\ \n");
  printf(" | |____| | |  __/ (_| | ||  __/ | |\\  |  __/\\ V  V /  | |  | | "
         "(_| | |_) |\n");
  printf("  \\_____|_|  \\___|\\__,_|\\__\\___| |_| \\_|\\___| \\_/\\_/   "
         "|_|  |_|\\__,_| .__/ \n");
  printf("                                                                   "
         " | |    \n");
  printf("                                                                   "
         " |_|    \n");
  breakln(0);
  printf("\n");
}

void exportMapTitle() {
  clearScreen();
  printHeader();
  printf("\t\t\t ______                       _     __  __               \n");
  printf("\t\t\t|  ____|                     | |   |  \\/  |              \n");
  printf("\t\t\t| |__  __  ___ __   ___  _ __| |_  | \\  / | __ _ _______\n");
  printf("\t\t\t|  __| \\ \\/ / '_ \\ / _ \\| '__| __| | |\\/| |/ _` |_  / _ "
         "\\\n");
  printf("\t\t\t| |____ >  <| |_) | (_) | |  | |_  | |  | | (_| |/ /  __/\n");
  printf("\t\t\t|______/_/\\_\\ .__/ \\___/|_|   \\__| |_|  "
         "|_|\\__,_/___\\___|\n");
  printf("\t\t\t            | |                                           \n");
  printf("\t\t\t            |_|                                           \n");
  breakln(0);
  printf("\n\n\t☆꧁༒☬  List of commands ☬༒꧂☆\n\n");
  printf("\t\t ▒ 1 : Confirm Export\n");
  printf("\t\t ▒ 0 : Return to Mainmenu\n");
  printf("\n\n");
  printFooter();
}

void editMapTitle() {
  clearScreen();
  printHeader();
  printf("\t\t\t\t___  ___              _____    _ _ _             \n");
  printf("\t\t\t\t|  \\/  |             |  ___|  | (_) |            \n");
  printf("\t\t\t\t| .  . | __ _ _ __   | |__  __| |_| |_ ___  _ __ \n");
  printf("\t\t\t\t| |\\/| |/ _` | '_ \\  |  __|/ _` | | __/ _ \\| '__|\n");
  printf("\t\t\t\t| |  | | (_| | |_) | | |__| (_| | | || (_) | |   \n");
  printf("\t\t\t\t\\_|  |_/\\__,_| .__/  \\____/\\__,_|_|\\__\\___/|_|   \n");
  printf("\t\t\t\t             | |                                 \n");
  printf("\t\t\t\t             |_|                                 \n");
  breakln(0);
  printf("\n\n\n");
}

void displayMapTitle() {
  clearScreen();
  printHeader();
  printf("\t\t\t  _____  _           _               \t__  __             \n");
  printf(
      "\t\t\t |  __ \\(_)         | |             \t|  \\/  |            \n");
  printf("\t\t\t | |  | |_ ___ _ __ | | __ _ _   _  \t| \\  / | __ _ _ __  \n");
  printf("\t\t\t | |  | | / __| '_ \\| |/ _` | | | | \t| |\\/| |/ _` | '_ \\ "
         "\n");
  printf(
      "\t\t\t | |__| | \\__ \\ |_) | | (_| | |_| | \t| |  | | (_| | |_) |\n");
  printf("\t\t\t |_____/|_|___/ .__/|_|\\__,_|\\__, | \t|_|  |_|\\__,_| .__/ "
         "\n");
  printf("\t\t\t              | |             __/ |     \t         | |    \n");
  printf("\t\t\t              |_|            |___/     \t\t         |_|    \n");
  breakln(0);
  printf("\n\n\n");
}

void exitTitle() {
  printf("\n\n");
  printf("\t\t\t███████╗██╗  ██╗██╗████████╗\n");
  printf("\t\t\t██╔════╝╚██╗██╔╝██║╚══██╔══╝\n");
  printf("\t\t\t█████╗   ╚███╔╝ ██║   ██║   \n");
  printf("\t\t\t██╔══╝   ██╔██╗ ██║   ██║   \n");
  printf("\t\t\t███████╗██╔╝ ██╗██║   ██║   \n");
  printf("\t\t\t╚══════╝╚═╝  ╚═╝╚═╝   ╚═╝   \n");
  printf("\t\t\t                            \n");
  breakln(1);
}

void goodluckTitle() {
  printf("\n\n");
  printf("\t\t\t   _____                 _   _                _    \n");
  printf("\t\t\t  / ____|               | | | |              | |   \n");
  printf("\t\t\t | |  __  ___   ___   __| | | |    _   _  ___| | __\n");
  printf("\t\t\t | | |_ |/ _ \\ / _ \\ / _` | | |   | | | |/ __| |/ /\n");
  printf("\t\t\t | |__| | (_) | (_) | (_| | | |___| |_| | (__|   < \n");
  printf("\t\t\t  \\_____|\\___/ \\___/ \\__,_| "
         "|______\\__,_|\\___|_|\\_\\\n");
  printf("\t\t\t                                                   \n");
  printf("\t\t\t                                                   \n");

  breakln(0);
}

void printWelcome() {
  printHeader();

  // create sample maze and print in size 4 x 20
  printSampleMaze(4, 20);

  welcomeTitle();

  // create sample maze and print in size 4 x 20
  printSampleMaze(4, 20);

  breakln(1);
  printFooter();
}



void printMainMenu() {
  mainMenuTitle();
  printf("\n\n\t☆꧁༒☬  List of commands ☬༒꧂☆\n\n");
  printf("\t\t ▒ 1 : Create new map\n");
  printf("\t\t ▒ 2 : Edit map\n");
  printf("\t\t ▒ 3 : Display map\n");
  printf("\t\t ▒ 4 : Export map\n");
  printf("\t\t ▒ 0 : Exit program\n");
  printf("\n\n");
  printFooter();
}

void printCreateMap(MAP_T **map, int *width, int *length) {

  int cmd, stage, oldWidth, oldLength, con = 1;
  bool isExisted;
  stage = 0;

  while (true) {
    createMapTitle();
    if (stage == 0) {
      isExisted = false;
      printf("\t☆꧁༒☬ Do you want to create new map? ☬༒꧂☆\n\n");
      printf("\t\t▒ ◉ Enter 1 to continue \n");
      printf("\t\t▒  \n");
      printf("\t\t▒ ◉ Enter 0 to return to the main menu \n\n");
      printf("\t⚠️  Caution: the pervious map will be replaced!  \n\n");

      printFooter();

      intInput(&cmd);
      if (cmd != 1) { // return to main menu
        break;
      }
    }

    if (stage == 1) {
      printf("\t\t ███ Width = ???   |   ███ Length = ???  \n\n");
      breakln(2);
      printf("\n\n\n");

      printf("\t\t ▒▒▒ Instruction: Enter the width of the map");
      printf("\n\n\n\n");
      printFooter();

      // oldWidth will use in case creating new map is canceled
      oldWidth = *width;

      // map ต้องมีขนาดอย่างน้อย 2 x 2 จึงจะสร้าง path ของ maze ได้
      while (true) {
        intInput(width);
        if (*width > 1)
          break;
        else
          printf("Row must more than 1\n");
      }

    }

    else if (stage == 2) {
      printf("\t\t  ✅  Width = %d   |   ███ Length = ???  \n\n", *width);
      breakln(2);
      printf("\n\n\n");

      printf("\t\t ▒▒▒ Instruction: Enter the length of the map\n");
      printf("\n\n\n\n");
      printFooter();

      // oldLength will use in case creating new map is canceled
      oldLength = *length;

      // map ต้องมีขนาดอย่างน้อย 2 x 2 จึงจะสร้าง path ของ maze ได้
      while (true) {
        intInput(length);
        if (*length > 1)
          break;
        else
          printf("Length must more than 1\n");
      }

    }

    else if (stage == 3) {
      printf("\t\t  ✅  Width = %d   |   ✅  Length = %d  \n\n", *width, *length);
      breakln(2);
      printf("\n\n\n");

      printf("\t☆꧁༒☬ Comfirm width and length of the Map ☬༒꧂☆\n\n");
      printf("\t\t▒ ◉ Enter 1 to continue \n");
      printf("\t\t▒  \n");
      printf("\t\t▒ ◉ Enter 2 to enter width and length again \n");
      printf("\t\t▒  \n");
      printf("\t\t▒ ◉ Enter 0 to return to the main menu \n\n");
      printf("\t⚠️  Caution: the pervious map will be replaced!  \n\n");
      printFooter();

      intInput(&cmd);
      if (cmd == 2) {
        stage = 0;

      } else if (cmd != 1) { // creating new map is canceled
        // change width and length to old one
        *width = oldWidth;
        *length = oldLength;
        break;
      }
    }

    else if (stage == 4) {
      printf("\t\t  ✅  Width = %d   |   ✅  Length = %d  \n\n", *width, *length);
      breakln(2);
      printf("\n\n\n");
      printf("Result: \n\n\n");

      if (isExisted == false) {
        if (*map != NULL) { // free maze In case have old one
          free(*map);
          *map = NULL;
        }
        initMap(map, *width, *length);
        generatePath(*map, *width, *length);
        isExisted = true;
      }
      printMap(*map, *width, *length);
      // printMapIndex(map, *width, *length);

      printf("\n\n\n");

      printf("\t☆꧁༒☬ What do you want to do next? ☬༒꧂☆\n\n");
      printf("\t\t▒ ◉ Enter 1 to regenerate map \n");
      printf("\t\t▒  \n");
      printf("\t\t▒ ◉ Enter 2 to generate random special item \n");
      printf("\t\t▒  \n");
      printf("\t\t▒ ◉ Enter 3 to remove all special item \n");
      printf("\t\t▒  \n");
      printf("\t\t▒ ◉ Enter 0 to return to the main menu\n\n");

      printFooter();

      // get command
      intInput(&cmd);

      if (cmd == 1) { // regenerate map for new path at stage 4
        isExisted = false;
        stage = 3;

      } else if (cmd == 2) { // random item
        randomItem(*map, *width, *length);
        stage = 3;

      } else if (cmd == 3) { // remove all item
        removeAllItem(*map, *width, *length);
        stage = 3;

      } else { // return to main menu
        break;
      }
    }

    stage++;
  }
}

void printExportMap(MAP_T *map, int width, int length) {
  int cmd;

  exportMapTitle();

  intInput(&cmd);

  // Export
  if (cmd == 1) {
    printf("💾 Enter name for the file (FILENAME.txt): ");
    int MAX = 256;
    char str[MAX];
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0;

    exportMap(map, width, length, str);
    return;
  }
}

void printEditMap(MAP_T *map, int *width, int *length) {
  int cmd, stage, check = 0;
  stage = 0;
  while (true) {

    editMapTitle();

    if (stage == 0) {
      printf("\t☆꧁༒☬ Select the part you would like to edit ☬༒꧂☆\n\n");
      printf("\t\t▒ ◉ Enter 1 Special Item \n");
      printf("\t\t▒  \n");
      printf("\t\t▒ ◉ Enter 2 Walls \n");
      printf("\t\t▒  \n");
      printf("\t\t▒ ◉ Enter 0 to return to the main menu \n\n");
      printf("\n\n\n\n");
      printFooter();
      intInput(&cmd);
      if (cmd == 1) {
        stage = 1;
      } else if (cmd == 2) {
        stage = 2;
      } else { // return to main menu
        break;
      }
    } else if (stage == 1) { // edit special item
      printMapIndex(map, *width, *length);
      printf("\n\n\n");
      printf("\t☆꧁༒☬ Select Row Column and Item to Replace ☬༒꧂☆\n\n");
      printf("\t\t ░ 0 ►► Empty ░ 1 ►► 🍎 ░ 2 ►► 🍌 ░ 3 ►► 🍊 ░ 4 ►► 🍒 ░ \n\n");
      printf("\t\t ░ 5 ►► remove all special item ░ Enter ►► Return to main "
             "menu \n\n");
      printf("\t\t ░ Ex. 10 5 1 ►► at 10th row, 5th column add 🍎 \n\n");
      printFooter();

      // call function for get input and place item
      check = placeItem(map, *width, *length, 1);

      if (check == 0) // return to main menu
        break;
      else if (check == 5) // call removeAllItem function
        removeAllItem(map, *width, *length);
    }

    else if (stage == 2) { // edit walls
      printMapIndex(map, *width, *length);
      printf("\t☆꧁༒☬ Select Row Column and Wall to Edit ☬༒꧂☆\n\n");
      printf("\t\t ░ 1 ►► up wall ░ 2 ►► down wall ░ 3 ►► left wall ░ 4 ►► "
             "right wall ░ \n\n");
      printf("\t\t ░ 0 ►► space ░ 1 ►► wall ░ \n\n");
      printf("\t\t ░ Enter ►► Return to main "
             "menu \n\n");
      printf("\t\t ░ Ex. 10 5 4 0 ►► at 10th row, 5th column change right wall "
             "to space \n\n");

      // call function for get input and edit item
      check = editWall(map, *width, *length);

      if (check == 0) // return to main menu
        break;
    }
  }
}

void printDisplayMap(MAP_T *map, int *width, int *length) {
  int cmd = 0;
  while (true) {
    // Display map
    displayMapTitle();
    printf("\t☆꧁༒☬ Comfirm width and length of the Map ☬༒꧂☆\n\n");
    printf("\t\t▒ ◉ Enter 1 to typical display \n");
    printf("\t\t▒  \n");
    printf("\t\t▒ ◉ Enter 2 to display with indexing \n");
    printf("\t\t▒  \n");
    printf("\t\t▒ ◉ Enter 0 to return to the main menu \n\n");
    printf("\n\n\n\n");

    if (cmd == 1) {
      printMap(map, *width, *length);
    }

    else if (cmd == 2) {
      printMapIndex(map, *width, *length);
    }

    printFooter();
    intInput(&cmd);

    if (cmd != 1 && cmd != 2) { // return to main menu
      break;
    }
  }
}

int printExit() {
  int cmd, stage;
  stage = 0;
  while (true) {
    clearScreen();
    printHeader();
    if (stage == 0) {
      exitTitle();
      printf("\n\n\n\t☆꧁༒☬ Would you like to exit the program? ☬༒꧂☆\n\n");
      printf("\t⚠️  Caution: You may lose your map data if you haven't "
             "exported the map  \n\n");
      printf("\t\t▒ ◉ Enter 1 to exit the program \n");
      printf("\t\t▒  \n");
      printf("\t\t▒ ◉ Enter 0 to return to the main menu\n");
      printf("\t\t▒  \n\n\n");
      printFooter();
    } else if (stage == 1) {
      goodluckTitle();
      printf("\n\n\n");
      printFooter();
      return 0;
    }

    intInput(&cmd);
    if (cmd == 1) {
      stage++;
    }

    else {
      return 1;
    }
  }
}
