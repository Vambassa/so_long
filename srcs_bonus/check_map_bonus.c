/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:54:37 by vambassa          #+#    #+#             */
/*   Updated: 2022/01/29 16:31:34 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	check_symbols_number(t_info *info)
{
	if (!info->coins)
		ft_print_error(NOT_ENOUGH_COINS);
	if (info->player_pos < 1)
		ft_print_error(NEED_START_POS);
	if (info->player_pos > 1)
		ft_print_error(MANY_START_POS);
	if (!info->exit)
		ft_print_error(NEED_EXIT);
}

static void	check_symbols_validity(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == '1' || info->map[i][j] == '0' \
					|| info->map[i][j] == 'Z')
				;
			else if (info->map[i][j] == 'C')
				info->coins += 1;
			else if (info->map[i][j] == 'E')
				info->exit += 1;
			else if (info->map[i][j] == 'P')
				info->player_pos += 1;
			else
				ft_print_error("Error: invalid symbols on the map");
			j++;
		}
		i++;
	}
}

static void	check_all_walls(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[0][i])
	{
		if (info->map[0][i] != '1')
			ft_print_error("Error: upper bound of the map must be 1");
		i++;
	}
	i = 0;
	while (info->map[info->map_height - 1][i])
	{
		if (info->map[info->map_height - 1][i] != '1')
			ft_print_error("Error: lower bound of the map must be 1");
		i++;
	}
	i = 1;
	while (i < info->map_height - 1)
	{
		if (info->map[i][0] != '1' || info->map[i][info->map_len - 1] != '1')
			ft_print_error("Error: side borders of the map must be 1");
		i++;
	}
}

static void	check_shape(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->map_height)
	{
		if ((int)ft_strlen(info->map[i]) != info->map_len)
			ft_print_error("Error: incorrect shape of the map");
		i++;
	}
}

void	check_map(t_info *info)
{
	info->map_len = (int)ft_strlen(info->map[0]);
	check_shape(info);
	check_all_walls(info);
	check_symbols_validity(info);
	check_symbols_number(info);
}
