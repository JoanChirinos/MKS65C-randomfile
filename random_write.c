#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int random_int() {
  int* ret_p = calloc(sizeof(int), 1);
  int x = open("/dev/random", O_RDONLY);
  read(x, ret_p, sizeof(int));
  close(x);
  int ret = *ret_p;
  free(ret_p);
  return ret;
}

int main() {
  int* int_array = calloc(sizeof(int), 10);
  int i;
  printf("Generating random numbers...\n\n");
  for (i = 0; i < 10; i++) {
    int rand_int = random_int();
    printf("random %d: %d\n", i, rand_int);
    *(int_array + i) = rand_int;
  }

  int write_to_file = open("writing_here.txt", O_WRONLY);
  write(write_to_file, int_array, sizeof(int) * 10);
  printf("\nWriting to file...\n\n");
  close(write_to_file);

  int* stuff_in_file = calloc(sizeof(int), 10);
  int read_from = open("writing_here.txt", O_RDONLY);
  read(read_from, stuff_in_file, sizeof(int) * 10);
  printf("Reading from file...\n\n");
  close(read_from);

  printf("Verify they're the same...\n\n");
  for (i = 0; i < 10; i++) {
    printf("random %d: %d\n", i, *(stuff_in_file + i));
  }
  printf("\n");
  free(int_array);
  free(stuff_in_file);
}
