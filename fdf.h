/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 21:47:21 by lnagy             #+#    #+#             */
/*   Updated: 2016/04/27 21:47:29 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define KeyPress 2
# define KeyRelease 3
# define KeyPressMask (1L<<0)
# define KeyReleaseMask (1L<<1)
# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "X.h"

typedef struct	s_pt
{
	int			x;
	int			y;
	int			z;
}				t_pt;
typedef struct	s_env
{
	void		*mlx;
	void		*win;

	int			len;
	int			**map;
	int			size;

	double	z;
	int			o_z;
	int			o_x;
	int			o_y;
	double		zoom;

	char			zoomio;
	char			ud;
	char			mv;
}				t_env;
typedef enum	e_key
{
	LEFT = 123,
	RIGHT = 124,
	UP = 125,
	DOWN = 126,
	NUM_4 = 88,
	NUM_6 = 86,
	NUM_8 = 91,
	NUM_2 = 84,
	NUM_0 = 82,
	PLUS = 69,
	MINUS = 78,
	MULT = 67,
	DIV = 75,
	ENTER = 76,
	ESC = 53,
}				t_key;

void			do_key(t_env *env);
void			do_mlx(t_env *env);
void			put_line(t_env *env, int x1, int y1, int x2, int y2, int z1);
void			do_map(t_env *env);
int				*line_to_itab(char *line, t_env *env);
int				**create_map(int *itab, t_env *env);
void			print_tab(t_env *env);

#endif
