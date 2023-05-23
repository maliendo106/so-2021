#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    
    int fd1;
    char *buffer[1024];

    if (argc == 1){
        printf("---> no se paso el archivo");
        exit(1);
    }
 
        
    fd1 = open(argv[1], O_RDONLY);
    
    if (fd1 == -1){
        printf("No se pudo leer el archivo...");
        exit(1);
    }

    while (read(fd1, &buffer, 1) > 0){
        printf("%s", buffer);
    }
    
    return 0;

}

