#include "get_next_line.h"


int file_stuff(int fd, char **line, int returnvalue, char *all_fd)
{
	int pos;
	int strlen;
	char *temp;

	pos = 0;
	while (all_fd[pos] != '\n' && all_fd[pos] != '\0')
		pos++;
	if (all_fd[pos] ==  '\n')
	{	
		temp = (char *)malloc(sizeof(char) * pos + 1);
		ft_strlcpy(temp, all_fd, pos + 1);
		*line = temp;
		//printf("%s\n",temp);
		strlen = ft_strlen(all_fd);
		ft_strlcpy(all_fd, &all_fd[pos + 1], strlen - pos + 1);
		return (1);
	}
	else if (all_fd[pos] == '\0')
	{
		*line = all_fd;
	}
	return (0);
}

int get_next_line(int fd, char **line)
{
	static char *all_fd[FD_TOTAL];
	char buf[BUFFER_SIZE + 1];
	char *temp;
	int returnvalue;
	int readbytes;

	returnvalue = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
	 	return (-1);
	if (!all_fd[fd])
		all_fd[fd] = ft_strdup("\0");
	while ((readbytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[readbytes] = '\0';
		temp = ft_strjoin(all_fd[fd], buf);
		free(all_fd[fd]);
		all_fd[fd] = temp;
		if (ft_strchr(temp,'\n'))
			break;
	}
	returnvalue = file_stuff(fd, line, returnvalue, all_fd[fd]);
	// if (returnvalue == 0)
	// 	{
	// 		free(all_fd[fd]);
	// 		all_fd[fd] = NULL;
	// 	}
	//printf("This is the saved bit after reading but not to discard:%s\n", all_fd[fd]);
	return (returnvalue);
}

// OLD TESTING CODE
	// bytes = read(fd,temp,BUFFER_SIZE);
	// printf("What has been read:\n%s",temp);
	// printf("\nThis is how many bytes:%d\n",bytes);
	// buf = ft_strjoin(buf, temp);
	// printf("This is using strjoin on them:\n%s",buf);
	// free(temp);
	//return (1);
	// static char allfiles[100];
	// char buf[BUFFER_SIZE];
	// char temp;
	// int i;
	// int size;
	// i = 0;
	// size = 0;
	// if (fd < 0 || !line)
	// 	return (-1);
	// while (allfiles[fd][size])
	// 	size++;
	// while (read(fd,buf+size,BUFFER_SIZE) > 0)
	// {
	// 	while (buf[i] != '\n' && buf[i])
	// 		i++;
	// 	if (i == BUFFER_SIZE)

	//maybe a working realloc, need to test
	// void *org_realloc(char *ptr, size_t size)
// {
// 	int i = 0;
// 	char *tohold;

// 	if (!ptr || !size)
// 		return (NULL);
// 	tohold = (char *)malloc(size + 1);
// 	while (ptr[i])
// 	{
// 		tohold[i] = ptr[i];
// 		i++;
// 	}
// 	tohold[i] = '\0';
// 	free(ptr);
// 	ptr=tohold;
// 	return (ptr);
// }