/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:54:37 by vambassa          #+#    #+#             */
/*   Updated: 2022/01/29 13:47:05 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	change_enemy(t_info *info, void *img, int x, int y)
{
	info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, \
			img, &info->img_hei, &info->img_wid);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, \
			info->img_ptr, x * info->img_hei, y * info->img_wid);
}

int	animate_enemy(t_info *info)
{
	int	x;
	int	y;

	if (info->count_times == 60)
		info->count_times = 0;
	else
		info->count_times++;
	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (info->map[y][x] == 'Z' && info->count_times > 30)
				change_enemy(info, info->img_enemy1, x, y);
			else if (info->map[y][x] == 'Z' && info->count_times <= 30)
				change_enemy(info, info->img_enemy2, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	render_image(char c, t_info *info, int i, int j)
{
	if (c == '1')
		info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, info->img_wall, \
				&info->img_hei, &info->img_wid);
	else if (c == '0')
		info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, \
				info->img_background, &info->img_hei, &info->img_wid);
	else if (c == 'C')
		info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, info->img_coins, \
				&info->img_hei, &info->img_wid);
	else if (c == 'E')
	{
		if (info->coins)
			info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, \
					info->img_exit_closed, &info->img_hei, &info->img_wid);
		else
			info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, \
					info->img_exit_open, &info->img_hei, &info->img_wid);
	}
	else if (c == 'Z')
		info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, info->img_enemy1, \
				&info->img_hei, &info->img_wid);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, \
			j * info->img_hei, i * info->img_wid);
}

void	render_player_image(t_info *info, int i, int j)
{
	info->player_x = j;
	info->player_y = i;
	info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, info->img_player, \
			&info->img_hei, &info->img_wid);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, \
			j * info->img_hei, i * info->img_wid);
}

void	render_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'P')
				render_player_image(info, i, j);
			else
				render_image(info->map[i][j], info, i, j);
			j++;
		}
		i++;
	}	
}
