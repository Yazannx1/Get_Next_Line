/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasser <yyasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:19:16 by yyasser           #+#    #+#             */
/*   Updated: 2024/10/30 04:37:45 by yyasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
char *ft_strjoin(char *s1, char *s2)
{
    char *s;
    char *str;

    if (!s1 && !s2)
        return (NULL);
    else if (!s1)
        return strdup(s2);
    else if (!s2)
        return strdup(s1);

    s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (s == NULL)
        return (NULL);

    str = s;
    while (*s1)
        *str++ = *s1++;
    while (*s2)
        *str++ = *s2++;
    *str = '\0';
    return (s);  // Correctly return the start of the allocated memory
}


// char	*new_temp(void)
// {
// 	char	*s;

// 	s = malloc(1);
// 	if (!s)
// 		return (NULL);
// 	*s = '\0';
// 	return (s);
// }

char	*ft_strdup(char *s)
{
	int		ft_strlen;
	int		i;
	char	*duplicate;

	i = 0;
	ft_strlen = 0;
	while (s[ft_strlen])
		ft_strlen++;
	duplicate = (char *)malloc(ft_strlen + 1);
	if (duplicate == NULL)
		return (NULL);
	while (s[i])
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		// printf("%c\n", s[i]);
		if (s[i] == c)
			return (1);
		i++;
	}
		// if(s[i] == '\0')
		// {
		// 	printf("WE ARE IN THE NULL");
		// }
	
	return (0);
}

// int main()
// {
// 	char *str = " Moammed alfakih";
// 	char c = 'h';

// 	ft_strchr(str, c);
// }
