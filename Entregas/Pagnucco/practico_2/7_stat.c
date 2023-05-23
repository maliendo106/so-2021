#include <stdio.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char *argv[]) {
  char *nombre = argv[1];

  struct stat f_stats;

  int ret_code = stat(nombre, &f_stats);
  if (ret_code != 0) {
    if (ret_code == -1)
      printf("No existe el archivo \"%s\".\n", nombre);
    else
      printf("Hubo un error abriendo el archivo.\n");
    return 0;
  }

  printf("Stats sobre %s\n\n", nombre);
  printf("ID dispositivo: [%u, %u]\n", major(f_stats.st_dev),
         minor(f_stats.st_dev));
  printf("I-nodes: %lu\n", f_stats.st_ino);
  printf("Cant. link fisicos: %lu\n", f_stats.st_nlink);
  printf("ID User: %u\n", f_stats.st_uid);
  printf("ID Grupo: %u\n", f_stats.st_gid);
  printf("Tipo Disp: %lu\n", f_stats.st_rdev);

  printf("Proteccion: %#o\n", f_stats.st_mode & ~(S_IFMT));
  printf("Tipo de Archivo: ");
  switch (f_stats.st_mode & S_IFMT) {
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

  printf("Size: %fkb\n", ((float)f_stats.st_size) / 1024);
  printf("Size Bloques: %ld bytes\n", f_stats.st_blksize);

  printf("Cant. Bloques: %ld\n", f_stats.st_blocks);
  printf("Hora ultimo acceso: %s", ctime(&f_stats.st_atime));
  printf("Hora ultima modificacion: %s", ctime(&f_stats.st_atime));
  printf("Hora ultimo cambio: %s", ctime(&f_stats.st_ctime));

  return 0;
}