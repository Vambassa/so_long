/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:54:37 by vambassa          #+#    #+#             */
/*   Updated: 2022/01/28 12:33:47 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	exit(EXIT_SUCCESS);
}
