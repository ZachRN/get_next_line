#include "get_next_line.h"

void *org_realloc(char *ptr, size_t size)
{
	int i = 0;
	char *tohold;

	if (!ptr || !size)
		return (NULL);
	tohold = (char *)malloc(size + 1);
	while (ptr[i])
	{
		tohold[i] = ptr[i];
		i++;
	}
	tohold[i] = '\0';
	free(ptr);
	ptr=tohold;
	return (ptr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	y = 0;
	while (s1[y] != '\0')
	{
		s3[y] = s1[y];
		y++;
	}
	x = 0;
	while (s2[x] != '\0')
	{
		s3[y] = s2[x];
		x++;
		y++;
	}
	s3[y] = '\0';
	return (s3);
}

int get_next_line(int fd, char **line)
{
	char *buf;
	char *temp;
	int bytes;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	temp = (char *)malloc(BUFFER_SIZE + 1);
	bytes = read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	printf("What has been read:\n%s", buf);
	printf("\nThis is how many bytes:%d\n",bytes);
	// bytes = read(fd,temp,BUFFER_SIZE);
	// printf("What has been read:\n%s",temp);
	// printf("\nThis is how many bytes:%d\n",bytes);
	// buf = ft_strjoin(buf, temp);
	// printf("This is using strjoin on them:\n%s",buf);
	free(buf);
	// free(temp);
	return (1);

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
}