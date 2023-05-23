#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 1

int main() {

  int file;

  file = open("file.txt", O_WRONLY);

  write(file, "0", sizeof(char));

  close(file);

return 0;
}
