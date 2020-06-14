#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int fd = open(argv[1], O_CREAT | O_RDONLY);
	int len = lseek(fd, 0, SEEK_END);
	int copy = open("copy.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IXUSR);
	int i=0;
	for(i=0; i<10; i++) {
		lseek(fd, i*(len/10), SEEK_SET);
		char * buffer = (char*) malloc(sizeof(char) * ((len/10)+1));
		read(fd, buffer, len/10);
		printf("%s", buffer);
		lseek(copy, i*(len/10), SEEK_SET);
		write(copy, buffer, len/10);
	}
	close(copy);
}
