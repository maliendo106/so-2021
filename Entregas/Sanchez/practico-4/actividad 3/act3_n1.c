#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int main()
{
    int archivo;
    time_t tiempo;
    char *msj;

    archivo = open("compartirPipe", O_WRONLY);
    if (archivo != -1)
    {
        time(&tiempo);
        msj = ctime(&tiempo);
        write(archivo, msj, strlen(msj));
    }
    return 0;
}
