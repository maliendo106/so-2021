#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int pid;
  pid = fork();
  if (pid == 0) {
    /* hijo */

    // PID del fork (hijo)
    printf("Hijo - pid: %d\n", pid);
    fflush(stdout);

    // PID del proceso (hijo)
    printf("Hijo - getpid: %d\n", getpid());
    fflush(stdout);

    // PID del proceso padre
    printf("Hijo - getppid: %d\n", getppid());
    fflush(stdout);
  } else {
    /* padre */

    // PID del fork (hijo)
    printf("Padre - Hijo pid: %d\n", pid);
    fflush(stdout);

    // PID del proceso (padre)
    printf("Padre - getpid: %d\n", getpid());
    fflush(stdout);

    // PID del proceso padre (probablemente bash)
    printf("Padre - getppid: %d\n", getppid());
    fflush(stdout);
  }
  return 0;
}
