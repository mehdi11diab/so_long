/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:08:21 by ediab             #+#    #+#             */
/*   Updated: 2022/12/19 20:08:23 by ediab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_putstr(char *s, int char_count)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (char_count + 6);
	}
	while (s[i])
	{
		write (1, &s[i], sizeof(char));
		i++;
	}
	char_count += i;
	return (char_count);
}
