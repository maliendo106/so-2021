
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

int main() {
  // Abre un stream de DIRs (struct para un directorio)
  DIR *root = opendir("/");
  struct dirent *entry;

  // Devuelve una entrada usando struct dirent (struct con info de un elemento
  // del directorio). Si entry es NULL se llego al final del archivo
  while ((entry = readdir(root)))
    printf("%s\n", entry->d_name);

  // Se cierra el stream
  closedir(root);

  return 0;
}