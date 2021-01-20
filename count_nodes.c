#include "ttt.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char * argv[]) {

  int count = 0;

  init_boards();
  init_board(START_BOARD);
  join_graph(START_BOARD);

  for (int i = 0; i < HSIZE; i++) { //Loop through table
    if (htable[i].init == 1) {
      count++;
    }
  }

  printf("counter = %d\n", count);

  return 0;

}
