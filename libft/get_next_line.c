/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:54:37 by vambassa          #+#    #+#             */
/*   Updated: 2022/01/28 12:10:51 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(int fd, char **line)
{
	int		rd;
	int		i;
	char	*buffer;

	i = 0;
	buffer = (char *)malloc(100000);
	*line = buffer;
	rd = read(fd, &buffer[i], 1);
	while (rd > 0 && buffer[i] != '\n')
	{
		i++;
		rd = read(fd, &buffer[i], 1);
	}
	buffer[i] = '\0';
	return (rd);
}
