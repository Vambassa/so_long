/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:54:37 by vambassa          #+#    #+#             */
/*   Updated: 2022/01/29 13:36:35 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static char	*assign_image(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_print_error("Error: no such image in directory");
	return (path);
}

static void	open_sprites_images(t_info *info)
{
	info->img_player = assign_image("./imgs/elza.xpm");
	info->img_background = assign_image("./imgs/ice_background.xpm");
	info->img_wall = assign_image("./imgs/ice_border.xpm");
	info->img_coins = assign_image("./imgs/olaf.xpm");
	info->img_exit_closed = assign_image("./imgs/anna.xpm");
	info->img_exit_open = assign_image("./imgs/anna_elza.xpm");
	info->img_enemy1 = assign_image("./imgs/enemy1.xpm");
	info->img_enemy2 = assign_image("./imgs/enemy2.xpm");
}

void	init_structure(t_info *info)
{
	info->map_len = 0;
	info->map_height = 0;
	info->coins = 0;
	info->player_pos = 0;
	info->exit = 0;
	info->is_exit_open = 0;
	info->moves = 0;
	info->img_hei = TILE_SIZE;
	info->img_wid = TILE_SIZE;
	info->count_times = 0;
	open_sprites_images(info);
}
