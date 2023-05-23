#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Prototipo de funcion
void sigmanager(int);

// Funcion principal main
int main() {

	signal(SIGINT, sigmanager); // Ctrol-C
	signal(SIGTSTP, sigmanager); // Ctrol-Z
	 
	while(1) {
		sleep(1);
	}
	
	return 0;
}


// Funcion sigmanager
void sigmanager(int sig_num) {
	
	if ( sig_num == SIGINT ) {

		printf(" -> se ha capturado Ctrl-C\n");
		fflush(stdout);

	} else if ( sig_num == SIGTSTP ) {

		exit(0);
	}
}