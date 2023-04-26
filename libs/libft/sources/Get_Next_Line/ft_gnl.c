/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:46:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 23:13:28 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strjoin_free(char *s1, char *s2);
void		*ft_realloc_free(char **ptr);
static char	*read_fd(char **rest, char **line, int fd);
static char	*until_newline(char **line, char *buf, char **rest);
static void	cpy_1_line(char **rest, char **line);
static void	secret_trick(char **rest, char *buf, size_t n);

/**
 * @brief Get the next line of a file descriptor;
 * 
 * @param fd The file descriptor to be read;
 * @return A string containing the next line of the file descriptor;
 */
char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (0x0);
	if (!rest[fd])
		rest[fd] = ft_calloc(sizeof(char), 1);
	line = ft_calloc(sizeof(char), 1);
	if (rest[fd] && rest[fd][0] != 0)
	{
		cpy_1_line(&rest[fd], &line);
		if (!ft_strchr(line, '\n'))
			line = read_fd(&rest[fd], &line, fd);
		return (line);
	}
	line = read_fd(&rest[fd], &line, fd);
	if (line[0] == 0 && rest[fd][0] == 0)
	{
		free(line);
		line = 0x0;
		free(rest[fd]);
		rest[fd] = 0x0;
		return (0x0);
	}
	return (line);
}

static void	cpy_1_line(char **rest, char **line)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((*rest)[i] != '\n' && (*rest)[i] != 0)
		i++;
	free(*line);
	if ((*rest)[i] == '\n')
		*line = ft_calloc(sizeof(char), i + 2);
	else if ((*rest)[i] == 0)
		*line = ft_calloc(sizeof(char), i + 1);
	j = i;
	while (i != 0)
		(*line)[j--] = (*rest)[i--];
	(*line)[j] = (*rest)[i];
	*rest = (char *)ft_realloc_free(rest);
}

static char	*read_fd(char **rest, char **line, int fd)
{
	char	*buf;
	size_t	readble;

	readble = 42;
	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (readble > 0)
	{
		readble = read(fd, buf, BUFFER_SIZE);
		buf[readble] = '\0';
		if (readble == 0)
			break ;
		if (ft_strchr(buf, '\n'))
		{
			*line = until_newline(line, buf, rest);
			free(buf);
			buf = 0x0;
			return (*line);
		}
		*line = ft_strjoin_free(*line, buf);
	}
	free(buf);
	buf = 0x0;
	return (*line);
}

static char	*until_newline(char **line, char *buf, char **rest)
{
	size_t	i;
	size_t	j;
	char	*newline;

	i = 0;
	while (buf[i] != '\n')
		i++;
	newline = ft_calloc(sizeof(char), ft_strlen(*line) + i + 2);
	i = 0;
	j = 0;
	while ((*line)[j] != 0)
		newline[i++] = (*line)[j++];
	free(*line);
	j = 0;
	while (buf[j] != '\n')
		newline[i++] = buf[j++];
	newline[i] = buf[j++];
	free(*rest);
	*rest = 0x0;
	if (buf[j] != 0)
		secret_trick(rest, buf, j);
	return (newline);
}

static void	secret_trick(char **rest, char *buf, size_t n)
{
	size_t	i;

	i = 0;
	*rest = ft_calloc(sizeof(char), ft_strlen(buf) - n + 1);
	while (buf[n] != 0)
		(*rest)[i++] = buf[n++];
}
