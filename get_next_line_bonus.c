/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampos- <jcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:50:30 by jcampos-          #+#    #+#             */
/*   Updated: 2019/12/07 16:09:26 by jcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     manage_ret(const int fd, char **file, char **line)
{
    int     j;
    char    *acc;

    j = 0;
    while (file[fd] && (file[fd][j] != '\n' && file[fd][j] != '\0'))
        j++;
    if (file[fd][j] == '\n')
    {
        *line = ft_substr(file[fd], 0, j);
        acc = ft_strdup(file[fd] + j + 1);
        free(file[fd]);
        file[fd] = acc;
        return (1);
    }
    if (file[fd][j] == '\0')
    {
        *line = ft_strdup(file[fd]);
        free(file[fd]);
        file[fd] = NULL;
        return (0);
    }
    return (1);
}

int     get_next_line(const int fd, char **line)
{
    char        buff[BUFF_SIZE + 1];
    int         ret;
    char        *acc;
    static char *file[4096];

    if ((fd < 0 || line == NULL) || BUFF_SIZE < 1)
        return (-1);
    while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
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
    if (ret == -1)
        return (-1);
    return (manage_ret(fd, file, line));
}