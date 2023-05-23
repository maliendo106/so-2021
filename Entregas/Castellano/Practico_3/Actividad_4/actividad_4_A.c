#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX 100

int main(int argc,char *argv[]) {

  int file;
  char buffer [MAX];
  char msg[] = "Hola, como estas?";

  
    remove("comunicacion.txt");
    file = open("comunicacion.txt", O_RDWR | O_CREAT, 0664);
    write(file, msg, strlen(msg) + 1);
    lseek(file, 0, SEEK_SET);

    printf("Proceso A: %s\n", msg);

    while (read(file, buffer, MAX)) {
        if (strcmp(buffer, msg) != 0)
            break;
        lseek(file, 0, SEEK_SET);
        printf("...\n");
        sleep(3);
    }

    read(file, buffer, MAX);

    printf("Proceso B: %s\n", buffer);

    close(file);
  
  return 0;

}
