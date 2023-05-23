#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main( int argc, char *argv[]){

    char text[1];
    int original, copia;
   
    ssize_t es, le;

    original = open(argv[1], O_RDONLY);
    copia = open("copia.bak", O_RDWR|O_CREAT, 0644);

    do{
        
        le = read(original, text, 1); // leo un byte del archivo, lo almaceno en text y muevo el puntero al siguiente byte 
        es = write(copia, text, 1);
        fflush(stdout);
    
    }while(le != 0); // si n == 0 se leyo todo el archivo.
    
    close(copia);
    close(original);

}