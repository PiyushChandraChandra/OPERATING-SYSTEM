#include <stdio.h>
#include <pthread.h>
#include<unistd.h>
pthread_t thread[2];
static void *func1(void *_)
{
	int i;
	for (i=0;i<10;i++)
	{
		printf("\n THREAD1 IS FOR THE VALUE OF I IS : %d",i);
		sleep(1);
	}
}
static void *func2(void *_)
{
	int i;
	for (i=0;i<5;i++)
	{
	printf("\n THREAD2 IS FOR THE VALUE OF I IS : %d",i);
	sleep(5);
	}
	printf("\n");
}
int main()
{
	pthread_create (&thread[0], NULL, func1, NULL);
	pthread_create (&thread[1], NULL, func2, NULL);
	pthread_exit(NULL);
}
