#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<time.h>

void shm_msg()
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
}

int main()
{
	time_t t1,t2;
	double termination_time;
	int child1;
	pid_t cpid;

	child1=fork();

	
	if(child1==0)
	{
		t1=clock();
		shm_msg();
		//wait(NULL);
		t2=clock();
		termination_time=((double)(t2-t1))/CLOCKS_PER_SEC;
		printf("termination time is : %lf\n",termination_time);
		printf("submission time is :- %ld\n",((double)t1/CLOCKS_PER_SEC));
		printf("termination time is :- %ld\n",((double)t2/CLOCKS_PER_SEC));
		exit(0);
	}
	else
	{
		cpid = wait(NULL);
	}



	return 0;
}