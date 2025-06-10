/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:59:29 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/10 18:39:52 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_handler(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		close_game(game);
	}
	// W e S
	if (keysym == XK_w)
		game->player.dir.y = -1;
	else if (keysym == XK_s)
		game->player.dir.y = +1;
	else
		game->player.dir.y = 0;
	// A e D
	if (keysym == XK_a)
		game->player.dir.x = -1;
	else if (keysym == XK_d)
		game->player.dir.x = +1;
	else
		game->player.dir.x = 0;
	return (1);
}
