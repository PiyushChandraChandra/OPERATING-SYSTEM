#include <pthread.h>
#include <stdio.h>
#include<unistd.h>
void* myturn( void *arg)
{
	int a=10;
	while(a<13)
	{
		sleep(1);
		printf("My turn!\n");
		a++;
	}
	return NULL;
}
void yourTurn()
{
	int b=10;
	while(b<13)
	{
		sleep(1);
		printf("your turn!\n");
		b++;	
	}
}
int main()
{
	pthread_t newthread;
	pthread_create(&newthread, NULL, myturn, NULL);
	yourTurn();
	return 0;
}
