#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>

int main (int argc, char *argv[]){

    DIR *direc;
    struct dirent *direcp;
    
    if (argc == 1){
    printf("--->No paso directorio...\n\n");
    exit(1);
    }

    direc = opendir(argv[1]); //null en caso de error

    if (direc == NULL){
        printf("--->No se pudo abrir directorio...\n\n");
        exit(1);
    }
    
    printf("Tipo\tTamano(bytes)\t\tNombre\n");
    while ((direcp = readdir(direc)) != NULL){
        printf("%d\t%d\t%d\t%s\n", direcp->d_ino, direcp->d_off, direcp->d_reclen, direcp->d_name);
    }

    

    closedir(direc);
    return 0;

}