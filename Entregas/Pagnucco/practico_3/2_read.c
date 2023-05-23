#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 1

int main() {
  int fd;
  char buff[MAX];

  fd = open("test", O_RDONLY);
  if (fd < 0) {
    printf("Se creara el archivo test\n");
    close(fd);
    fd = open("test", O_WRONLY | O_CREAT, 0664);
    write(fd, "1", sizeof(char));
    close(fd);

    fd = open("test", O_RDONLY);
  }

  read(fd, &buff, MAX);
  while (strcmp(buff, "1") == 0) {
    printf("Contiene %s, seguir!\n", buff);
    fflush(stdout);

    // lseek reposiciona el offset del archivo del file descritor abierto. En
    // este caso pone el offset de nuevo al comienzo
    lseek(fd, 0, SEEK_SET);

    read(fd, &buff, MAX);
    sleep(1);
  }

  close(fd);

  printf("Se encontro un %s, terminar!\n", buff);

  return 0;
}