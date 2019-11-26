/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampos- <juancampos2610@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:43:07 by jcampos-          #+#    #+#             */
/*   Updated: 2019/11/26 15:44:24 by jcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*copy_save(char **file, int fd)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	while (file[fd][i] != '\n')
		i++;
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = -1;
	while (file[fd][++i] != '\n')
		str[i] = file[fd][i];
	str[i] = '\0';
	temp = ft_strdup(file[fd] + i + 1);
	free(file[fd]);
	file[fd] = temp;
	return (str);
}

int		make_line(char **file, int fd, char **line)
{
	if (ft_strchr(file[fd], '\n'))
	{
		*line = copy_save(file, fd);
		return (1);
	}
	else
	{
		*line = ft_strdup(file[fd]);
		free(file[fd]);
		file[fd] = NULL;
		return (0);
	}
}

int		handle_ret(int ret, char **file, char **line, int fd)
{
	if (ret == -1)
		return (-1);
	if (ret == 0 && (file[fd] == NULL || file[fd][0] == '\0'))
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (make_line(file, fd, line));
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*acc;
	static char	*file[4096];

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	while (((ret = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[ret] = '\0';
		if (file[fd] == NULL)
			file[fd] = ft_strdup("");
		acc = ft_strjoin(file[fd], buff);
		free(file[fd]);
		file[fd] = acc;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (handle_ret(ret, file, line, fd));
}
