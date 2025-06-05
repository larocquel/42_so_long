/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:44:44 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/05 20:56:15 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Error -> Usage: ./so_long <map.ber>\n");
		exit(1);
	}
	if (!read_map(av[1], &game))
	{
		ft_printf("Error -> Reading map failed\n");
		exit(1);
	}
	if (!validate_map(&game))
	{
		free_map(game.map, game.height);
		exit(1);
	}

	// Continuar com a inicializacao grafica do jogo
	// ...
	return (0);
}
