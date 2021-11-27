#include "config.h"
#include <stdio.h>
#include <string.h>
#define MAX_LEN 128

extern DATA_ACCESS data_access;

int cmp(char *a, char *b) {
  int c = strlen(b);
  for (int i = 0; i < c; i++) {
    if (a[i] != b[i]) {
      return 1;
    }
  }
  return 0;
}

void print_image() {

  char *filename = "img/art.txt";
  FILE *fptr = NULL;

  if ((fptr = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "error opening %s\n", filename);
  }

  char read_string[MAX_LEN];

  while (fgets(read_string, sizeof(read_string), fptr) != NULL)
    printf("%s", read_string);
  fclose(fptr);
}

void Mode() {
  char num, str[200], *user, *passd, *colon;
  FILE *fptr;
  char buf[200];

  int key = 0;
  int i;

  fptr = fopen("account/zero.txt", "r+");

  if (fptr == NULL) {
    printf("Error!");
  }
  while (fgets(str, sizeof(str), fptr)) {

    char *b = data_access.user;
    char *a = str;
    if (cmp(a, b) == 0) {

      data_access.mode_set = 1;
      break;
    } else {
      data_access.mode_set = 0;
    }
  }
}
