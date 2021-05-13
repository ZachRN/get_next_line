#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# if BUFFER_SIZE < 0
# undef BUFFER_SIZE
# define BUFFER_SIZE 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define FD_TOTAL 128

typedef struct	s_filehold
{
	char *all_fd[FD_TOTAL];
	char buf[BUFFER_SIZE + 1];
}				t_filehold;

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif