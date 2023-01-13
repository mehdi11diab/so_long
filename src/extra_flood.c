/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_flood.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:20:52 by ediab             #+#    #+#             */
/*   Updated: 2022/12/21 23:21:00 by ediab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/so_long.h"

void	fill2(char **tab, t_loca dm, t_loca pp)
{
	if (pp.y < 0 || pp.x < 0 || pp.y >= dm.y || pp.x >= dm.x
		|| (tab[pp.y][pp.x] != 'C'
		&& tab[pp.y][pp.x] != 'P'
		&& tab[pp.y][pp.x] != '0'))
		return ;
	tab[pp.y][pp.x] = 'G';
	fill2(tab, dm, (t_loca){pp.x - 1, pp.y});
	fill2(tab, dm, (t_loca){pp.x + 1, pp.y});
	fill2(tab, dm, (t_loca){pp.x, pp.y - 1});
	fill2(tab, dm, (t_loca){pp.x, pp.y + 1});
}

int	check2(char **s, t_loca size)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (size.y > j)
	{
		while (size.x > i)
		{
			if (s[j][i] == 'C' || s[j][i] == 'P')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	flood_fill2(char **tab, t_loca size, t_loca begin)
{
	fill2(tab, size, begin);
	check2(tab, size);
	return (check2(tab, size));
}
