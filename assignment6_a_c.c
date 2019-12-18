#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

int main()
{
	key_t key=88;
	int shmid;
	char *var;
	size_t size=1024;

	//Generating Unique key
	//key=ftok("shmfile",65);

	//Generating shared memory id
	shmid=shmget(key,size,0666|IPC_CREAT);

	var =(char*) shmat(shmid,(void*)0,0);

	printf("Data read from memory:- %s\n",var);

	//detach from shared memory
	shmdt(var);

	//destory the shared memory
	shmctl(shmid,IPC_RMID,NULL);

	return 0;
}