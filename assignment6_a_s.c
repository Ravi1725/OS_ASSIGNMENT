#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

int main()
{
	key_t key=88;
	int shmid;
	char *buffer;
	size_t size=1024;

	//Generating Unique key
	//key=ftok("shmfile",65);

	//Generating shared memory id
	shmid=shmget(key,size,0666|IPC_CREAT);

	//shmat to attach to shared memory
	buffer =(char*) shmat(shmid,(void*)0,0);

	//var=getpid();
	printf("Enter the data\n");
	gets(buffer);

	printf("Data written in memory:- %s\n",buffer);

	//Detach from shared memory
	shmdt(buffer);

	return 0;
}