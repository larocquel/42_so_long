/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:35:52 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/09 22:43:37 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH	1280
# define HEIGHT	720

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
	void	*img;
	void	*addr;
	int		line_len;
	int		bits_per_pixel;
	int		endian;
	int		width;
	int		height;
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

}	t_game;

/* ************************************************************************** */
/*   PROTOTYPES                                                               */
/* ************************************************************************** */

// game_loop.c
int		game_loop(t_game *game);
void	update(t_game *game);

// utils.c
void	ft_pixelput(t_image *data, int x, int y, int color);
void	draw_texture(t_image *buffer, t_image *texture, int x, int y, int scale);

#endif
