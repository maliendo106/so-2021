#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdlib.h>

// funcion principal main
int main() {
  int fd;

  while((fd = open("hola.txt", O_RDONLY)) < 0) {  // Abre un archivo para lectura, escritura o ambas
    printf("no se ha encontrado el archivo\n");
    sleep(1);
  }

  close(fd);
  printf("el archivo se ha encontrado\n");

  return 0;
}