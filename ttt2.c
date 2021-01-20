#include "ttt.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void init_boards() {
  for (int i = 0; i < HSIZE; i++) { //Loop through table
    htable[i].init = 0; //Initialize
  }
}

int depth(Board board) {

  int length = strlen(board);
  int count = 0;

  for (int i = 0; i < length; i++) { //Loop through board string
    if ((board[i] == 'X') || (board[i] == 'x') || (board[i] == 'O') || (board[i] == 'o')) {
      //if there is an X or O add to count
      count++;
    }
  }

  return count;

}

char winner(Board board) {

  for (int i = 0; i < 8; i++) {

    if (((board[pos2idx[WINS[i][0]]]) == 'X') && ((board[pos2idx[WINS[i][1]]]) == 'X') && ((board[pos2idx[WINS[i][2]]]) == 'X')) {
      return 'X';
    }
    else if (((board[pos2idx[WINS[i][0]]]) == 'O') && ((board[pos2idx[WINS[i][1]]]) == 'O') && ((board[pos2idx[WINS[i][2]]]) == 'O')) {
      return 'O';
    }

  }

  if (depth(board) == 9) {
    //Tie
    return '-';
  }
  else {
    //Game Not Over
    return '?';
  }

}

char turn(Board board) {

  if ((depth(board) == 9) || (winner(board) == 'X') || (winner(board) == 'O')) {
    //Game Over
    return '-';
  }
  else if ((depth(board) % 2) == 0) {
    //X's Turn
    return 'X';
  }
  else if ((depth(board) % 2) == 1) {
    //O's Turn
    return 'O';
  }
  else {
    return '-';
  }

}

void init_board(Board board) {

  int i = board_hash(board);

  htable[i].init = 1;
  htable[i].turn = turn(board);
  htable[i].depth = depth(board);
  strcpy(htable[i].board, board);
  htable[i].winner = winner(board);

}

void join_graph(Board board) {

  for (int i = 0; i < 9; i++) {

    if ((board[pos2idx[i]] == 'X') || (board[pos2idx[i]] == 'O')) {
      //Occupied
      int index = board_hash(board);
      htable[index].move[i] = -1;
    }
    else {

      Board boardCopy;
      strcpy(boardCopy, board); //Copy board

      boardCopy[pos2idx[i]] = turn(board); //Place marker on board in spot

      int index = board_hash(boardCopy);
      int oldIndex = board_hash(board);
      htable[oldIndex].move[i] = index; //Place hash value of new board into move array

      if (htable[index].init == 0) {
        init_board(boardCopy);
        join_graph(boardCopy);
      }

    }

  }

}

void compute_score() {

  for (int i = 0; i < HSIZE; i++) { //Loop through htable

    if ((htable[i].init) == 1) { //check if valid

      if ((htable[i].winner) == 'X') { //X wins
        htable[i].score = 1;
      }
      else if ((htable[i].winner) == 'O') { //O wins
        htable[i].score = -1;
      }
      else if ((htable[i].winner) == '-') { //Tie
        htable[i].score = 0;
      }
      else if ((htable[i].turn) == 'X') { //X's Turn

        int index = 0;
        int j = 0;
        int large = htable[i].move[0];

        for (j = 1; j < 9; j++) {
          if (large < (htable[i].move[j])) {
            large = htable[i].move[j];
            index = j;
          }
        }

        htable[i].score = index;
//        htable[i].score = htable[large].score;

      }

      else if ((htable[i].turn) == 'O') { //O's Turn

        int index = 0;
        int j = 0;
        int small = htable[i].move[0];

        for (j = 1; j < 9; j++) {
          if (small > (htable[i].move[j])) {
            small = htable[i].move[j];
            index = j;
          }
        }

        htable[i].score = index;
//        htable[i].score = htable[small].score;

      }

    }

  }

}

int best_move(int board) {

  if ((htable[board].turn) == 'X') {

    int index = 0;
    int j = 0;
    int large = htable[board].move[0];

    for (j = 1; j < 9; j++) {
      if (large < (htable[board].move[j])) {
        index = j;
      }
    }

    return index;

  }
  else if ((htable[board].turn) == 'O') {

    int index = 0;
    int j = 0;
    int small = htable[board].move[0];

    for (j = 1; j < 9; j++) {
      if (small > (htable[board].move[j])) {
        index = j;
      }
    }

    return index;

  }

  return 0;

}
