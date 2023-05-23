#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>


int main() {
    
    struct dirent *pDirent;
    DIR *dirp;

    dirp = opendir("/");

    while( (pDirent = readdir(dirp)) != NULL ) {
        
        printf("%d \t %d \t %s\n", pDirent->d_reclen, pDirent->d_type, pDirent->d_name); // tamaño | tipo | nombre
    }

    closedir(dirp);
    return 0;
}




