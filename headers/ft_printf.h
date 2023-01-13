/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:54:58 by ediab             #+#    #+#             */
/*   Updated: 2022/12/18 21:55:36 by ediab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		main(int argc, char *argv[]);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c, int char_count);
int		ft_putstr(char *s, int char_count);
int		ft_putnbr(int n, int char_count);

#endif
