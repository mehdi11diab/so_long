/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:08:35 by ediab             #+#    #+#             */
/*   Updated: 2022/12/19 20:08:37 by ediab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_putnbr(int n, int char_count)
{
	if (n == -2147483648)
		char_count = ft_putstr("-2147483648", char_count);
	else if (n < 0)
	{
		ft_putchar('-', char_count);
		char_count = ft_putnbr(-n, char_count + 1);
	}
	else if (n >= 10)
	{
		char_count = ft_putnbr(n / 10, char_count);
		char_count = ft_putchar((n % 10 + 48), char_count);
	}
	else
		char_count = ft_putchar((48 + n), char_count);
	return (char_count);
}
