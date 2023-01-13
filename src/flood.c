/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:06:56 by ediab             #+#    #+#             */
/*   Updated: 2022/12/22 18:21:08 by ediab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	fill(char **tab, t_loca dm, t_loca pp)
{
	if (pp.y < 0 || pp.x < 0 || pp.y >= dm.y || pp.x >= dm.x
		|| (tab[pp.y][pp.x] != 'C'
		&& tab[pp.y][pp.x] != 'P'
		&& tab[pp.y][pp.x] != '0'
		&& tab[pp.y][pp.x] != 'E'))
		return ;
	tab[pp.y][pp.x] = 'F';
	fill(tab, dm, (t_loca){pp.x - 1, pp.y});
	fill(tab, dm, (t_loca){pp.x + 1, pp.y});
	fill(tab, dm, (t_loca){pp.x, pp.y - 1});
	fill(tab, dm, (t_loca){pp.x, pp.y + 1});
}

int	check(char **s, t_loca size)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (size.y > j)
	{
		while (size.x > i)
		{
			if (s[j][i] == 'C' || s[j][i] == 'P' || s[j][i] == 'E')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

t_loca	pos_player(char **s, t_map map)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (map.h > j)
	{
		while (map.w > i)
		{
			if (s[j][i] == 'P')
				return ((t_loca){i, j});
			i++;
		}
		i = 0;
		j++;
	}
	return ((t_loca){0, 0});
}

char	**dupl(char **t, int k)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	j = 0;
	s = malloc(sizeof(char *) * (k + 1));
	while (i < k)
		s[i++] = ft_strdup(t[j++]);
	s[i] = NULL;
	return (s);
}

int	flood_fill(char **tab, t_loca size, t_loca begin)
{
	fill(tab, size, begin);
	check(tab, size);
	return (check(tab, size));
}
