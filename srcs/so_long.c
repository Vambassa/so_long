/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:54:37 by vambassa          #+#    #+#             */
/*   Updated: 2022/01/29 13:52:46 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_game(t_info *info)
{
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, info->map_len * TILE_SIZE, \
			info->map_height * TILE_SIZE, "Frozen Heart");
	render_map(info);
	mlx_key_hook(info->win_ptr, determine_action, info);
	mlx_hook(info->win_ptr, 17, 1L << 2, cross_key, info);
	mlx_loop(info->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		ft_print_error("Error: invalid number of arguments. Need 2");
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
		ft_print_error("Error: incorrect extension of the map. Need .ber");
	init_structure(&info);
	create_map(argv[1], &info);
	start_game(&info);
	return (0);
}
