#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Performance * newPerformance() {

  struct Performance * newP;
  newP = malloc(sizeof(struct Performance));

  if (newP == NULL) {
    printf("Error: newPerformance\n");
    exit(1);
  }

  //Initialize performance structure

  newP->reads = 0;
  newP->writes = 0;
  newP->mallocs = 0;
  newP->frees = 0;

  return newP;

}

void attachNode(struct Performance * performance, struct Node ** node_ptr, void * src, unsigned int width) {

  //Make Space

  *node_ptr = (struct Node *)malloc(sizeof(struct Node));

  if (*node_ptr == NULL) {
    fprintf(stderr, "Error: attachNode: Malloc Failed\n");
    exit(1);
  }

  (*node_ptr)->data = malloc(width);

  if ((*node_ptr)->data == NULL) {
    fprintf(stderr, "Error: attachNode: Malloc Failed\n");
    exit(1);
  }

  //Copy Bytes

  memcpy((*node_ptr)->data, src, width);

  //Attach New Node

  (*node_ptr)->lt = NULL;
  (*node_ptr)->gte = NULL;

  performance->mallocs++;
  performance->writes++;

}

int comparNode(struct Performance * performance, struct Node ** node_ptr, int(*compar)(const void *, const void *), void * target) {
  //Compare Data for left or right
  int result = (*compar)(target, (*node_ptr)->data);
  performance->reads++;
  return result;
}

struct Node ** next(struct Performance * performance, struct Node ** node_ptr, int direction) {

  //Checks if the tree is empty

  if (isEmpty(performance, node_ptr)) {
    fprintf(stderr, "Error: next: Tree Empty\n");
    exit(1);
  }

  //Goes to next node

  else {
    performance->reads++;
    if (direction < 0) {
      return &((*node_ptr)->lt);
    }
    else {
      return &((*node_ptr)->gte);
    }
  }

}

void readNode(struct Performance * performance, struct Node ** node_ptr, void * dest, unsigned int width) {

  //Checks if tree is empty

  if (isEmpty(performance, node_ptr)) {
    fprintf(stderr, "Error: readNode: Tree Empty\n");
    exit(1);
  }

  //Copys from tree into destination

  else {
    memcpy((*node_ptr)->data, dest, width);
  }

  performance->reads++;

}

void detachNode(struct Performance * performance, struct Node ** node_ptr) {

  //Checks if tree is empty

  if (isEmpty(performance, node_ptr)) {
    fprintf(stderr, "Error: detachNode: Tree Empty\n");
    exit(1);
  }

  //frees node

  free((*node_ptr)->data);
  free(*node_ptr);
  *node_ptr = NULL;

  performance->frees++;

}

int isEmpty(struct Performance * performance, struct Node ** node_ptr) {
  if (*node_ptr == NULL) {
    return 1;
  }
  else {
    return 0;
  }
}

void addItem(struct Performance * performance, struct Node ** node_ptr, int(*compar)(const void *, const void *), void * src, unsigned int width) {

  struct Node ** current = node_ptr;

  if ((*node_ptr) == NULL) {
    attachNode(performance, node_ptr, src, width);
    return;
  }

  //Checks nodes in the tree

  while (*current != NULL) {
    int result = comparNode(performance, current, compar, src);
    current = next(performance, current, result);
  }

  //Adds node if node is empty

  attachNode(performance, current, src, width);

}

void freeTree(struct Performance * performance, struct Node ** node_ptr) {
  if (*node_ptr) {
    freeTree(performance, next(performance, node_ptr, -1));
    freeTree(performance, next(performance, node_ptr, 1));
    detachNode(performance, node_ptr);
  }
}

int searchItem(struct Performance * performance, struct Node ** node_ptr, int (*compar)(const void *, const void *), void * target, unsigned int width) {

  //Checks if empty

  if (*node_ptr) {
    if (comparNode(performance, &(*node_ptr), compar, target) == 0) {
      //if found
      return 1;
    }
    else {
      //Otherwises keep looking
      if (comparNode(performance, &(*node_ptr), compar, target) < 0) {
        return searchItem(performance, &((*node_ptr)->lt), compar, target, width);
      }
      else {
        return searchItem(performance, &((*node_ptr)->gte), compar, target, width);
      }
    }
  }
  else {
    //not found
    return 0;
  }

}
