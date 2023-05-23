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

  remove("b-inout");
  close(creat("b-inout", 0644));

  if ((pid = fork()) == 0) {
    /* hijo 1 */
    int fdb, rflock;
    time_t curtime;
    char *msg;

    fdb = open("b-inout", O_WRONLY);
    while ((rflock = flock(fdb, LOCK_EX)) != 0) {
    }

    time(&curtime);
    msg = ctime(&curtime);

    write(fdb, msg, strlen(msg));

    flock(fdb, LOCK_UN);
    close(fdb);
  } else {
    if ((pid = fork()) == 0) {
      /* hijo 2 */
      int fdb, rflock;
      char buff[MAX];
      char *curtime_str;
      time_t curtime;

      fdb = open("b-inout", O_RDONLY);
      while (1) {
        while ((rflock = flock(fdb, LOCK_EX)) != 0) {
        }

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
      int status1, status2;
      wait(&status1);
      printf("Status1: %d\n", status1);
      wait(&status2);
      printf("Status2: %d\n", status1);
    }
  }
  return 0;
}
