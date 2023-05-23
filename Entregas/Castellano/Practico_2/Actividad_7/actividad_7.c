#include <stdio.h>
#include <stdlib.h>
#include <linux/fs.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char *argv[]) {
    
    int file;
    struct stat statbuf;
    int stat_res = stat(argv[1],&statbuf);

    if( stat_res < 0 ) {
        printf("No se encuentra el archivo\n");
        return 1;
    }else {

        printf("Nombre del archivo: %s\n", argv[1]);
        printf("ID del usuario propietario: %u\n", statbuf.st_uid);
        printf("ID del grupo propietario: %u\n", statbuf.st_gid);
        printf("ID dispositivo: [%u, %u]\n", major(statbuf.st_dev), minor(statbuf.st_dev));
        printf("Tipo dispositivo: %lu\n", statbuf.st_rdev);
        printf("Numero de enlaces fisicos: %lu\n", statbuf.st_nlink);
        printf("nodos-I: %lu\n", statbuf.st_ino);
        printf("Proteccion: %#o\n", statbuf.st_mode & ~(S_IFMT));
        printf("Tamaño total en bytes: %fkb\n", ((float)statbuf.st_size));
        printf("Tamaño de bloque: %ld bytes\n", statbuf.st_blksize);
        printf("Numero de bloques asignados: %ld\n", statbuf.st_blocks);
        printf("Hora de ultimo acceso: %s", ctime(&statbuf.st_atime));
        printf("Hora de ultima modificacion: %s", ctime(&statbuf.st_atime));
        printf("Hora de ultimo cambio: %s", ctime(&statbuf.st_ctime));
        printf("Tipo de Archivo: ");

        switch (statbuf.st_mode & S_IFMT) {

            case S_IFSOCK:
                printf("Socket\n");
                break;
            case S_IFREG:
                printf("Archivo normal\n");
                break;
            case S_IFLNK:
                printf("Symlink\n");
                break;
            case S_IFIFO:
                printf("Fifo\n");
                break;
            case S_IFDIR:
                printf("Directorio\n");
                break;
            case S_IFCHR:
                printf("Dispositivo tipo caracter\n");
                break;
            case S_IFBLK:
                printf("Dispositivo tipo bloque\n");
                break;
            default:
                printf("Otro\n");
                break;
        }
    }

  return 0;
}
