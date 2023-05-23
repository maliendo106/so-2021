#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[]) {

  int file;

  while ((file = open(argv[1], O_RDONLY)) < 0) {

    printf("El archivo todavia no existe.\n");

    sleep(1);

  }

  close(file);

  printf("El archivo existe. Adios\n");

  return 0;

}