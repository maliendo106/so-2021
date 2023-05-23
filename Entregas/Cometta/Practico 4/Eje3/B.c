#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX 1024

int main(){
  
  // Hijo 2
  char buff[MAX];
  int fd = open("Pipe", O_RDONLY);

  if (fd != -1) {
    
    read(fd, buff, MAX);
    
  } 

  printf("Chat: %s\n\n", buff);
  return 0;
}
