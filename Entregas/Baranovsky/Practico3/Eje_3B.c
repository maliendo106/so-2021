#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define Max 1400

int main(int argc,char *argv[]) {

  int file;
  char buffer [Max];
  int numbyte = 1;

  if ((file = open("File.txt", O_RDWR|O_CREAT,0644)) < 0) {

    printf("El archivo todavia no existe.\n");

    exit(1);

  }else {

        write(file,"0",sizeof(char));
    

        close(file);
  }

  return 0;

}