/*
3) Escriba un programa que lea el directorio raiz (/) y muestre su
contenido por pantalla. Use opendir(), readdir() y closedir().

*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    
    struct dirent *pDirent;
    DIR *sDir;
    //Abro  directorio
    sDir = opendir("/");
    printf("********************************************\n");
    printf("|Nombre\t\tTamaño\tTipo               |\n");
    printf("********************************************\n");
    //leo y imprimo los datos del directorio
    while((pDirent = readdir(sDir)) != NULL)
            printf("| %s\t\t%d\t%d                  |\n",pDirent -> d_name,pDirent -> d_reclen,pDirent -> d_type);
    printf("********************************************\n");
     //cierro  directorio.
    closedir (sDir);
    return 0;
}