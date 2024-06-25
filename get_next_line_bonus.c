/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:14:43 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/06/14 18:21:55 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *line)
{
	char	*new_line;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	new_line = (char *)ft_calloc((i + 1), sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*new_line(char *line)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	new_line = ft_calloc((ft_strlen(line) - i + 1), sizeof(char));
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		new_line[j++] = line[i++];
	new_line[j] = '\0';
	free(line);
	return (new_line);
}

char	*read_update(int fd, char *line)
{
	char	*buffer;
	int		cnt;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	cnt = 1;
	while (cnt != 0)
	{
		cnt = read(fd, buffer, BUFFER_SIZE);
		if (cnt < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[cnt] = '\0';
		if (!line)
			line = ft_strdup("");
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free (buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[4096];
	char		*rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line[fd])
		line[fd] = ft_strdup("");
	line[fd] = read_update(fd, line[fd]);
	if (line[fd] == NULL || line[fd][0] == '\0')
		return (free(line[fd], line = NULL, NULL);
	rd = get_line(line[fd]);
	line[fd] = new_line(line[fd]);
	return (rd);
}

/* int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */
