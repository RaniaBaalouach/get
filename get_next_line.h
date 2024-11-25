#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int find_newline(char *buf);
size_t	ft_strlen(char *s);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char *read_line(char *saved_buf, int fd);
char *fetch_line(char *saved_buf);
char *keep_line(char *buf);

#endif