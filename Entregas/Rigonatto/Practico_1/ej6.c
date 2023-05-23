/*
Escriba un programa que capture las señales “Ctrl-C” (Interrumpir) 
y “Ctrl-Z” (Suspender), en el primer caso el programa debe escribir un mensaje en pantalla, en el segundo debe terminar.

Utilice el siguiente procedimiento: defina una función que retorne 
void para manejar la señal y asigne una señal a esta función por medio 
de la llamada signal()

void sigmanager(int sig_num) {
	Reasignar la señal 
	signal(SIGNAL, sigmanager):
	...
	fflush(stdout);
	}
	...
	signal(SIGNAL, sigmanager);

*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//Prototipo de la funcion
void sigmanager(int);


//main
int main() {

	signal(SIGINT, sigmanager); //La senal SIGNINT sera manejada por sigmanager -> Ctrol + C
	signal(SIGTSTP, sigmanager); //La senal SIGTSTP sera manejada por sigmanager -> Ctrol + Z
	
	// loop infinito 
	while ( 1 ) {
		printf(".\n");
		fflush(stdout);
		sleep(1);
	}
	
	return 0;
}

//Definicion de la funcion
void sigmanager(int sig_num) {
	//Reasignar la señal 
	signal( sig_num, sigmanager );
	
	if (sig_num == SIGINT){
		printf("Se capturo la senal 'Interrumpir'\n");
		fflush(stdout);
	}else if(sig_num == SIGTSTP){
		printf("Se capturo la senal 'Suspender' \n Se procedera a terminar el proceso\n");
		fflush(stdout);
		exit(0);
	}
}