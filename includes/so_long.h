/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:35:52 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/07 17:05:09 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH	500
# define HEIGHT	500

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"

# include <stdbool.h>

/* ************************************************************************** */
/*   STRUCTS                                                                  */
/* ************************************************************************** */

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_image
{
	void	*player;
	void	*collectable;
	void	*wall;
	void	*floor;
	void	*door_open;
	void	*door_close;
}	t_images;

typedef struct s_game
{
	int			fd;
	char		**map;
	char		**map_copy;
	int			map_height;
	int			map_width;
	int			players_c;
	int			exit_c;
	int			collectables_c;
	int			reachable_c;
	int			reachable_e;
	bool		exit_access;
	bool		start;
	bool		door_open;
	bool		exit_found;
	int			moves_c;
	t_position	player_pos;
	t_position	exit_pos;
	t_position	*collectable_pos;
	void		*mlx;
	void		*win;
	t_images	img;
}	t_game;

#endif
