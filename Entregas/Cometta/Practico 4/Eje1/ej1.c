#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/file.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX 2048

int main() {
  int pid;

  remove("file");
  close(creat("file", 0644));

  //Hijo 1
  if ((pid = fork()) == 0) {
    
    int fdb; //ver ese rflock
    time_t curtime;
    char *msj;
    
    fdb = open("file", O_WRONLY); //le doy permiso de escritura
    
    time(&curtime);
    msj = ctime(&curtime);
    write(fdb, msj, strlen(msj));
    flock(fdb, LOCK_UN);
    close(fdb);
  
  } else {
    
    //Hijo 2
    if ((pid = fork()) == 0) {
          
      int fdb; 
      char buff[MAX];
      char *tactual_str;
      time_t tactual;

      fdb = open("file", O_RDONLY); //le doy permiso de lectura
      while (1) {

        read(fdb, buff, MAX);

        if (strcmp(buff, "") == 0) {
          flock(fdb, LOCK_UN);
          continue;
        }

        printf("Lectura: %s\n", buff);

        close(fdb);
        break;
      }
    } else {
      int estado1, estado2;
      wait(&estado1);
      printf("Estado 1: %d\n", estado1);
      wait(&estado2);
      printf("Estado 2: %d\n", estado2);
    }
  }
  return 0;
}
