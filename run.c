#include <stdio.h>
#include <stdlib.h>

int main() {
	int pid = fork();
	if (pid == -1) {
		// Il y a une erreur
		perror("fork");
		return EXIT_FAILURE;
	} else if (pid == 0) {
		// On est dans le fils
		printf("Mon PID est %i et celui de mon père est %i\n", getpid(),	getppid());
		system( "python3 script2.py 100 20" );
	} else {
		// On est dans le père
		printf("Mon PID est %i et celui de mon fils est %i\n", getpid(), pid);
	}
	return EXIT_SUCCESS;
}