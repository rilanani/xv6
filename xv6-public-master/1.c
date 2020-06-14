#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int fd = open(argv[1], O_CREAT);
	int offset = atoi(argv[2]);
	lseek(fd, offset, SEEK_SET);
	int len = atoi(argv[3]);
	char * buffer = (char*) malloc(sizeof(char) * (len+1));
	read(fd, buffer, len);
	if(strcmp(buffer, argv[4]))
		printf("Data read isn't same\n");
	else
		printf("Data read is same\n");
	
}
