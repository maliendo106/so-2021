#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 1

// funcion principal main
int main(int argc,char *argv[]) {

  int fd;
  char buffer[MAX];

  if ((fd = open("hola.txt", O_RDONLY)) < 0) {

    printf("no se ha encontrado el archivo\n");
    exit(1);

  }else {

    read(fd, buffer, MAX);

    while (strcmp(buffer, "1") == 0) {
        printf("Se ha encontrado un 1\n");
        fflush(stdout);
        read(fd, buffer, MAX);
        sleep(1);
    }

  close(fd);
  printf("Se ha encontrado un 0\n");

  }

  return 0;
}