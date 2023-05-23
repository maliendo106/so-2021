#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    
    struct dirent *pDirent;
    DIR *sDir;

    sDir = opendir("/");

    printf("Nombre\t\tTam\tTipo\n");
   
    while((pDirent = readdir(sDir)) != NULL)
    {
        printf("%s\t\t%d\t%d\n",pDirent -> d_name,pDirent -> d_reclen,pDirent -> d_type);
    }

    closedir (sDir);
    
    return 0;
}