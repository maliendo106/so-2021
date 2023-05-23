#include <stdio.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <linux/fs.h>
#include <time.h>

int main(int argc, char *argv[]) {
  char *nombre = argv[1];

  struct stat stats;

  int ret_code = stat(nombre, &stats);
  if (ret_code != 0) {
    if (ret_code == -1)
      printf("No existe el archivo \"%s\".\n", nombre);
    else
      printf("Hubo un error abriendo el archivo.\n");
    return 0;
  }
printf("--------------informacion de stats--------------------");
  printf("Stats sobre %s\n\n", nombre);
  printf("ID dispositivo: [%u, %u]\n", major(stats.st_dev),
         minor(stats.st_dev));
  printf("I-nodes: %lu\n", stats.st_ino);
  printf("Cant. link fisicos: %lu\n", stats.st_nlink);
  printf("ID User: %u\n", stats.st_uid);
  printf("ID Grupo: %u\n", stats.st_gid);
  printf("Tipo Disp: %lu\n", stats.st_rdev);

   printf("Size: %fkb\n", ((float)stats.st_size) / 1024);
  printf("Size Bloques: %ld bytes\n", stats.st_blksize);

  printf("Cant. Bloques: %ld\n", stats.st_blocks);
  printf("Hora ultimo acceso: %s", ctime(&stats.st_atime));
  printf("Hora ultima modificacion: %s", ctime(&stats.st_atime));
  printf("Hora ultimo cambio: %s", ctime(&stats.st_ctime));

  printf("Proteccion: %#o\n", stats.st_mode & ~(S_IFMT));
  printf("Tipo de Archivo: ");
  switch (stats.st_mode & S_IFMT) {
  case S_IFBLK:
    printf("dispositivo tipo bloque\n");
    break;
  case S_IFCHR:
    printf("dispositivo tipo caracter\n");
    break;
  case S_IFDIR:
    printf("directorio\n");
    break;
  case S_IFIFO:
    printf("FIFO/pipe\n");
    break;
  case S_IFLNK:
    printf("symlink\n");
    break;
  case S_IFREG:
    printf("archivlo normal\n");
    break;
  case S_IFSOCK:
    printf("socket\n");
    break;
  default:
    printf("desconocido?\n");
    break;
  }

 

  return 0;
}