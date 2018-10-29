#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

  int* int_array = calloc(sizeof(int), 10);
  int x = open("/dev/random", O_RDONLY);
  read(x, int_array, sizeof(int) * 10);
  close(x);

  int write_to_file = open("writing_here.txt", O_WRONLY);
  write(write_to_file, int_array, sizeof(int) * 10);
  close(write_to_file);

  int* stuff_in_file = calloc(sizeof(int), 10);
  int read_from = open("writing_here.txt", O_RDONLY);
  read(read_from, stuff_in_file, sizeof(int) * 10);
  close(read_from);

  printf("wrote: ");
  int ctr;
  for (ctr = 0; ctr < 10; ctr++) {
    printf("%d | ", *(int_array + ctr));
  }
  printf("\n\nread: ");
  for (ctr = 0; ctr < 10; ctr++) {
    printf("%d | ", *(stuff_in_file + ctr));
  }
  printf("\n");
}
