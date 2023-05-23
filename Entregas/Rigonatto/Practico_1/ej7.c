/*
7. Escriba un programa que cree un hijo, capture las mismas señales 
del programa anterior, se las reenvie al hijo y reproduzca la 
funcionalidad previa, es decir que el hijo escriba un mensaje para 
la primer señal y termine para la segunda, al terminar el hijo también 
debe terminar el padre.
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//Prototipo de las funciones
void Psigmanager(int);
void Hsigmanager(int);


//variable global
int pid;

//main
int main() {

	pid = fork();
	
	if (pid == 0){
		signal( SIGINT, Hsigmanager);
		signal( SIGTSTP, Hsigmanager);	
	}

	else {
		signal( SIGINT, Psigmanager);
		signal( SIGTSTP, Psigmanager);

	}
		while( 1 ){
			printf(".\n");
			sleep(1);
			fflush(stdout);
		}
	
	return 0;
}

void Psigmanager(int sig_num){
	int status;
	
	
	

	if ( sig_num == SIGINT) {
		printf( "El proceso padre capturo la senal 'Interrumpir' y se la reenvio al Hijo\n");
		fflush(stdout);
		kill(pid, sig_num);
	}else if (sig_num == SIGTSTP){
		printf( "El proceso padre capturo la senal 'Suspender' y se la reenvio al Hijo\n");
		fflush(stdout);
		kill(pid, sig_num);
		wait(&status);
		exit(0);
	}
	
	
}

void Hsigmanager(int sig_num){
	


	if ( sig_num == SIGINT) {
		printf( "El proceso hijo capturo la senal 'Interrumpir'. \n");
	}else if (sig_num == SIGTSTP){
		printf( "El proceso Hijo capturo la senal 'Suspender'. Terminando procesos padre e hijo\n");
		exit(0);
	}
	fflush(stdout);
}