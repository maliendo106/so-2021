/*
1) Finalizar un programa utilizando un archivo externo
Escriba un programa que verifique periódicamente la existencia de un archivo (elija el nombre)
Si descubre que existe entonces termina.
*/


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {

  int file;

  while ((file = open("texto.txt", O_RDONLY)) < 0) {
    printf("Archivo no encontrado.\n");
    sleep(1);
  }

  close(file);
  printf("Archivo encontrado.\n");

  return 0;

}