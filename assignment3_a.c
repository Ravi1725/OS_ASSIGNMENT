/*Write  a  C  program  to  handle  the  
reception  of  INTERRUPT  FROM  THE  
KEYBOARD  signal  by  executing  a  particul
ar  (user)  function,  which  function  is  
responsible  for  crea
ting  a  child  process  by  
using  fork()  system  call.  Also,  the  child  
process will take an input N (N is the no. of terms to generate the Fibonacci series) 
from  the  user  and  generate  the  Fibonacci  series  up  to  N  terms.  Then  the  child  
process  will  send  the  Fibonacci  series  terms  one  by  one  to  the  parent  process  by  
using pipe() system call and the parent pr
ocess will read the Fibonacci series terms 
one by one and will display it. */



#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>

int n;
char ch[200];
int pid;
int child_pid;

void handle_sigint(int sig)
{
int child,x=2;
int fds[2];
int return_status;
return_status = pipe(fds);
        if(return_status == -1)
        {
                printf("Unable to create pipe\n");

        }
	printf("Enter the values of n\n");
        scanf("%d",&n);
	pid=fork();

	//child process
        if(pid==0)
        {       
		close(fds[0]);
	        child_pid=getpid();
		sprintf(ch,"%d",child_pid);
		printf("write child_pid:-%d\n",child_pid);
		write(fds[1],ch,sizeof(ch)+1);
		int i=0,j=1,k;
               // printf("Enter the values of n\n");
               //scanf("%d",&n);
		//printf("\n%d\n%d\n",i,j);

		
		for(int m;m<=n;m++)
		{
			k=i+j;
			printf("Child write on pipe %d\n ",k);
			sprintf(ch,"%d",k);
		        //printf("\nChild write on pipe %d ",k);
			//close(pipefds[0]);
			i=j;
			j=k;
			write(fds[1],ch,sizeof(ch)+1);
			//printf("\nChild write on pipe %d ",k);
			sleep(2);
		}
		//close(pipefds[1]);
        }

	//Parent process
        else{
		int k;
                close(fds[1]);
                read(fds[0],ch,sizeof(ch)+1);
                sscanf(ch,"%d",&k);
                printf("Parent recieved Child Process ID:-%d\n",k);
		for(int j=0;j<=n;j++)
		{
			read(fds[0],ch,sizeof(ch)+1);
			sscanf(ch,"%d",&k);
			printf("Parent read %d\n",k);
		}




		//close(pipefds[0]);
                }
	

}

int main()
{
	//printf("Enter the values of n\n");
        //scanf("%d",&n);

        signal(SIGINT, handle_sigint);
        while(1);
	sleep(2);
        return 0;

}
