#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
	pid_t p;
	p = fork();
	if(p > 0) {
		// sleep(10);
		printf("Parent process is executing with PID: %d\n",getpid());
		exit(0);
	}
	else if(p == 0) {
		sleep(1);
		printf("Child process is executring with PPID: %d\n",getppid());
	}
	else {
		printf("Fork Failed\n");
	}
	return 0;
}
