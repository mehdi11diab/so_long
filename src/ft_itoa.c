/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:07:45 by ediab             #+#    #+#             */
/*   Updated: 2022/12/19 20:07:47 by ediab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*ft_tableau(unsigned int n, char *c, int len)
{
	while (n > 0)
	{
		c[len] = 48 + (n % 10);
		n = n / 10;
		len--;
	}
	return (c);
}

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*c;
	int				len;
	unsigned int	number;
	char			sign;

	len = ft_len(n);
	c = (char *)malloc(len * sizeof(char) + 1);
	if (!c)
		return (NULL);
	if (n == 0)
	{
		c[0] = 48;
	}
	c[len--] = '\0';
	if (n < 0)
	{
		sign = -1;
		number = n * -1;
		c[0] = '-';
	}
	else
		number = n;
	c = ft_tableau(number, c, len);
	return (c);
}
