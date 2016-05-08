/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:32:38 by lnagy             #+#    #+#             */
/*   Updated: 2016/04/26 17:32:47 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_press(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	if (key == RIGHT || key == LEFT)
		env->mv = (key == RIGHT ? -1 : 1);
	if (key == UP || key == DOWN)
		env->ud = (key == UP ? -1 : 1);
		if (key == PLUS || key == MINUS)
		env->zoomio = (key == PLUS ? -1 : 1);
	return (0);
}

static int	key_release(int key, t_env *env)
{
	if (key == RIGHT || key == LEFT)
		env->mv = 0;
	if (key == UP || key == DOWN)
		env->ud = 0;
	if (key == PLUS || key == MINUS)
		env->zoomio = 0;
	return (0);
}

static int	reborn_map(t_env *env)
{
	if (env->mv)
		env->o_x += (env->mv == 1 ? -5 : 5);
	if (env->ud)
		env->o_y += (env->ud == 1 ? -5 : 5);
	if (env->zoomio)
		env->zoom *= (env->zoomio == 1 ? 1/1.1 : 1.1);
	mlx_clear_window(env->mlx, env->win);
	do_map(env);
	return (0);
}

void		do_mlx(t_env *env)
{
	mlx_hook(env->win, KeyPress, KeyPressMask, key_press, env);
	mlx_hook(env->win, KeyRelease, KeyReleaseMask, key_release, env);
	mlx_loop_hook(env->mlx, reborn_map, env);
	mlx_loop(env->mlx);
}
