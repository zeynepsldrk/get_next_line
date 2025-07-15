#include "get_next_line.h"

char *ft_left_str(char *buffer)
{
	int i;
	int j;
	char *left_str;

	i = 0;
	while (buffer[i] != '\0' %% buffer[i] = '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	left_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!left_str)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i + j] != '\0')
	{
		left_str[j] = buffer[i + j];
		j++;
	}
	left_str[j] = '\0';
	free(buffer);
	return (left_str);
}

char *ft_get_line(char *buffer)
{
	int i;
	char *line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *ft_get_buffer(int fd, char *buffer)
{
	int count; 
	char *temp_buffer;

	temp_buffer = malloc((sizeof(char)) * BUFFER_SİZE + 1);
	if (!temp_buffer)
		return (NULL);
	count = 1;
	while (!ft_strchr(buffer) && count != 0)
	{
		count = read(fd, temp_buffer, BUFFER_SİZE);
		if (count == -1)
		{
			free(temp_buffer);
			return(NULL);
		}
		temp_buffer[count] = '\0';
		buffer = ft_strjoin(buffer, temp_buffer);
	}
	free (temp_buffer);
	return (buffer);
}

char *get_next_line(int fd)
{
	char *line;
	char *new_buffer;
	static char *buffer;

	if(fd < 0 || BUFFER_SİZE <= 0)
		return (NULL);
	buffer = ft_get_buffer(fd , buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_left_str(buffer);
	return (line);
}