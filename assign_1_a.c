#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
   int child1,grandchild,i=1;
   FILE *ftr;
   
   ftr=fopen("data.txt","w");
   if (ftr == NULL) 
    { 
        printf("Could not open file"); 
        return 0; 
    } 
   child1= fork();
   if(child1==0)
   {
     printf("PID is %d\n,PPID is %d\n",getpid(),getppid());
     fprintf(ftr,"%d",i);
   }
   grandchild=fork();
   if(grandchild==0)
   {
    printf("My roll number is CSB17078\n");
    fprintf(ftr,"%d",i);
   }
    
  // printf("\nhello world\n");
   //fork();
  // printf("program started\n");
  // printf("PID is %d\n,PPID is %d\n",getpid(),getppid());
  // fork();
  // printf("My Roll Number is CSB17078\n");
   fclose(ftr);
   return 0; 
}
