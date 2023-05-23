/*
4) Intercambio de mensajes entre dos procesos utilizando un archivo
Sean dos procesos, A y B, los cuales van a 'hablar'
A crea un archivo, ej. comunicador.txt, y escribe dentro de el un mensaje.
Luego lee periodicamente el archivo y espera que el mensaje 'cambie',
cuando descubre que ha cambiado termina.

B verifica que exista el archivo anterior, cuando lo encuentra lo lee,
luego lo sobre-escribe con un mensaje de respuesta, cierra el archivo
y termina.
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX 100

int main(int argc,char *argv[]) {

  int file;
  char buffer [MAX];
  char msg[] = "Buenas buenas";

  
    remove("chat.txt");
    file = open("chat.txt", O_RDWR | O_CREAT, 0664);
    write(file, msg, strlen(msg) + 1);
    lseek(file, 0, SEEK_SET);

    printf("ej4A: %s\n", msg);
    while (read(file, buffer, MAX)) {
        if (strcmp(buffer, msg) != 0)
            break;
        lseek(file, 0, SEEK_SET);
        printf("...\n");
        sleep(3);
    }

    read(file, buffer, MAX);
    printf("ej4B: %s\n", buffer );
    close(file);
  
  return 0;

}