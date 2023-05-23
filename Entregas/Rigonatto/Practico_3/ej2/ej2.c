/*
2) Finalizar un programa utilizando el contenido de un archivo externo
Similar al anterior, pero ahora queremos 'ver' que contiene el archivo.
Si contiene un valor '1' entonces prosigue
Si contiene el valor '0' termina
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 1

int main(int argc,char *argv[]) {

  int file;
  char buffer [MAX];

  if ((file = open("texto.txt", O_RDONLY)) < 0) {

    printf("Archivo inexistente o no encontrado.\n");
    exit(1);

  }else {

    read(file,buffer,MAX);

    while (strcmp(buffer, "1") == 0) {
        printf("Hay 1, no se puede terminar\n");
        fflush(stdout);
        read(file, buffer, MAX);
        sleep(1);
    }

  close(file);

  printf("Se encontro un 0. Terminando, \n");

  }
  return 0;
}