/*
7) Escriba un programa que reciba por linea de comando el nombre de
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
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc,char *argv[]) {
    
    int file;
    struct stat statbuf;
    int stat_res = stat(argv[1],&statbuf);
    if(stat_res != 0){
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }else{

        printf("Nombre del archivo: %s\n", argv[1]);
        printf("ID del usuario: %u\n", statbuf.st_uid);
        printf("ID Grupo: %u\n", statbuf.st_gid);
        printf("ID dispositivo: [%u, %u]\n\n", major(statbuf.st_dev),
         minor(statbuf.st_dev));

        printf("Tipo Dispositivo: %lu\n", statbuf.st_rdev);
        printf("Cantidad link fisicos: %lu\n", statbuf.st_nlink);
        printf("I-nodes: %lu\n", statbuf.st_ino);
        printf("Proteccion: %#o\n\n", statbuf.st_mode & ~(S_IFMT));

        printf("Tamaño: %fkb\n", ((float)statbuf.st_size) / 1024);
        printf("Tamaño de Bloques: %ld bytes\n", statbuf.st_blksize);
        printf("Cantidad de Bloques: %ld\n\n", statbuf.st_blocks);

        printf("Hora de ultimo acceso: %s", ctime(&statbuf.st_atime));
        printf("Hora de la ultima modificacion: %s", ctime(&statbuf.st_atime));
        printf("Hora del ultimo cambio: %s\n", ctime(&statbuf.st_ctime));

        printf("Tipo de Archivo: ");
        switch (statbuf.st_mode & S_IFMT) {
            case S_IFSOCK:
                printf("Socket\n");
                break;
            case S_IFREG:
                printf("Archivo normal\n");
                break;
            case S_IFLNK:
                printf("symlink\n");
                break;
            case S_IFIFO:
                printf("FIFO/pipe\n");
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
                printf("Desconocido\n");
                break;
        }
    }

  return 0;
}

