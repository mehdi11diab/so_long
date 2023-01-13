/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:09:38 by ediab             #+#    #+#             */
/*   Updated: 2022/12/19 20:09:41 by ediab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	setmap(t_map *map)
{
	map->h = 1;
	map->w = 0;
	map->collect = 0;
	map->c = 0;
	map->exit = 0;
}

void	getwidth(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i])
		i++;
	map->w = i;
}

void	putgnl(int fd, t_map *map)
{
	setmap(map);
	map->result = ft_strdup("");
	map->str = get_next_line(fd);
	if (map->str == NULL)
		ft_error("!! INVALID PATH OR THE MAP IS EMPTY !!");
	while (1)
	{
		map->tmp = map->result;
		if (map->str[0] == '\n')
			ft_error("!! THERE IS A NEW LINE IN THE MAP !!");
		if (map->str)
			map->result = ft_strjoin(map->result, map->str);
		free(map->tmp);
		free(map->str);
		map->str = get_next_line(fd);
		if (!map->str)
			break ;
		map->h++;
	}
	map->map = ft_split(map->result, '\n');
	getwidth(map);
	free(map->result);
}
