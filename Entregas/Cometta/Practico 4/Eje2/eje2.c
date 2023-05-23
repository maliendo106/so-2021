#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX 1024

int main() {
  int pid;
  int p[2];
  pipe(p);

  // Hijo 1
  if ((pid = fork()) == 0) {
        
    time_t ta; //tiempo actual
    char *msj;

    time(&ta);
    msj = ctime(&ta);
    write(p[1], msj, strlen(msj));
  
  } else {

    // Hijo 2
    if ((pid = fork()) == 0) {

      char buff[MAX];
      read(p[0], buff, MAX);
      printf("Chat: %s", buff);

    } 
  }
  
  return 0;
}
