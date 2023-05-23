/*
2. Escriba un programa (en C) que utilice la llamada fork() para 
crear un nuevo proceso. Es necesario que cada proceso escriba un 
mensaje diferente en pantalla.
Utilice el siguiente esquema de programa

int main() {
	int pid;
	...
	pid = fork();
	if (pid == 0) {
		// hijo 
	//	...
//	} else {
	 padre 
		...
	}
	return 0;
	}

Estudie la página de manual de la llamada fork() .

*/

#include <stdio.h>

int main(){
    int pid;

    pid = fork();

    if (pid==0) { //Hijo
        printf("Proceso Hijo\n");
    }else{//Padre
        printf("Proceso Padre\n");
    }

    return 0;

}