#include "ttt.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

  if (argc == 1) {
    exit(1);
  }

  init_boards();
  init_board(START_BOARD);
  join_graph(START_BOARD);
  compute_score();

  for (int i = 1; i <= argc; i++) {
    print_node(htable[i]);
  }

  return 0;
}
