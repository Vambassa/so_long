/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:54:37 by vambassa          #+#    #+#             */
/*   Updated: 2022/01/28 12:31:04 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
