#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 99999

void process_record(char *record, int record_length);

int main()
{
    int fd;
    char buff[MAX];
    char record[MAX];
    char length[6];
    int record_length;
    int num_records = 0;

    fd = open("osbooks.iso2709", O_RDONLY);
    if (fd < 0)
    {
        printf("No se ha podido leer el archivo\n");
        exit(1);
    }

    while (read(fd, length, 5))
    {
        num_records++;
        record_length = atoi(length); // convierte una cadena en un entero
        printf("Record %d, Length = %d\n", num_records, record_length);
        strcpy(record, length);
        read(fd, buff, record_length - 5);
        strcat(record, buff); // concatena la segunda cadena en la primera
        process_record(record, record_length);
    }

    close(fd);
    return 0;
}

void process_record(char *record, int record_length)
{
    char leader[25];
    char directory[MAX];
    char data[MAX];  
    char base_data_s[6];
    int base_data;
    char tag[13];  
    char nombre[4];
    char longitud[5];
    char posicion[6];
    int n_tag = 0;

    strncpy(leader, record, 24); // strncpy(destino, fuente, cantidad_a_copiar);
    leader[25] = '\0';
    printf("Leader: %s\n", leader);

    strncpy(base_data_s, record + 12, 5); //(12, 13, 14, 15, 16) --> donde empiezan los datos
    base_data_s[6] = '\0';
    base_data = atoi(base_data_s); //paso al valor numérico la posición donde empiezan los datos
    printf("Base: %s\n", base_data_s);

    strncpy(directory, record + 24, base_data - 25);
    printf("============ Directory ============\n");
    printf("Nombre  Longitud  Posicion\n");

    n_tag = ((base_data - 25) / 12);  // porque el directorio se divide cada 12 caracteres
    for (int i = 0; i < n_tag; i++)
    {
        strncpy(tag, directory + (i * 12), 12); 
        tag[12 + 1] = '\0';

        strncpy(nombre, tag, 3);
        strncpy(longitud, tag + 3, 4);
        strncpy(posicion, tag + 7, 5);

        printf("->  %s   %s     %s\n", nombre, longitud, posicion);
    }

    strncpy(data, record + base_data, record_length - base_data); // guardo en data solo los DATOS
    data[record_length - base_data + 1] = '\0';
    printf("Data: %s\n", data);
    printf("\n\n");
}
