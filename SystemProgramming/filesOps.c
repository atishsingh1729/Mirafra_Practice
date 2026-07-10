#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>



int main(){
	int fd = open("test.txt",O_RDWR | O_CREAT | O_TRUNC,0644);

	if(fd == -1){
		perror("Error opening file");
		return 1;
	}
	write(fd,"This is a test file \n",strlen("This is a test file \n"));
	printf("File created and written successfully\n");

	close(fd);

	int fd2 = open("test.txt",O_RDONLY);
	if(fd2 == -1){
		perror("Error opening file for reading");
		return 1;
	}

	off_t size = lseek(fd2,0,SEEK_END);
	lseek(fd,0,SEEK_SET);

	char buffer[size + 1];
	ssize_t bytes = read(fd2,buffer,size);

	if(bytes > 0){
		buffer[bytes] = '\0';
	}

	printf("file had string as : %s", buffer);

	close(fd2);


	return 0;
}

