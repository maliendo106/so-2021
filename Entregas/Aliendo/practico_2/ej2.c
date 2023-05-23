#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>

int main(void) {

    int fd;
    char buffer[1];
    int n;

    //system("ls -l / > listado.txt");

    fd = open("listado.txt", O_RDONLY);  // Abre un archivo para lectura, escritura o ambas

    do{

        n = read(fd, buffer, 1); // Lee datos de un archivo y los coloca en un búfer 
        printf("%s", buffer); // imprimo el caracter leido
        fflush(stdout);

     }while(n != 0); // si n == 0 -> se leyo todo el archivo.

    close(fd);
    
    
    return 0;
}
