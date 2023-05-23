/*
3) Hacer que un proceso finalice a otro
Variante de los anteriores, pero esta vez tenmos dos procesos, A y B
A funciona como en 2
B espera un cierto tiempo y luego escribe el archivo esperado por A
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 1

int main() {

  int file;
  char buffer [MAX];

  if ((file = open("texto", O_RDONLY)) < 0) {

    printf("Archivo inexistente o no encontrado.\n");
    exit(1);

  }else {

    read(file,buffer,MAX);

    while (strcmp(buffer, "1") == 0) {
        printf("Hay 1, no se puede terminar\n");
        fflush(stdout);
        lseek(file, 0, SEEK_SET);
        read(file, buffer, MAX);
        sleep(1);
    }

  close(file);

  printf("Se encontro un 0. Terminando, \n");

  }
  return 0;
}