/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:10:13 by ediab             #+#    #+#             */
/*   Updated: 2022/12/25 15:41:32 by ediab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	checkborder(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->w)
	{
		if (map->map[0][i] != '1' || map->map[map->h - 1][i] != '1')
			ft_error("!! THE MAP IS NOT SUROUNDED BY WALLS !!");
		i++;
	}
	while (j < map->h)
	{
		if (map->map[j][0] != '1' || map->map[j][map->w - 1] != '1')
			ft_error("!! THE MAP IS NOT SUROUNDED BY WALLS !!");
		j++;
	}
}

void	numbercheck(t_map *map)
{
	int	i;
	int	j;
	int	pcount;

	j = 0;
	pcount = 0;
	while (j < map->h)
	{
		i = 0;
		while (map->map [j][i++])
		{
			if (map->map[j][i] == 'P' || map->map[j][i] == 'E')
				pcount++;
			if (map->map[j][i] == 'C')
				map->collect = map->collect + 1;
		}
		j++;
	}
	if (pcount != 2 || map->collect < 1)
		ft_error("!! INVALID MAP !!");
}

void	checkletters(t_map *map)
{
	int	j;
	int	i;

	j = 0;
	while (j < map->h)
	{
		i = 0;
		while (map->map[j][i])
		{
			if (map->map[j][i] != '0' && map->map[j][i] != '1' &&
		map->map[j][i] != 'E' && map->map[j][i] != 'C' &&
		map->map[j][i] != 'P')
				ft_error("!! THE MAP CONTAINS UNKNOWN CHARACTERS !!");
			i++;
		}
		j++;
	}
}

void	rectangular_map(t_map *map)
{
	int	j;
	int	i;

	j = 0;
	while (j < map->h)
	{
		i = 0;
		while (map->map[j][i])
			i++;
		if (i != map->w)
			ft_error("!! MAP IS NOT RECTENGULAR !!");
		j++;
	}
}

void	validmap(t_map *map)
{
	int		i;
	char	**r;
	char	**s;

	i = 0;
	if (map->h == 0 || map->w == 0)
		ft_error("!! NO MAP !!");
	checkletters(map);
	checkborder(map);
	numbercheck(map);
	rectangular_map(map);
	s = dupl(map->map, map->h);
	r = dupl(map->map, map->h);
	if (!flood_fill(r, (t_loca){map->w, map->h}, pos_player(map->map, *map))
	|| !flood_fill2(s, (t_loca){map->w, map->h}, pos_player(map->map, *map)))
		ft_error("!! CAN'T REACHE EVERYTHING !!");
	while (i <= map->h)
	{
		free(r[i]);
		free(s[i]);
		i++;
	}
	free(r);
	free(s);
}
