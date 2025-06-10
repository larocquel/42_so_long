/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:35:52 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/10 20:35:13 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH	1280
# define HEIGHT	720
# define SPEED	5
# define SCALE	5

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"

# include <stdbool.h>

/* ************************************************************************** */
/*   STRUCTS                                                                  */
/* ************************************************************************** */

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_player
{
	t_xy	pos;
	t_xy	dir;
} t_player;

typedef struct s_image
{
	void		*img;
	void		*addr;
	int			line_len;
	int			bits_per_pixel;
	int			endian;
	int			width;
	int			height;
} t_image;

typedef struct s_texture
{
	t_image	player;
	t_image	collectable;
	t_image	wall;
	t_image	floor;
	t_image	door_open;
	t_image	door_close;
}	t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_image		buffer;
	t_texture	texture;
	t_player	player;
}	t_game;

/* ************************************************************************** */
/*   PROTOTYPES                                                               */
/* ************************************************************************** */

// game_loop.c
void	update(t_game *game);
void	render(t_game *game);
int		game_loop(t_game *game);

// utils.c
int		close_game(t_game *game);
void	ft_pixelput(t_image *data, int x, int y, int color);
void	draw_texture(t_image *buffer, t_image *texture, int x, int y, int scale);

// input.c
int		key_handler(int keysym, t_game *game);

#endif
