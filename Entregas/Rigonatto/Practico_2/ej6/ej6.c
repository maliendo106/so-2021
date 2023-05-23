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

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main( int argc, char *argv[]){

    // DIR *f_original;
    // DIR *f_copia;
    char text[1];
    int f_original, f_copia;
   
    ssize_t wo, n;

    f_original = open(argv[1], O_RDONLY);
    f_copia = open("copia.bak", O_RDWR|O_CREAT, 0644);
    //f_copia = mknod("./", mode_t mode, dev_t dev);

    do{
    n = read(f_original, text, 1); // leo un byte del archivo, lo almaceno en [text] y muevo el puntero al siguiente byte 
    wo = write(f_copia, text, 1);
    fflush(stdout);
  }while(n != 0); // si n == 0 -> se leyo todo el archivo.
  close(f_copia);
  close(f_original);
}