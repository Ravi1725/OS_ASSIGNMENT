/*Write  a  C  program  which  will  be  able  to read  a  file  using read() system call. Now you provide a mechanism to set a lock by using fcntl() system call and to  release the lock by using the same fcntl()
system call. For setting
up 
and releasing 
out 
a lock, you 
have to fill 
up
a struct
ure 
flock 
(struct flock)
with proper values. 
Now you run the program from two di
fferent terminals simultaneously and
demonstrate that if one process has got the lock, then that process
only
can read 
the  f
ile. 
But 
the 
other  one 
is  not  permitted  to 
read  the  file 
until  the  lock 
is 
released by the 
first 
process. That means, only one process 
who acquires the 
lock
can read the file at 
any instant 
of 
time. */

#include <stdio.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <unistd.h>
    
    int main(int argc, char *argv[])
    {

    	char str[100];                 /* l_type   l_whence  l_start  l_len  l_pid   */
    	struct flock fl = { F_WRLCK, SEEK_SET, 0,       0,     0 };
    	int fd;
    
        fl.l_pid = getpid();
    
    	if (argc > 1) 
    		fl.l_type = F_RDLCK;
    
    	if ((fd = open("exp.c", O_RDWR)) == -1) {
    		perror("open");
    		exit(1);
    	}
    
    	printf("Enter text and <return> to try to get lock: ");
    	scanf("%s",str);
    	printf("Trying to get lock...");
    
    	if (fcntl(fd, F_SETLKW, &fl) == -1) {
    		perror("fcntl");
    		exit(1);
    	}
    
    	printf("got lock\n");

        sleep(3);
    	printf("enter the text and <return> to release lock: ");
    	scanf("%s",str);
    
    	fl.l_type = F_UNLCK;  /* set to unlock same region */
    
    	if (fcntl(fd, F_SETLK, &fl) == -1) {
    		perror("fcntl");
    		exit(1);
    	}
    
    	printf("Unlocked.\n");
    
    	close(fd);
    }