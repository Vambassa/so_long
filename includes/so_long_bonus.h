/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:54:37 by vambassa          #+#    #+#             */
/*   Updated: 2022/01/29 15:48:36 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define TILE_SIZE 64

# define NOT_ENOUGH_COINS "Error: need at least 1 collectible on the map"
# define NEED_START_POS "Error: need at least 1 player's position on the map"
# define MANY_START_POS "Error: need only 1 player's position on the map"
# define NEED_EXIT "Error: need at least 1 exit on the map"

typedef struct s_info
{
	char	**map;
	int		map_len;
	int		map_height;
	int		coins;
	int		player_pos;
	int		exit;
	int		is_exit_open;
	int		img_hei;
	int		img_wid;
	int		moves;
	int		player_x;
	int		player_y;
	int		count_times;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_player;
	void	*img_background;
	void	*img_wall;
	void	*img_coins;
	void	*img_exit_closed;
	void	*img_exit_open;
	void	*img_enemy1;
	void	*img_enemy2;
}	t_info;

void	start_game(t_info *info);
void	check_map(t_info *info);
void	create_map(char *map, t_info *info);
int		determine_action(int key_code, t_info *info);
void	init_structure(t_info *info);
void	render_map(t_info *info);
void	render_image(char c, t_info *info, int i, int j);
int		cross_key(t_info *info);
void	stop_game(t_info *info, char type);
void	render_player_image(t_info *info, int i, int j);
void	print_moves_window(t_info *info);
int		animate_enemy(t_info *info);

#endif
