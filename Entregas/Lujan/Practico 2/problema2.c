/*

2) Genere un archivo que contenga un listado extendido del contenido
del directorio raiz (/). Escriba un programa que lea dicho archivo
y muestre su contenido en pantalla. Para ello use las llamadas
al sistema open(), close() y read().

Tip: Para crear el archivo basta con hacer un 'ls -l' y redirigir
su salida. 
Recuerde que cada proceso 'nace' con entrada estandar, salida estandar
y error estandar.
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
  fd = open( "test.txt", O_RDONLY ); /* verificar el valor de fd 
  n = read( fd, buff, max );  verificar n, su valor es importante

*/

  
#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){

  char text[1];
  int arch, n;
  system("ls -l / > listado.txt"); 

//Abro el archivo
  arch = open( "archivo.txt", O_RDONLY );

 // lectura de archivo
  do{
    printf("%s", text); 
  }while(n = read(arch, text, 1));
  
 //cierro el archivo.
  close(arch);
  return 0; 

}