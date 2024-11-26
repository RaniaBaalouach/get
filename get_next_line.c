#include "get_next_line.h"

int	find_newline(char *buf)
{
	int	i;

	if (!buf)
		return (0);
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_line(char *saved_buf, int fd)
{
	int		readed;
	char	*line;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	readed = 1;
	while (!find_newline(saved_buf) && readed > 0)
	{
		readed = read(fd, line, BUFFER_SIZE);
		if (readed == -1)
		{
			free(line);
			free(saved_buf);
			return (line = NULL, saved_buf = NULL, NULL);
		}
		line[readed] = '\0';
		saved_buf = ft_strjoin(saved_buf, line);
	}
	free(line);
	line = NULL;
	return (saved_buf);
}

char	*fetch_line(char *saved_buf)
{
	int		i;
	char	*next_line;

	if (!saved_buf || !*saved_buf)
		return (NULL);
	i = 0;
	while (saved_buf[i] && saved_buf[i] != '\n')
		i++;
	if (saved_buf[i] == '\n')
	{
		next_line = (char *)malloc(sizeof(char) * (i + 2));
		if (!next_line)
			return (NULL);
		ft_strlcpy(next_line, saved_buf, i + 2);
	}
	else
	{
		next_line = (char *)malloc(sizeof(char) * (i + 1));
		if (!next_line)
			return (NULL);
		ft_strlcpy(next_line, saved_buf, i + 1);
	}
	return (next_line);
}

char	*keep_line(char *buf)
{
	int		i;
	char	*saved_buf;

	if (!buf)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	saved_buf = ft_strdup(buf + i + 1);
	free(buf);
	buf = NULL;
	return (saved_buf);
}

char	*get_next_line(int fd)
{
	static char	*saved_buf;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_buf = read_line(saved_buf, fd);
	if (!saved_buf)
		return (NULL);
	next_line = fetch_line(saved_buf);
	saved_buf = keep_line(saved_buf);
	return (next_line);
}
