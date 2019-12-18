#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main()
{
	int fd;
	int PID;

	//Assigning address to FIFO file system
	char *myfifo="/tmp/myfifo";
	char str3[200],str4[200];

	//Creation of named pipe FIFO
	mkfifo(myfifo,0666);
	
		
		//Reading from Program2
		fd=open(myfifo, O_RDONLY);
		read(fd, str3, strlen(str3));
		printf("\nRead from Program1\n: %s",str3);
		close(fd);
		//if(strlen(str1)==3)
			PID=getpid();
			printf("\n%d\n",PID);
		sprintf(str4,"%d",&PID);
		printf("%s",str4);

		//Writing in Program1
		
		fd=open(myfifo, O_WRONLY);
		//printf("\nWrite in program2:");
		//fgets(str2, 200, stdin); 
		//scanf("%s",str2);
		write(fd, str4, strlen(str4)+1);
		close(fd);
	
	
	return 0;
}