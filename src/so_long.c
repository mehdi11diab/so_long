/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:15:58 by ediab             #+#    #+#             */
/*   Updated: 2022/12/23 00:32:25 by ediab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_exit(t_map *map)
{
	free(map->map);
	exit(1);
}

void	ft_error(char *message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	exit(1);
}

void	*my_strtrim(char const *s1, char const *set)
{
	size_t	size_s1;
	int		k;
	char	*b;

	k = 0;
	b = "";
	if (!s1 || !set)
		return (NULL);
	size_s1 = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[size_s1]) && size_s1 != 0)
	{
		k = *set - s1[size_s1];
		size_s1--;
	}
	if (k != 0)
		ft_error("!! INVALID PATH !!");
	return (b);
}

void	so_long(char *filename)
{
	int		fd;
	t_map	map;
	t_img	img;
	char	*path;
	char	*so;

	so = "so_long";
	path = ft_strjoin("maps/", filename);
	fd = open(path, O_RDONLY);
	my_strtrim(filename, ".ber");
	putgnl(fd, &map);
	validmap(&map);
	map.mlx.mp = mlx_init();
	map.mlx.wp = mlx_new_window(map.mlx.mp, map.w * 100, map.h * 100, so);
	setimg(&img, &map);
	system("leaks o_long");
	mlx_key_hook(map.mlx.wp, key_press, &map);
	mlx_hook(map.mlx.wp, 17, 0, ft_exit, &map);
	mlx_loop(map.mlx.mp);
	free(map.map);
	free(&map);
	close(fd);
}
