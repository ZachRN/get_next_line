#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static int str_pos = 0;
	char buf[BUFFER_SIZE];
	str_pos += 10;
	read(fd,line,BUFFER_SIZE);
	printf("current number is :%d\n",str_pos);
	printf("testing line read \n%s",line);
	return (str_pos);
}