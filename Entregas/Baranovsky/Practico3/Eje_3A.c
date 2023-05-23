#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define Max 1400

int main(int argc,char *argv[]) {

  int file;
  char buffer [Max];

  if ((file = open("File.txt", O_RDONLY)) < 0) {

    printf("El archivo todavia no existe.\n");

    exit(1);

  }else {

    read(file,buffer,1);

    while (strcmp(buffer, "1") == 0) {
        printf("Hay 1, no se puede terminar\n");
        fflush(stdout);
        lseek(file, 0, SEEK_SET);
        read(file, buffer, 1);
        sleep(10);
    }

  close(file);

  printf("Encontrado un 0\n");

  }
  return 0;

}