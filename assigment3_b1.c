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

	//Assigning address to FIFO file system
	char *myfifo="/tmp/myfifo";
	char arr1[200],arr2[200];

	//Creation of named pipe FIFO
	mkfifo(myfifo,0666);

	while(1)
	{
		//Writing in Program1
		fd=open(myfifo, O_WRONLY);
		printf("\nWrite in program1:");
		//fgets(arr1, 200, stdin); 
		scanf("%s",arr1);
		write(fd, arr1, strlen(arr1)+1);
		close(fd);

		//Reading from Program2
		fd=open(myfifo, O_RDONLY);
		read(fd, arr2, strlen(arr2));
		printf("\nRead from Program2: %s",arr2);
		close(fd);

	}
	return 0;
}