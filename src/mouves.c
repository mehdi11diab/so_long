/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:09:49 by ediab             #+#    #+#             */
/*   Updated: 2022/12/25 15:40:02 by ediab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	moves(t_map *map)
{
	int		x;
	int		y;
	void	*newimg;
	char	*moves;

	x = 100;
	y = 100;
	newimg = mlx_xpm_file_to_image(map->mlx.mp, "img/walll.xpm", &x, &y);
	mlx_put_image_to_window(map->mlx.mp, map->mlx.wp, newimg, 100, 0);
	map->c = map->c + 1;
	moves = ft_itoa(map->c);
	mlx_string_put(map->mlx.mp, map->mlx.wp, 102, 10, 0x061272, moves);
	ft_printf("MOUVES : %d \n", map->c);
	free(moves);
}

void	moveplayer(t_map *map, int mx, int my)
{
	int	x;
	int	y;

	x = 100;
	y = 100;
	mlx_destroy_image(map->mlx.mp, map->np);
	map->np = mlx_new_image(map->mlx.mp, x, y);
	mlx_put_image_to_window(map->mlx.mp, map->mlx.wp, map->np, mx, my);
	map->np = mlx_xpm_file_to_image(map->mlx.mp, map->player, &x, &y);
	mlx_put_image_to_window(map->mlx.mp, map->mlx.wp, map->np, map->x, map->y);
	moves(map);
}

void	poss_move(t_map *map, int mapx, int mapy)
{
	int	i;
	int	j;

	i = map->x / 100;
	j = map->y / 100;
	if (map->map[j][i] != '1' && map->map[j][i] != 'C' && map->map[j][i] != 'E')
		moveplayer(map, mapx, mapy);
	else if (map->map[j][i] == 'C')
	{
		moveplayer(map, mapx, mapy);
		map->exit = map->exit + 1;
		map->map[j][i] = '0';
	}
	else if (map->map[j][i] == 'E' && map->exit == map->collect)
		exit(0);
	else
	{
		map->x = mapx;
		map->y = mapy;
	}
}

int	key_press(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_S)
	{
		map->y = map->y + 100;
		poss_move(map, map->x, map->y - 100);
	}
	if (keycode == KEY_A)
	{
		map->x = map->x - 100;
		poss_move(map, map->x + 100, map->y);
	}
	if (keycode == KEY_W)
	{
		map->y = map->y - 100;
		poss_move(map, map->x, map->y + 100);
	}
	if (keycode == KEY_D)
	{
		map->x = map->x + 100;
		poss_move(map, map->x - 100, map->y);
	}
	return (0);
}
