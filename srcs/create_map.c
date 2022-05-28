/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:54:37 by vambassa          #+#    #+#             */
/*   Updated: 2022/01/29 13:52:33 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	define_height(char *map, t_info *info)
{
	int		fd;
	int		rd;
	char	*res;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_print_error("Error: no such map in directory");
	rd = get_next_line(fd, &res);
	while (rd > 0)
	{
		info->map_height += 1;
		free(res);
		rd = get_next_line(fd, &res);
	}
	free(res);
	if (rd == -1)
		ft_print_error("Error: map parsing");
	close(fd);
}

static void	parse_map(char *map, t_info *info)
{
	int		fd;
	int		rd;
	int		i;
	char	*res;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_print_error("Error: no such map in directory");
	info->map = malloc(sizeof(char *) * (info->map_height + 1));
	if (!info->map)
		ft_print_error("Error: malloc failed");
	i = 0;
	while (i < info->map_height)
	{
		rd = get_next_line(fd, &res);
		if (rd == -1)
			ft_print_error("Error: map parsing");
		info->map[i] = ft_strdup(res);
		free(res);
		i++;
	}
	close(fd);
}

void	create_map(char *map, t_info *info)
{
	define_height(map, info);
	parse_map(map, info);
	check_map(info);
}
