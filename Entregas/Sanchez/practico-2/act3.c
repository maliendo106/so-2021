#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

int main()
{
    //Abre directorio raiz
    DIR *raiz = opendir("/");
    struct dirent *entrada;

    //devuelve una entrada si llega a 0 es que no queda mas por leer
    while ((entrada = readdir(raiz)))
        printf("%s\n", entrada->d_name);

    // Se cierra el directorio
    closedir(raiz);

    return 0;
}