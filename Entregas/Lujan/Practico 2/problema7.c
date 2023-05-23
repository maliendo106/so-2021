
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
