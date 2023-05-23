#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

  int archivo;

 archivo = open("test", O_WRONLY);

  write(archivo, "0", sizeof(char));

  close(archivo);

return 0;
}