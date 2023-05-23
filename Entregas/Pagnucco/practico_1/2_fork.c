#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int pid;
  pid = fork();
  if (pid == 0) {
    /* hijo */
    printf("Soy el hijo!");
    fflush(stdout);
  } else {
    /* padre */
    printf("Soy el padre!");
    fflush(stdout);
  }
  return 0;
}
