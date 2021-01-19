#include<stdio.h>
#include<unistd.h>
int main(void)
{
	int mypipefd[2];
	int ret;
	char buf[15];
	pipe(mypipefd);
	ret=fork();
	if(ret>0)
	{
		fflush(stdin);
		printf("Parrent Process\n");
		write(mypipefd[1],"hello Piyush",12);
	}
	if(ret==0)
	{
		sleep(5);
		fflush(stdin);
		printf("Child Process\n");
		read(mypipefd[0],buf,sizeof(buf));
		write(1,buf,sizeof(buf));
	}
	return 0;
}
