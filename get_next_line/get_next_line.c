/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasser <yyasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:19:13 by yyasser           #+#    #+#             */
/*   Updated: 2024/11/18 15:03:32 by yyasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// Constuct a string until the \n
char	*read_until_next_line(int fd, char *buf, char *str)
{
	char	*s;
	int		i;

	i = 1;
	while (!ft_strchr(str, '\n') && i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
			if (i < 0)
			{
				free(buf);
				free(str);
				return (NULL);
			}
			if (i == 0)
			{
				free(buf);
				return (str);
			}	
			buf[i] = '\0';	
			s = str;
			str = ft_strjoin(str, buf);
			free(s);
	}
	free(buf);
	return (str);
}


char	*current_line(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = malloc(i + 1);
	if (!s)
        return (NULL);
	while (j < i)
	{
		s[j] = str[j];
		j++;
	}
	s[j] = '\0';

	return (s);
}

// Save the rest after \n
char	*save_the_rest(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
    if (str[i] == '\n')
		i++;
	if (!str[i])
        return (NULL);
	s = malloc(ft_strlen(str) - i + 1);
	if (!s)
		return (NULL);
	while (str[i]) {
        s[j] = str[i];
        j++;
        i++;
    }
	s[j] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str;
	char		*line;
	char		*new_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = read_until_next_line(fd, buf, str);
	if (!str)
		return (NULL);
	line = current_line(str);
	if(!line)
		return(free(str), str = NULL, NULL);
	new_str = save_the_rest(str);
	free(str);
	str = new_str;
	return (line);
}


int main(void)
{
	int fd = open("Shahine.txt", O_RDONLY);
	char *line;
	int i;

	i = 0;
	
	while(i != 1)
	{
		line = get_next_line(fd);
		if(line)
		{
			printf("%s", line);
			free(line);
		}
		if(!line)
			i = 1;
	}
}

// int main(void)
// {
// 	int fd = open("Shahine.txt", O_RDONLY);
	
// 	while(1)
// 	{
// 		printf("%s", get_next_line(fd));
// 	}
// }

