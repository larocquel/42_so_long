/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:46:23 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/05 21:19:28 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	while(read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count + 1);
}

int	read_map(char *file, t_game *game)
{
	int		i;
	char	*line;
	size_t	len;
	FILE	*f;

	game->height = count_lines(file);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return (0);
	f = fopen(file, "r");
	if (!f)
		return (0);
	i = 0;
	line = NULL;
	len = 0;
	while (i < game->height && getline(&line, &len, f) != -1)
	{
		game->map[i] = ft_strdup(line);
		if (game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
			game->map[i][ft_strlen(game->map[i]) - 1] = '\0';
		i++;
	}
	game->map[i] = NULL;
	fclose(f);
	return (free(line), 1);
}
int	validate_map(t_game *game)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	i = 0;
	while(i < game->height)
	{
		if ((int)ft_strlen(game->map[i] != game ->width))
			return (ft_printf("Error -> Non-rectangular map\n"), 0);
		j = 0;
		while(j < game->width)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->map[i][j] != 'C' && game->map[i][j] != 'E' && game->map[i][j] != 'P')
				return (ft_printf("Error -> Map has a invalid char\n"), 0);
			if ((i == 0 || i == game->height - 1 || j == 0 || j == game->width - 1))
				return (ft_printf("Error -> Map must be surrounded by walls\n"), 0);
			if (game->map[i][j] == 'P')
				p++;
			if (game->map[i][j] == 'E')
				e++;
			if (game->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || c < 1)
		return (ft_printf("Error -> Map must contain 1 P, 1 E and at least 1 C\n"), 0);
	game->collectibles = c;
	return (1);
}

void	free_map(char **map, int height)
{
	int i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}
