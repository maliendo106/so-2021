#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 1

int main() {

  int fd;
  fd = open("hola.txt", O_WRONLY);

  write(fd, "0", sizeof(char));

  close(fd);

return 0;
}