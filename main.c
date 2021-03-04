#include "get_next_line.h"

//test
int main(int argc, char *argv[])
{
	char **line;
	int bytes;
	int fd = open(argv[1],O_RDONLY);
	int hi;

	hi = argc;
	printf("%d\n",hi);

	printf("this is argv[1]:%s\n",argv[1]);
	printf("this is the fd #:%d\n",fd);

	get_next_line(fd, line);
	get_next_line(fd, line);
	//line[BUFFER_SIZE] = '\0';
	//printf("bytes read is:%d\n",bytes);
	//printf("testing line read \n%s",line);
	//free(line);
}