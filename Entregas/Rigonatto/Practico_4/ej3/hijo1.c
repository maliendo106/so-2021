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

int main() {
  // Hijo 1
  int fd;
  time_t ct; // current time
  char *msg;

  fd = open("chatPipe", O_WRONLY);
  if (fd != -1) 
  {
    time(&ct);
    msg = ctime(&ct);
    write(fd, msg, strlen(msg));
  }

  return 0;
}
