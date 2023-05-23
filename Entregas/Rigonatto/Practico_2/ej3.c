/*
3) Escriba un programa que lea el directorio raiz (/) y muestre su
contenido por pantalla. Use opendir(), readdir() y closedir().
*/
#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <stdio.h>

int main(){
    DIR *fd;
    struct dirent *direntp;

    fd = opendir("/");
    
    printf("Tipo\tTamano(bytes)\tNombre\n");
    while ((direntp = readdir(fd)) != NULL) {
        
        printf("%i\t%d\t\t%s\n", direntp->d_type, direntp->d_reclen, direntp->d_name);
    }

    closedir(fd);
    return 0;
}