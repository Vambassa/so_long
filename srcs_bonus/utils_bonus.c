/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:54:37 by vambassa          #+#    #+#             */
/*   Updated: 2022/01/29 13:51:50 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	cross_key(t_info *info)
{
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	ft_putendl_fd("You have closed the game. Come back!!!", 1);
	exit(EXIT_SUCCESS);
}

void	stop_game(t_info *info, char type)
{
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	if (type == 'E')
		ft_putendl_fd("You have closed the game. Come back!!!", 1);
	else if (type == 'W')
		ft_putendl_fd("You won! Hooray!", 1);
	else if (type == 'F')
		ft_putendl_fd("You have been eaten by enemies. What a pity!!!", 1);
	exit(EXIT_SUCCESS);
}

void	print_moves_window(t_info *info)
{
	char	*moves;

	moves = ft_itoa(info->moves);
	render_image('1', info, 0, 0);
	render_image('1', info, 0, 1);
	render_image('1', info, 0, 2);
	mlx_string_put(info->mlx_ptr, info->win_ptr, 30, 20, 0x00008b, \
			"Movements:  ");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 140, 20, 0x00008b, moves);
}
