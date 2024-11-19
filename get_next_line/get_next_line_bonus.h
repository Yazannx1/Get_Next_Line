
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 11
#endif

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
int	    ft_strchr(char *s, char c);
char	*get_next_line(int fd);
char	*read_until_next_line(int fd, char *buf, char *str);
char	*current_line(char *str);
char	*save_the_rest(char *str);

#endif