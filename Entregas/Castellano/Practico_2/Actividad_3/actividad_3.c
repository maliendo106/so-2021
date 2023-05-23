#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    
    struct dirent *dirent;
    DIR *dir;

    dir = opendir("/");

    printf("Se muestra: Nombre/Tamaño/Tipo\n");
   
    while((dirent = readdir(dir)) != NULL)
    {
        printf("%s/%d/%d\n",dirent -> d_name,dirent -> d_reclen,dirent -> d_type);
    }

    closedir (dir);
    
    return 0;
}
