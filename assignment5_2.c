#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buffer
{
	long msg_type;
	char msg[200];
}message;

int main()
{
	int msg_id;
	key_t key;

	//generating the unique key
	key=ftok("programfile",65);

	//generating the message queue
	msg_id=msgget(key,0666|IPC_CREAT);
	message.msg_type=1;

	msgrcv(msg_id,&message,sizeof(message),0,1);

	printf("\n message id is:- %d\n",msg_id);
	printf("\nrecieved data:-%s\n",message.msg);

	msgctl(msg_id,IPC_RMID,NULL);

	return 0;

}