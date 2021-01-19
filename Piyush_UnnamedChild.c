#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	pid_t pid;
	int mypipefd[2];
	int ret;
	char buf[20];
	ret=pipe(mypipefd);
	if(ret==-1)
	{
		perror("pipe");
		exit(1);
	}
	pid=fork();
	if(pid==0)
	{
		printf("Child Process\n");
		write(mypipefd[1],"hello Piyush",12);
	}
	else
	{
		printf("Parrent Process\n");
		read(mypipefd[0],buf,15);
		printf("buf:%s\n",buf);
	}
	return 0;
}
