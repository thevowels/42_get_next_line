#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
char	*get_next_line(int fd);
ssize_t	ft_strchr(char *str, char c);
char	*ft_strndup(char *str, size_t t);
char	*ft_strdup(char *str);

#endif