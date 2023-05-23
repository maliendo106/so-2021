#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define MAX 1400

int main(int argc,char *argv[]) {

  int file;
  char buffer [MAX];
  char mensaje[] = "Como estas?";

  
    remove("File.txt");
    file = open("File.txt", O_RDWR | O_CREAT, 0664);
    write(file, mensaje, strlen(mensaje) + 1);
    lseek(file, 0, SEEK_SET);

    while (read(file, buffer, MAX)) {
        if (strcmp(buffer, mensaje) != 0)
            break;
        lseek(file, 0, SEEK_SET);
        printf("Todavia no hay respuesta!\n");
        sleep(5);
    }


    close(file);
    printf("Respuesta recibida\n");
  

  
  return 0;

}