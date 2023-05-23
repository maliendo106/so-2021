#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#define MAX 1400

int main()
{
      char buffer[MAX];
      if(open("pipeNamed", O_RDONLY) != -1){
        read(pipe[0], buffer, MAX);
        printf("Contenido: %s", buffer);
      }
      
  return 0;
}
