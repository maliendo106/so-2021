#include <stdio.h>

int main(int argc, char *argv[]){

    printf("Cantidad de argumentos: %d\n",argc);
    fflush(stdout);

    for ( int i = 0; i < argc; i++ ) {
    printf( "argumento[%d] = %s \n", i, argv[i]);
    fflush(stdout);
    }
    return 0;
}