/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampos- <jcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:28:46 by jcampos-          #+#    #+#             */
/*   Updated: 2019/12/07 13:49:15 by jcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;

	len = ft_strlen(s1);
	if (!(dup = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (*s1)
	{
		*dup = *s1;
		dup++;
		s1++;
	}
	*dup = '\0';
	dup = dup - len;
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*ns;
	unsigned int	i;
	unsigned int	j;
	unsigned int	l;

	if (!s1 || !s2)
		return (0);
	j = ft_strlen(s2);
	l = 0;
	i = ft_strlen(s1);
	if (!(ns = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (0);
	while (l < i)
	{
		ns[l] = s1[l];
		l++;
	}
	i = 0;
	while (i < j)
	{
		ns[l] = s2[i];
		l++;
		i++;
	}
	ns[l] = '\0';
	return (ns);
}

char	*ft_strchr(const char *s, int c)
{
	c = (char)c;
	while (*s != c && *s)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(substring = (char *)malloc(len + 1 * sizeof(char))))
		return (0);
	if (!(start > (unsigned int)ft_strlen(s)))
	{
		while (s[start] && i < len)
		{
			*substring = s[start];
			start++;
			substring++;
			i++;
		}
	}
	*substring = '\0';
	substring = substring - i;
	return (substring);
}

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
