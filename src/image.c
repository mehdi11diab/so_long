/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:09:15 by ediab             #+#    #+#             */
/*   Updated: 2022/12/25 15:38:13 by ediab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	check_path(char *path, t_map *map, t_img *img)
{
	int	x;
	int	y;

	x = 100;
	y = 100;
	img->ni = mlx_xpm_file_to_image (map->mlx.mp, path, &x, &y);
	if (!img->ni)
		ft_error("INVALID IMMG");
}

void	imgtowin(t_img img, t_loca l, t_map *map, char c)
{
	if (c == '1' || c == 'C' || c == 'E')
	{
		if (c == '1')
			check_path(img.wall, map, &img);
		if (c == 'C')
			check_path(img.collect, map, &img);
		if (c == 'E')
			check_path(img.exit, map, &img);
		mlx_put_image_to_window (map->mlx.mp, map->mlx.wp, img.ni, l.x, l.y);
	}
	else if (c == 'P')
	{
		check_path(map->player, map, &img);
		mlx_put_image_to_window (map->mlx.mp, map->mlx.wp, img.ni, l.x, l.y);
		map->np = img.ni;
		map->x = l.x;
		map->y = l.y;
	}
}

void	imgletters(t_map *map, t_img img)
{
	int		j;
	int		i;
	char	*message;

	map->x = 0;
	map->y = 0;
	j = 0;
	message = "MOUVES : ";
	while (map->h > j)
	{
		i = 0;
		while (map->map [j][i])
		{
			if (map->map[j][i] != '0')
				imgtowin(img, (t_loca){i * 100, j * 100}, map, map->map[j][i]);
			i++;
		}
		j++;
	}
	mlx_string_put(map->mlx.mp, map->mlx.wp, 5, 10, 0x061272, message);
}

void	setimg(t_img *img, t_map *map)
{
	img->collect = "img/snow.xpm";
	img->exit = "img/cha.xpm";
	img->wall = "img/walll.xpm";
	map->player = "img/GOT.xpm";
	imgletters(map, *img);
}
