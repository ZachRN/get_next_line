#include "get_next_line.h"

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

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&str[i]);
	return (NULL);
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

char	*ft_strdup(const char *s)
{
	char	*str;
	int		strlen;
	int		i;

	strlen = ft_strlen(s);
	str = malloc(sizeof(char) * (strlen + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < strlen)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int get_next_line(int fd, char **line)
{
	static char *all_fd[FD_TOTAL];
	char buf[BUFFER_SIZE + 1];
	char *temp;

	if (!all_fd[fd])
		all_fd[fd] = ft_strdup("");
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		temp = buf;
		all_fd[fd] = ft_strjoin(all_fd[fd], temp);
		if (ft_strchr(temp,'\n'))
			break;
	}
	printf("This is the current of all_fd[%d]\n%s\n",fd,all_fd[fd]);
	// bytes = read(fd,temp,BUFFER_SIZE);
	// printf("What has been read:\n%s",temp);
	// printf("\nThis is how many bytes:%d\n",bytes);
	// buf = ft_strjoin(buf, temp);
	// printf("This is using strjoin on them:\n%s",buf);
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