/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:02:12 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/10 20:36:31 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Update: Mexe com toda logica antes de colocar as coisas na tela
void	update(t_game *game)
{
	game->player.pos.x += game->player.dir.x * SPEED;
	game->player.pos.y += game->player.dir.y * SPEED;

	// Rebater as bordas da tela

	if (game->player.pos.x < 0)
		game->player.pos.x = 0;
	if (game->player.pos.y < 0)
		game->player.pos.y = 0;
	if (game->player.pos.x >= WIDTH - (game->texture.player.width * SCALE))
		game->player.pos.x = WIDTH - (game->texture.player.width * SCALE);
	if (game->player.pos.y >= HEIGHT - (game->texture.player.height * SCALE))
		game->player.pos.y = HEIGHT - (game->texture.player.height * SCALE);
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
	draw_texture(&game->buffer, &game->texture.player, game->player.pos.x, game->player.pos.y, SCALE);
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

