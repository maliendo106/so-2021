#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX 2048

int main() {
  // Hijo 1
  int fd;
  time_t curtime;
  char *msg;

  fd = open("fpipe", O_WRONLY);
  if (fd != -1) {
    time(&curtime);
    msg = ctime(&curtime);
    write(fd, msg, strlen(msg));
  }

  return 0;
}