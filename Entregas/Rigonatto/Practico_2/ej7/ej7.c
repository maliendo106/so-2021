/*
7) Escriba un programa que reciba por linea de comando el file_name de
un archivo, a continuacion muestre toda la informacion que se
pueda obtener de ese archivo usando la funcion "stat()".

AYUDA: Lo que hay que mostrar en este caso son los distintos
componentes de la estructura devuelta por la funcion stat().
             
              struct stat
              {
                  dev_t         st_dev;      /* dispositivo 
                  ino_t         st_ino;      /* inodo 
                  mode_t        st_mode;     /* protecci� 
                  nlink_t       st_nlink;    /* nmero de enlaces f�icos 
                  uid_t         st_uid;      /* ID del usuario propietario 
                  gid_t         st_gid;      /* ID del grupo propietario 
                  dev_t         st_rdev;     /* tipo dispositivo (si es
                                                dispositivo inodo) 
                  off_t         st_size;     /* tama� total, en bytes 
                  unsigned long st_blksize;  /* tama� de bloque para el
                                                sistema de ficheros de E/S 
                  unsigned long st_blocks;   /* nmero de bloques asignados 
                  time_t        st_atime;    /* hora ltimo acceso 
                  time_t        st_mtime;    /* hora ltima modificaci� 
                  time_t        st_ctime;    /* hora ltimo cambio 
              };

    De estos campos (man 2 stat) podemos mostrar como enteros (%d) a:
    st_ino, st_nlink, st_uid, st_gid, st_size, st_blksize, st_blocks. 
    
    Las fechas deben ser pasadas a la funcion ctime() que retorna una
    cadena, Ej. ctime(&var.st_atime) e imprimir esto como cadena (%s).
    
    Para el manejo de el campo st_mode, debemos hacer uso de lo
    siguiente:
    a) Para imprimir los permisos iterpretamos ese campo como una
    representacion octal, con lo cual lo imprimos
    
	   ("%#o", var.st_mode & ~(S_IMFT));
    
    b) Para descubrir cual es el tipo de archivo usamos los macros
    definidos en man 2 stat, a saber por ej. S_ISLNK, de modo que
    podemos escribir
	   
	   if (S_ISLNK(var.st_mode)) {
		  printf("Es un vinculo simbolico"):
	   }
    
    y asi sucesivamente para el resto de los macros.
    
    c) Por ultimo, para interpretar el campo st_dev, debemos agregar
    un archivo de cabecera
    
	   #include <linux/fs.h>
    
    En este archivo estan incluidos dos macros MAJOR(m) y MINOR(m) a
    los cuales les damos como argumento el campo st_dev y nos
    retornara los numeros mayor y menor correspondientes al dipositivo
    fisico, para ver esto pueden listar el dispositivo correspondiento
    al disco duro
    
	   ls -l  /dev/sda6
    
    y al observar el campo de tamaño se ven dos numeros, estos son el
    numero mayor y el menor que corresponden al dispositivo en este
    caso
    
	   mayor 8 ->  SCSI8_MAYOR
	   minor 6 ->  particion 6 (en realidad disco logico)
    
    Ambos numeros se pueden mostrar como enteros.

*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char *argv[]) {
  char *file_name = argv[1];

  struct stat file_stats;

  int ret_code = stat(file_name, &file_stats); //busco el archivo file_name, guardo sus stats en file_stats y el resultado de la operacion queda en ret_code
  
  if (ret_code != 0) { // si es 0 se abrio correctamente 
    if (ret_code == -1) // el archivo no se encontro
      printf("Archivo \"%s\" no encontrado.\n", file_name);
    else
      printf("Se produjo un error intentando abrir el archivo.\n");
    return 0;
  }

  printf("Stats sobre %s\n\n", file_name);
  printf("ID dispositivo: [%u, %u]\n", major(file_stats.st_dev),
         minor(file_stats.st_dev));
  printf("Inode number: %lu\n", file_stats.st_ino);
  printf("Number of hard links: %lu\n", file_stats.st_nlink);
  printf("User ID: %u\n", file_stats.st_uid);
  printf("Group ID: %u\n", file_stats.st_gid);
  printf("Device ID: %lu\n", file_stats.st_rdev);

  printf("Mode: %#o\n", file_stats.st_mode & ~(S_IFMT));
  printf("File type: ");
  switch (file_stats.st_mode & S_IFMT) {
  case S_IFSOCK:
    printf("socket\n");
    break;
  case S_IFLNK:
    printf("symbolic link\n");
    break;
  case S_IFREG:
    printf("regular file\n");
    break;
  case S_IFBLK:
    printf("block device\n");
    break;
  case S_IFDIR:
    printf("directory\n");
    break;
  case S_IFCHR:
    printf("character device\n");
    break;
  case S_IFIFO:
    printf("FIFO\n");
    break;
  default:
    printf(" ~ type no found ~\n");
    break;
  }

  printf("Size: %fkb\n", ((float)file_stats.st_size) / 1024);
  printf("Block size: %ld bytes\n", file_stats.st_blksize);

  printf("Number of 512B blocks allocated: %ld\n", file_stats.st_blocks);
  printf("last access: %s", ctime(&file_stats.st_atime));
  printf("last modification: %s", ctime(&file_stats.st_atime));
  printf("last status change: %s", ctime(&file_stats.st_ctime));

  return 0;
}


