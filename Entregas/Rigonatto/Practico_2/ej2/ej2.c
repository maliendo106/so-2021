/*
2) Genere un archivo que contenga un listado extendido del contenido del directorio raiz (/). Escriba un programa que lea dicho archivo
y muestre su contenido en pantalla. Para ello use las llamadas al sistema open(), close() y read().

Tip: Para crear el archivo basta con hacer un 'ls -l' y redirigir su salida. 
Recuerde que cada proceso 'nace' con entrada estandar, salida estandar y error estandar.
'<' redirige entrada std
'>' redirige salida std, igual que '1>'
'2>' redirige error std

Tip: Para su programa debe:
a) abrir el archivo para lectura utilizando open()
b) recorrer el archivo haciendo read() y observando su
valor de retorno, el mismo nos indica cuando hemos llegado 
al final del archivo.
c) cerrar el archivo

Consejo: Siempre verifique valores de retorno de funciones (ver man page)
ej.
  fd = open( "test.txt", O_RDONLY ); // verificar el valor de fd
  n = read( fd, buff, max ); // verificar n, su valor es importante 
*/

#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h>


int main(void){

  char text[1];
  int fd, n;

  system("ls -l / > listado.txt"); // guardo el resultado de [ls -l] en "listado.txt" 
                                   // En caso que "listado.txt" no exista, se crea. 

  fd = open( "listado.txt", O_RDONLY ); // abro el archivo "listado.txt" en modo lectura

  /*
    On success, open(), openat(), and creat() return the new file
    descriptor (a nonnegative integer).  On error, -1 is returned and
    errno is set to indicate the error.
  */

  if (fd < 0) { 
    printf("Error al abrir el archivo de texto.\n"); // notifica el error.
    return 1; // termina el programa
  }

  do{
    n = read(fd, text, 1); // leo un byte del archivo, lo almaceno en [text] y muevo el puntero al siguiente byte 
    printf("%s", text); // imprimo el caracter leido
    fflush(stdout);
  }while(n != 0); // si n == 0 -> se leyo todo el archivo.

  close(fd); //cierro el archivo.
  return 0;  // termina el proigrama
}