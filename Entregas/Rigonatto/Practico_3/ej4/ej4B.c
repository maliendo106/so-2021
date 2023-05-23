#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 10


int main() {
  int file;
  char buff[MAX];
  char msg[] = "Hola rey!";


  if (access("chat.txt", F_OK) != 0){
      sleep(3);
  }

  file = open("chat.txt", O_RDWR);
  read(file, &buff, MAX);
  lseek(file, 0, SEEK_SET);

  if (strcmp(buff, msg) != 0){
      write(file, msg, strlen(msg) + 1);
  }
    

  printf("Mensaje cambiado!\n");

  close(file);

  return 0;
}