#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main()
{
	int fd,x;

	//Assigning address to FIFO file system
	char *myfifo="/tmp/myfifo";
	char str1[200],str2[200];

	//Creation of named pipe FIFO
	mkfifo(myfifo,0666);

	
		

		//Writing in Client
		fd=open(myfifo, O_WRONLY);
		printf("\nquery:");
		//fgets(str2, 200, stdin); 
		scanf("%s",str2);
		write(fd, str2, strlen(str2)+1);
		close(fd);


		

	//Reading from server
		
		fd=open(myfifo, O_RDONLY);
		read(fd, str1, strlen(str1));
		//sscanf(str1,"%d",&x);
		printf("\nRead from Program1: %s",x);
		close(fd);
	

	return 0;
}