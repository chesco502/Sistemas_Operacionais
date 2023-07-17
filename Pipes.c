#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main()
{
	pid_t pid;
	int pip;
	pid = fork();
	pipe(pip);
	if (pid == 0) { /* child process */
		printf("Entrei no filho!\n");
		value += 15;
		printf ("CHILD: value = %d\n",value); /* LINE A */
		pip=1;
		return 0;
	}
	else if (pid > 0) { /* parent process */
		wait(pip==1);
		printf ("PARENT: value = %d\n",value); /* LINE A */
		return 0;
	}
}
