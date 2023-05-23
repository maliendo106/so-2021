#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdlib.h>

int main() {
  int fd;

  while((fd = open("file.txt", O_RDONLY)) < 0) {
    printf("no se encuentra el archivo\n");
    sleep(3);
  }

  close(fd);
  printf("archivo encontrado, terminando programa\n");

  return 0;
}
