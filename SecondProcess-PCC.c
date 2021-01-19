#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SHSIZE 100
int main()
{
	int retval, shmid;
	void *memory = NULL;
	char *p;
	key_t key= 9876;
	/************INITIALIZATION************/
	shmid = shmget (key, SHSIZE, IPC_CREAT | 0666);
	if(shmid <0)
	{
		printf("failure in shared memory initialization");
		perror("shmget");
		exit(1);
	}
	/************ATTACHMENT************/
	memory = shmat (shmid, NULL, 0);
	if (memory == NULL)
	{
		printf("failure in shared memory attachment");
		exit(1);
	}
	/************perform printing************/
	p = (char *) memory;
	printf("the MESSAGE is %s \n", p);
	/************DETACHMENT************/
	retval = shmdt (p);
	if(retval<0)
	{
		printf("failure in shared memory detachment");
		exit(1);
	}
	/************Deallocation of shared memory************/
	retval = shmctl ( shmid, IPC_RMID, NULL);
	return 0;
}
