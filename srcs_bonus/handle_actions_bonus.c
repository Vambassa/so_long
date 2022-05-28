/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:54:37 by vambassa          #+#    #+#             */
/*   Updated: 2022/01/29 13:35:34 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	open_exit(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'E')
				render_image('E', info, i, j);
			j++;
		}
		i++;
	}
}

static void	move_free(t_info *info, int x, int y)
{
	info->map[info->player_y][info->player_x] = '0';
	render_image('0', info, info->player_y, info->player_x);
	info->map[info->player_y + y][info->player_x + x] = 'P';
	render_player_image(info, info->player_y + y, info->player_x + x);
	info->moves++;
	print_moves_window(info);
}

static void	make_move(t_info *info, int x, int y)
{
	if (info->map[info->player_y + y][info->player_x + x] != '1')
	{
		if (info->map[info->player_y + y][info->player_x + x] == 'E' \
				&& info->is_exit_open)
			stop_game(info, 'W');
		else if (info->map[info->player_y + y][info->player_x + x] == 'Z')
			stop_game(info, 'F');
		else if (info->map[info->player_y + y][info->player_x + x] == 'C')
		{
			move_free(info, x, y);
			info->coins -= 1;
			if (!info->coins)
			{
				info->is_exit_open = 1;
				open_exit(info);
			}
		}
		else if (info->map[info->player_y + y][info->player_x + x] == '0')
			move_free(info, x, y);
	}
}

int	determine_action(int key_code, t_info *info)
{
	if (key_code == KEY_A)
		make_move(info, -1, 0);
	else if (key_code == KEY_W)
		make_move(info, 0, -1);
	else if (key_code == KEY_D)
		make_move(info, 1, 0);
	else if (key_code == KEY_S)
		make_move(info, 0, 1);
	else if (key_code == KEY_ESC)
		stop_game(info, 'E');
	return (0);
}
