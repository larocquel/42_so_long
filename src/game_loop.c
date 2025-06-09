/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:02:12 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/09 22:43:48 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Update: Mexe com toda logica antes de colocar as coisas na tela
void	update(t_game *game)
{
	(void) game;
}

// Render: Coloca as porra toda na tela
void	render(t_game *game)
{
	// Reseta a tela para cor que eu quiser
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			ft_pixelput(&game->buffer, i, j, 0XFFFFFF);
		}
	}

	// Coloca o player na tela
	draw_texture(&game->buffer, &game->texture.player, WIDTH/2, HEIGHT/2, 5);
	mlx_put_image_to_window(game->mlx, game->win, game->buffer.img, 0, 0);
	return ;
}

// game_loop() que chama update() e render()
int	game_loop(t_game *game)
{
	update(game);
	render(game);
	return (0);
}

