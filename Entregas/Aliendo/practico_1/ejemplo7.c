#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// prototipo de las funciones
void signalPadre(int);
void signalHijo(int);

// variables globales
int pid;

// funcion principal main
int main() {

	pid = fork();
	
	if (pid == 0){
		signal( SIGINT, signalHijo);    // ctrl + C
		signal( SIGTSTP, signalHijo);	// ctrl + Z
	}else {
		signal( SIGINT, signalPadre);   // ctrl + C
		signal( SIGTSTP, signalPadre);  // ctrl + Z
	}

	while(1) {
		printf(".\n");
		sleep(1);
		fflush(stdout);
	}
	
	return 0;
}

void signalPadre(int sig_num) {
	
    int status;
	
	if ( sig_num == SIGINT) {
		printf( "El proceso padre capturo la senal interrumpir\n");
		fflush(stdout);
		kill(pid, sig_num);
	}else if (sig_num == SIGTSTP) {
		printf( "El proceso padre capturo la senal suspender\n");
		fflush(stdout);
		kill(pid, sig_num);
		wait(&status);
		exit(0);
	}
}

void signalHijo(int sig_num) {

	if ( sig_num == SIGINT) {
		printf( "El proceso hijo capturo la senal interrumpir\n");
	}else if (sig_num == SIGTSTP) {
		printf( "El proceso hijo captura la senal y terminan los procedos\n");
		exit(0);
	}
	fflush(stdout);
}