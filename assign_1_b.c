#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
  int child,grandchild,x=2;
  child=fork();
  grandchild=fork();

  if(child>0 && grandchild>0)
  {
   printf("PID=%d\n PPID=%d\n",getpid(),getppid());
   wait(NULL);
   printf("child terminated\n");
  }

  else if(child==0 && grandchild>0)
	  printf("first child created\n");
  else if(child>0 && grandchild==0)
  { 
   printf("Second child created\n");
   printf("ROLL NUMBER is CSB17078\n");

  }
  else
	  printf("Third child created\n");

  return 0;
}
