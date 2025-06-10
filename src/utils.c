/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:31:22 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/10 18:34:34 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_display(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	ft_printf("Game Closed!\n");
	return (0);
}

void	ft_pixelput(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
void	draw_texture(t_image *buffer, t_image *texture, int x, int y, int scale)
{
	unsigned int	color;
	int				i;
	int				j;

	color = 0XFFFFFF;
	i = 0;
	while(i < texture->height * scale)
	{
		j = 0;
		while(j < texture->width * scale)
		{
			color = *((int *)(texture->addr + ((i / scale) * texture->line_len + (j / scale) * (texture->bits_per_pixel / 8))));
			if (color == 0XFF000000)
			{
				j++;
				continue ;
			}
			ft_pixelput(buffer, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
