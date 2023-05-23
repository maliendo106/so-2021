#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 1

int main(int argc,char *argv[]) {

  int file;
  char buffer [MAX];

  if ((file = open("file.txt", O_RDONLY)) < 0) {

    printf("Archivo no encontrado\n");

    exit(1);

  }else {

    read(file,buffer,MAX);

    while (strcmp(buffer, "1") == 0) {
        printf("Encontrado un 1\n");
        fflush(stdout);
        read(file, buffer, MAX);
        sleep(1);
    }

  close(file);

  printf("Encontrado un 0\n");

  }
  return 0;
}
