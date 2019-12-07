/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampos- <jcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:39:34 by jcampos-          #+#    #+#             */
/*   Updated: 2019/12/07 15:44:45 by jcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main (int argc, char **argv)
{
    char    *line;
    int     fd;

    argc = 1;
    if (!(line = malloc(4096)))
        return (-1);
    fd = open(argv[1], O_RDONLY);
    printf("maincasiOK\n");
    while (get_next_line(fd, &line) > 0)
    {
        printf("READ:%d\n", argc);
        printf("%s\n", line);
        argc++;
    }
    return (0);
}