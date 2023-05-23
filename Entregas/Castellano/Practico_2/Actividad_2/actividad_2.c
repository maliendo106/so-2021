#include <stdio.h>
#include <fcntl.h>

int main() {
    
    char text[1];
    int numbytes;

    system("ls -l / > lista.txt");

    int file=open("lista.txt", O_RDONLY);

    if (file < 0) { 
        printf("Error al abrir el archivo de texto.\n");
        return 1;
    }

    do{
        numbytes = read(file, text, 1);
        printf("%s",text);
        fflush(stdout);
    } while(numbytes != 0);

    close(file);

    return 0; 
}