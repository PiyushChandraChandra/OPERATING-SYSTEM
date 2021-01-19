#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SERVER_KEY_PATHNAME "/tmp/mqueue_server_key"
// Structure of the message
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

	if((msgid = msgget(key,0644 | IPC_CREAT))== -1)
	{
		perror("msgid");
		exit (1);
	}
	printf("\nThe msgid is %d\n", msgid);	
	printf("Enter the text:\n");
	msg.mtype=1;
	while(fgets(msg.msgtxt,198,stdin))
	{
		if(msgsnd(msgid, &msg,sizeof(msg),0) == -1)
		{
			perror("msgsnd");
			exit(1);
		}
	}
	/////////////////// part 4 of the programs: to delete the msgid when work is done //////////////
	if((msgctl(msgid,IPC_RMID,NULL))== -1)
	{
		perror("msgctl");
		exit(1);
	}
	return 0;
}
