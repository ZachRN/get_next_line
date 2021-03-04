#include "get_next_line.h"

//test
int main(int argc, char *argv[])
{
	char *line;
	int bytes;
	int fd = open(argv[1],O_RDONLY);
	int hi;

	hi = argc;
	printf("%d\n",hi);

	printf("this is argv[1]:%s\n",argv[1]);
	printf("this is the fd #:%d\n",fd);

	line = (char *)malloc((sizeof(char)*(BUFFER_SIZE + 1)));
	bytes = read(0,line,BUFFER_SIZE);
	printf("bytes read is:%d\n",bytes);
	printf("testing line read \n%s\n",line);
	free(line);
}