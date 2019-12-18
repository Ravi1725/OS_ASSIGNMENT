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

	printf("Enter the data to write on msg queue\n");
	gets(message.msg);

	//sending the message
	msgsnd(msg_id,&message,sizeof(message),0);
	printf("message Id is :-%d\n",msg_id);
	printf("Sent message is:  %s",message.msg);

	return 0;

}