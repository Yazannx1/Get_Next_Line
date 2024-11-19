#include "get_next_line_bonus.h"

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
	static char	*str[1025];
	char		*line;
	char		*new_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX || fd > 1025)
		return (NULL);
	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str[fd] = read_until_next_line(fd, buf, str[fd]);
	if (!str[fd])
		return (NULL);
	line = current_line(str[fd]);
	if(!line)
		return(free(str[fd]), str[fd] = NULL, NULL);
	new_str = save_the_rest(str[fd]);
	free(str[fd]);
	str[fd] = new_str;
	return (line);
}
int main(void)
{
	//shahine has friends
	int fd1 = open("Shahine.txt", O_RDONLY);
	int fd2 = open("dablow.txt", O_RDONLY);
	int fd3 = open("yazan.txt", O_RDONLY);

	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd2));
}

// int main()
// {
    
// }