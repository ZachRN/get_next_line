#include "get_next_line.h"

int	file_stuff(char **line, char *all_fd)
{
	int		pos;
	int		strlen;
	char	*temp;

	pos = 0;
	while (all_fd[pos] != '\n' && all_fd[pos] != '\0')
		pos++;
	if (all_fd[pos] == '\n')
	{
		temp = (char *)malloc(sizeof(char) * pos + 1);
		ft_strlcpy(temp, all_fd, pos + 1);
		*line = temp;
		strlen = ft_strlen(all_fd);
		ft_strlcpy(all_fd, &all_fd[pos + 1], strlen - pos + 1);
		return (1);
	}
	else if (all_fd[pos] == '\0')
		*line = all_fd;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*all_fd[FD_TOTAL];
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			readbytes;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!all_fd[fd])
		all_fd[fd] = ft_strdup("\0");
	readbytes = read(fd, buf, BUFFER_SIZE);
	while (readbytes)
	{
		buf[readbytes] = '\0';
		temp = ft_strjoin(all_fd[fd], buf);
		free(all_fd[fd]);
		all_fd[fd] = temp;
		if (ft_strchr(temp, '\n'))
			break ;
		readbytes = read(fd, buf, BUFFER_SIZE);
	}
	return (file_stuff(line, all_fd[fd]));
}
