/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:49:53 by ediab             #+#    #+#             */
/*   Updated: 2022/12/22 00:19:43 by ediab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_loca
{
	int	x;
	int	y;
}			t_loca;

typedef struct s_img
{
	void	*ni;
	char	*player;
	char	*collect;
	char	*exit;
	char	*wall;
}				t_img;

typedef struct s_mlx
{
	void	*mp;
	void	*wp;
}				t_mlx;

typedef struct s_map
{
	struct s_mlx	mlx;
	void			*player;
	void			*np;
	char			**map;
	int				x;
	int				y;
	int				w;
	int				h;
	int				c;
	int				collect;
	int				exit;
	char			*str;
	char			*result;
	char			*tmp;
}					t_map;

# define X_EVENT_KEY_PRESS 2
# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

int		main(int argc, char *argv[]);
void	so_long(char *filename);
void	putgnl(int fd, t_map *map);
int		key_press(int keycode, t_map *map);
void	validmap(t_map *map);
void	ft_error(char *message);
char	**ft_split(char const *s, char c);
void	setimg(t_img *img, t_map *map);
char	*ft_itoa(int n);
int		flood_fill(char **tab, t_loca size, t_loca begin);
int		flood_fill2(char **tab, t_loca size, t_loca begin);
t_loca	pos_player(char **s, t_map map);
char	**dupl(char **t, int k);
void	special_flood(char **cp, t_map *map);
void	imgletters(t_map *map, t_img img);
void	*my_strtrim(char const *s1, char const *set);

#endif
