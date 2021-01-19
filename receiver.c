#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//#define SERVER_KEY_PATHNAME "/tmp/mqueue_server_key"

struct msgAB
{
	long mtype;
	char msgtxt[150];
};

int main()
{
	struct msgAB msg;
	int msgid;
	key_t key;
	if((key = ftok("myfile.txt",'b')) == -1)
	{
		perror("key");
		exit(1);
	}
	if((msgid = msgget(key,0644)) == -1)
	{
		perror("msgid");
		exit (1);
	}

	while(1)
	{
		if(msgrcv(msgid, &msg, sizeof(msg),1,0) == -1)
		{
			perror("msgrcv");
			exit (1);
		}
		printf("%s\n" , msg.msgtxt);
	}
	return 0;
}
