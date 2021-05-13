#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
void	test_64_without_NL();

//test
int main(int argc, char *argv[])
{
	char *line = NULL;
	//int bytes;
	int fd = open(argv[1],O_RDONLY);
	int hi;

	hi = argc;
	// printf("%d\n",hi);
	// printf("this is argv[1]:%s\n",argv[1]);
	// printf("this is the fd #:%d\n",fd);
	printf("1");
	if (fd >= 0)
	{
		while (get_next_line(fd, &line) > 0)
			{
				printf("%s\n",line);
				free(line);
			}
	}
printf("2");
	// get_next_line(fd, &line);
	if (line)
	{
		printf("%s\n",line);
		free(line);
	}
	printf("3");
	// get_next_line(fd, &line);
	// printf("%s\n",line);
	// free(line);
	// get_next_line(0, &line);
	// printf("%s\n", line);;
	close(fd);
	printf("4");
	test_64_without_NL();
	printf("5");
	//get_next_line(fd, line);
	//get_next_line(fd, line);
	//line[BUFFER_SIZE] = '\0';
	//printf("bytes read is:%d\n",bytes);
	//printf("testing line read \n%s",line);
	//free(line);
	system ("leaks a.out");
}
void	test_64_without_NL(void)
{
	int fd;
	char *line;
	
	//		printf("%i | line %i: %s\n",res, i, line);
	fd = open("64bit_line.txt", O_RDONLY);
	assert(fd != -1);
	if (fd == -1)
		printf("not opened\n");
	
	line = NULL;
	int res;
	int i = 1;
	
	res = get_next_line(fd, &line);
//	printf("%i | line %i: %s\n",res, i, line);
	if (line)
	{
		assert(strcmp(line, "9GN+3XuFJq9SoIVEwyf9N6V0SsRGamXC+5i7fs3TQaDax3Q7obX6his/LqVswZ12") == 0);
		assert(res == 0);
		free(line);
		i++;
	}
	res = get_next_line(fd, &line);
	if (line)
	{assert(strcmp(line, "") == 0);
	assert(res == 0);
	if (line)
		free(line);
	}
	if (close(fd) < 0)
		printf("not closed\n");
}
