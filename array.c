#include "array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Performance * newPerformance() {

  struct Performance * newP;
  newP = malloc(sizeof(struct Performance *));

  if (newP == NULL) {
    printf("Error: newPerformance\n");
    exit(1);
  }

  newP->reads = 0;
  newP->writes = 0;
  newP->mallocs = 0;
  newP->frees = 0;

  return newP;

}

struct Array * newArray(struct Performance * performance, unsigned int width, unsigned int capacity) {

  struct Array * newArray;
  newArray = malloc(sizeof(struct Array));

  if (newArray == NULL) {
    printf("Error: newArray\n");
    exit(1);
  }

  newArray->width = width;
  newArray->capacity = capacity;
  newArray->nel = 0;

  newArray->data = malloc(width * capacity);

  performance->mallocs++;

  return newArray;

}

void readItem(struct Performance * performance, struct Array * array, unsigned int index, void * dest) {

  if (index >= array->nel) {
    printf("Error: readItem\n");
    exit(1);
  }
  else {
    char * src = (char *)array->data + (index * array->width);
    memcpy(dest, src, array->width);
    performance->reads++;
  }

}

void writeItem(struct Performance * performance, struct Array * array, unsigned int index, void * src) {

  if ((index > array->nel) || (index >= array->capacity)) {
    printf("Error: writeItem\n");
    exit(1);
  }
  else {
    char * dest = (char *)array->data + (index * array->width);
    memcpy(dest, src, array->width);

    if (index == array->nel) {
      array->nel++;
    }

    performance->writes++;

  }

}

void contract(struct Performance * performance, struct Array * array) {

  if (array->nel == 0) {
    printf("Error: contract\n");
    exit(1);
  }
  else {
    array->nel--;
  }

}

void freeArray(struct Performance * performance, struct Array * array) {

  free(array->data);
  free(array);
  performance->frees++;

}

void appendItem(struct Performance * performance, struct Array * array, void * src) {

  writeItem(performance, array, array->nel, src);

}

void insertItem(struct Performance * performance, struct Array * array, unsigned int index, void * src) {

  void * dest = malloc(array->width);

  for (int i = array->nel-1; i >= index; i--) {
    readItem(performance, array, i, dest);
    writeItem(performance, array, i + 1, dest);
  }

  writeItem(performance, array, index, src);

}

void prependItem(struct Performance * performance, struct Array * array, void * src) {

  insertItem(performance, array, 0, src);

}

void deleteItem(struct Performance * performance, struct Array * array, unsigned int index) {

  void * dest = malloc(array->width);

  for (int i = index + 1; i < array->nel; i++) {
    readItem(performance, array, i, dest);
    writeItem(performance, array, i - 1, dest);
  }

  contract(performance, array);

}

int findItem(struct Performance * performance, struct Array * array, int (*compar)(const void *, const void *), void * target) {

  void * dest = malloc(array->width);

  for (int i = 0; i < array->nel; i++) {

    readItem(performance, array, i, dest);
    char * str1 = (char *)array->data + (i *  array->width);
    int result = compar((char *)target, str1);

    if (result == 0) {
      return i;
    }

  }

  return -1;

}

int searchItem(struct Performance * performance, struct Array * array, int (*compar)(const void *, const void *), void * target) {

  int start = 0;
  int middle = (int)floor(array->nel / 2);
  int end = array->nel - 1;
  void * dest = malloc(array->width);

  while (start < end) {

    readItem(performance, array, middle, dest);
    int result = compar((char *)target, dest);

    if (result == 0) {
      return middle;
    }
    else if (result < 0) {
      end = middle - 1;
      middle = (int)floor(end / 2);
    }
    else if (result > 0) {
      start = middle + 1;
      middle = start + (int)floor((end - start) / 2);
    }
    else {
      return -1;
    }

  }

  return -1;

}
