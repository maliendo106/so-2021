#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define MAX 1

int main() {
  int fd;

  fd = open("test", O_WRONLY);
  if (fd < 0) {
    close(fd);
    printf("Se creara el archivo test\n");
    fd = open("test", O_WRONLY | O_CREAT, 0664);
    write(fd, "1", sizeof(char));
    lseek(fd, 0, SEEK_SET);
  }

  sleep(5);

  write(fd, "0", sizeof(char));

  close(fd);

  return 0;
}