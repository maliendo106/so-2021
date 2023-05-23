#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  
  int r;

  r = open("test", O_WRONLY);
  
  if (r < 0) {
    
    close(r);
    printf("creamos archivo test\n");
    r = open("test", O_WRONLY | O_CREAT, 0664);
    write(r, "1", sizeof(char));
    lseek(r, 0, SEEK_SET);
  
  }

  printf("sigue con 1...\n");

  write(r, "0", sizeof(char));

  printf("leyo el 0, cerramos\n");

  close(r);

  return 0;

}