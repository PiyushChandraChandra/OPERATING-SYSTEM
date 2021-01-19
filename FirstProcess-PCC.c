#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SHSIZE 100
int main()
{
	int retval, shmid;
	void *memory = NULL;
	char *p;
	key_t key= 9876;
/*****INITIALIZATION*****/
	shmid = shmget (key, SHSIZE, IPC_CREAT | 0666);
	if(shmid <0)
	{
		printf("failure in shared memory initialization");
		perror("shmget");
		exit(1);
	}
/*****ATTACHMENT*****/
	memory = shmat (shmid, NULL, 0);
	if (memory == NULL)
	{
		printf("failure in shared memory attachment");
		return 0;
	}
/*****perform writting*****/
	p = (char *) memory;
	memset(p, '\0', SHSIZE);
	memcpy (p, "HELLO", SHSIZE );
	/*****DETACHMENT*****/
	retval = shmdt (p);
	if(retval<0)
	{
		printf("failure in shared memory detachment");
		exit(1);
	}
	return 0;
}
