#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LIM 9999
#define MAX 1024

void parsear_directory(int base, char *buff) {
  char directory[base - 24];
  strncpy(directory, buff, base - 24 + 1);
  printf("## Directory: %s\n", directory);
}

int main() {
  // buff es el buffer, su tamanio es de 1 porque se leera char a char
  char buff[LIM];
  char aux[LIM], base_arr[6];
  int fd, n;
  int contador_record, record_length, base;

  // fd es un file descriptor, y abre el archivo
  fd = open("osbooks.iso2709", O_RDONLY);

  if (fd < 0) {
    printf("No existe el archivo!\n");
    return 0;
  }

  while ((n = read(fd, buff, 24))) {
    contador_record++;

    // ## LEADER
    strncpy(aux, buff, 5);
    record_length = (int)strtol(aux, (char **)NULL, 10);
    printf("Record #%d, Length: %d\n", contador_record, record_length);

    strncpy(aux, buff, 24);
    printf("## Leader: %s\n", aux);

    strncpy(base_arr, buff + 12, 5);
    base = (int)strtol(base_arr, (char **)NULL, 10);
    printf("Base: %s\n", base_arr);

    // ## DIRECTORY
    n = read(fd, buff, base - 24);
    parsear_directory(base, buff);
    n = read(fd, buff, record_length - base);
    printf("\n");
  }

  close(fd);

  return 0;
}