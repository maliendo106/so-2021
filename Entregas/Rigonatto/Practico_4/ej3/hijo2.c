/*
3) Idem anterior (en cuanto a funcionalidad) pero usando dos programas
diferentes en consolas diferentes y con un pipe con nombre.
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX 100

int main() 
{
  // Hijo 2
  char buff[MAX];
  int fd = open("chatPipe", O_RDONLY);

  if (fd != -1) 
  {
    read(fd, buff, MAX);
    
  } 

  printf("Chat: %s", buff);
  return 0;
}
