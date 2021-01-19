#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("I am in Exec.c \n");
	printf("Pid of Exec.c is %d \n",getpid());
	char *args[] = {"./hello",NULL};
	execv(args[0],args);
	printf("Coming back to exec.c");
	return 0;
}
