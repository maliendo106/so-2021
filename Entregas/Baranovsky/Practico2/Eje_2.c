#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define Max 1400

int main() 
{
    
    int lsFile;
    char buffer [Max];

    lsFile = open("lsFile.txt", O_RDONLY);
    if(lsFile < 0){
       printf("No se pudo abrir el archivo");
       return 1;
    }
      

    while((read(lsFile,buffer,Max)) > 0)
    {
        printf("%s",buffer);
    }


    return 0;
}