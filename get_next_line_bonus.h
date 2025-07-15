#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);
char *ft_get_buffer(int fd, char *buffer);
char *ft_get_line(char *buffer);
char *ft_left_str(char *buffer);
size_t ft_strlen(char *str);
int ft_strchr(char *str);
char *ft_strjoin(char *buffer, char *temp);

#endif