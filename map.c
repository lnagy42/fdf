/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:32:38 by lnagy             #+#    #+#             */
/*   Updated: 2016/04/26 17:32:47 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	do_map(t_env *env)
{
	t_pt co;
	t_pt w_coord;

	w_coord.x = env->o_x;
	co.x = 0;
	while (co.x < env->size)
	{
		co.y = 0;
		w_coord.y = env->o_y;
		while (co.y < env->len )
		{
			if (co.x != env->size - 1)
				put_line(env, w_coord.x, w_coord.y, w_coord.x - env->zoom, w_coord.y, env->map[co.x][co.y]);
			if (co.y != env->len - 1)
				put_line(env, w_coord.x, w_coord.y, w_coord.x, w_coord.y + env->zoom, env->map[co.x][co.y]);
			++co.y;
			w_coord.y += env->zoom;
		}
		w_coord.x -= env->zoom;
		++co.x;
	}
}

int		*line_to_itab(char *line, t_env *env)
{
	int		i;
	int		*tab;
	char	**tmp;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	if (!(tab = (int *)malloc(sizeof(int) * ft_strtablen(tmp))))
		return (NULL);
	while (tmp[i])
	{
		tab[i] = ft_atoi(tmp[i]);
		i++;
	}
	if (env->size > 1 && env->len != i)
	{
		ft_putendl("error map");
		exit(0);
	}
	env->len = i;
	return (tab);
}

int		**create_map(int *itab, t_env *env)
{
	int	**newmap;
	int	i;

	i = 0;
	if (!(newmap = (int **)malloc(sizeof(int *) * env->size)))
		return (NULL);
	newmap[env->size - 1] = itab;
	while (i < env->size - 1)
	{
		newmap[i] = env->map[i];
		++i;
	}
	return (newmap);
}

void	print_tab(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (i < env->size)
	{
		j = 0;
		while (j < env->len)
		{
			ft_putnbr(env->map[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
