/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:33:09 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/10 20:15:13 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Hello, World!");
	if (!game.win)
		return (free(game.mlx), 1);

	// Criar Imagem com Buffer
	game.buffer.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	game.buffer.addr = mlx_get_data_addr(game.buffer.img, &game.buffer.bits_per_pixel, &game.buffer.line_len, &game.buffer.endian);

	// Carregar textura
	game.texture.player.img = mlx_xpm_file_to_image(game.mlx, "textures/bonequinho.xpm", &game.texture.player.width, &game.texture.player.height);
	game.texture.player.addr = mlx_get_data_addr(game.texture.player.img, &game.texture.player.bits_per_pixel, &game.texture.player.line_len, &game.texture.player.endian);

	// Inicializa a posicao do player
	game.player.pos.x = WIDTH / 2;
	game.player.pos.y = HEIGHT / 2;
	game.player.dir.x = 0;
	game.player.dir.y = 0;

	// Loop Principal
	mlx_loop_hook(game.mlx, game_loop, &game);

	// Key hook loop
	mlx_key_hook(game.win, key_handler, &game);

	// Loop
	mlx_loop(game.mlx);
}
