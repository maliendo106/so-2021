#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX 2048

int main() {
  int pid;
  int p[2];
  pipe(p);

  if ((pid = fork()) == 0) {
    // Hijo 1
    time_t curtime;
    char *msg;

    time(&curtime);
    msg = ctime(&curtime);

    write(p[1], msg, strlen(msg));
  } else {
    if ((pid = fork()) == 0) {
      // Hijo 2
      char buff[MAX];
      read(p[0], buff, MAX);
      printf("Lectura: %s", buff);
    } else {
      // Padre
      int status1, status2;
      wait(&status1);
      printf("Status1: %d\n", status1);
      wait(&status2);
      printf("Status2: %d\n", status1);
    }
  }
  return 0;
}
