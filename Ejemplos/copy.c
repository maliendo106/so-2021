/*
    copia origen en destino por 4 métodos diferentes file, pipe, socket e internet
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define FILE 256
#define BUFF 512
#define SOCK_PATH "copy.socket"

char buff[BUFF];
int in, out, n;

void copy_file( char *origen, char *destino );
void copy_pipe( char *origen, char *destino );
void copy_sock( char *origen, char *destino );
void copy_inte( char *origen, char *destino );

int main( int argc, char *argv[] ) {

    char origen[FILE], destino[FILE], tipo[FILE];
    
    if ( argc != 4 ) {
        printf("Solo se aceptan 3 argumentos: ori dest tipo\n");
        printf("  tipo: file pipe sock inte\n");
        exit(1);
    }
    strcpy( origen,  argv[1] );
    strcpy( destino, argv[2] );
    strcpy( tipo,    argv[3] );

    in = open( origen, O_RDONLY );
    if ( in == -1  ) { printf("No se pudo abrir archivo %s\n", origen  ); exit(2); }
    out = open( destino, O_WRONLY|O_CREAT, 0644 );
    if ( out == -1 ) { printf("No se pudo abrir archivo %s\n", destino ); exit(3); }

    if ( strcmp( tipo, "file" ) == 0 ) 
        copy_file( origen, destino );
    if ( strcmp( tipo, "pipe" ) == 0 ) 
        copy_pipe( origen, destino );
    if ( strcmp( tipo, "sock" ) == 0 ) 
        copy_sock( origen, destino );
    if ( strcmp( tipo, "inte" ) == 0 ) 
        copy_inte( origen, destino );
    
    close(in);
    close(out);

    return 0;
}

void copy_file( char *origen, char *destino ) {
    while ( 1 ) {
        n = read( in, buff, BUFF );
        if ( n == 0 ) 
            break;
        write( out, buff, n );
    }
}

void copy_pipe( char *origen, char *destino ) {
    int p[2];
    pipe( p );
    int pid  = fork();

    if ( pid != 0 ) {
        dup2( p[1], 1 );                    /* close stdout */
        while ( (n = read( in, buff, BUFF )) != 0 ) {
            write( STDOUT_FILENO, buff, n );
        }
    } else {
        dup2( p[0], 0 );                    /* close stdin */
        while (1) {
            n = read( STDIN_FILENO, buff, BUFF );
            if ( n == 0 )
                break;
            write( out, buff, n );
        }
    }
    close(p[0]);
    close(p[1]);
}

// Sockets de tipo Unix
void copy_sock( char *origen, char *destino ) { int a=1; }

// Sockets de tipo internet
void copy_inte( char *origen, char *destino ) { int a=1; }

