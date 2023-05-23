/*
6) Escriba un programa que reciba por linea de comando el nombre de
un archivo y lo copie en un archivo con la extension ".bak". Use
open(), close(), read() y write().

Tip: Usará open() dos veces, una el leer el archivo origen y otra
al crear y escribir en el archivo de destino. Para el segundo caso
puede utilizar
  fd = open("test.txt", O_RDWR|O_CREAT, 0644);
o lo que es lo mismo
  fd = open("test.txt", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH );
vea la página de manual 'man 2 open'

Tip: El programa en si tiene tres partes
  - abrir los archivos
  - recorrer (loop) el origen y escribir en destino
  - cerrar los archivos
el loop termina analizando el valor retornado por read()
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *nombre = argv[1];
  char *copia = strdup(argv[1]);
  int aux;
  copia = strcat(copia, ".bak");
  char buff[1];
  int fd_original = open(nombre, O_RDONLY);

  if (fd_original < 0) {
    printf(" El archivo no existe!!!\n");
    return 0;
  }

  int fd_copia = open(copia, O_WRONLY | O_CREAT, 0644);
  
  while ( aux = read(fd_original, buff, sizeof(char))) {
    write(fd_copia, buff, sizeof(char));
  }

  close(fd_original);
  close(fd_copia);

  return 0;
}