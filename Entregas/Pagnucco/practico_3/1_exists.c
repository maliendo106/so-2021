#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int fd;
  while ((fd = open("test", O_RDONLY)) < 0) {
    printf("No se encontro el arvhivo.");
    sleep(1);
  }

  close(fd);

  printf("Archivo encontrado!");
  return 0;
}