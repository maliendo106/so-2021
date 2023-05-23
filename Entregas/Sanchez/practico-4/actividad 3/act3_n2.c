#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX_POS 250

int main()
{
    char buffer[MAX_POS];
    int archivo = open("compartirPipe", O_RDONLY);

    if (archivo != -1)
    {
        read(archivo, buffer, MAX_POS);
    }
    printf("Mensaje : %s", buffer);
    return 0;
}