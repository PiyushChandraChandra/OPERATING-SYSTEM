#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("I am in hello.c\n");
	printf("Pid of hello.c is %d\n",getpid());
	return 0;
}
