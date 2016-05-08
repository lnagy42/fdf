/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:33:13 by lnagy             #+#    #+#             */
/*   Updated: 2016/04/26 17:33:15 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_line_dx(t_env *env, int dx, int dy, int xincr, int yincr, int x1, int y1, int z1)
{
	int i;
	int error;

	i = 0;
	error = dx / 2;
	while (i < dx)
	{
		x1 += xincr;
		error += dy;
		if (error > dx)
		{
			error -= dx;
			y1 += yincr;
		}
		mlx_pixel_put(env->mlx, env->win, x1, y1, z1 > 0 ? 0xff : 0xffffff);
		i++;
	}
}

void	print_line_dy(t_env *env, int dx, int dy, int xincr, int yincr, int x1, int y1, int z1)
{
	int i;
	int error;

	i = 0;
	error = dy / 2;
	while (i < dy)
	{
		y1 += yincr;
		error += dx;
		if (error > dy)
		{
			error -= dy;
			x1 += xincr;
		}
		mlx_pixel_put(env->mlx, env->win, x1, y1, z1 > 0 ? 0xff : 0xffffff);
		i++;
	}
}

void	put_line(t_env *env, int x1, int y1, int x2, int y2, int z1)
{
	int xincr;
	int yincr;
	int dx;
	int dy;

	xincr = 1;
	if (x1 > x2)
		xincr = -1;
	yincr = 1;
	if (y1 > y2)
		yincr = -1;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	mlx_pixel_put(env->mlx, env->win, x1, y1, z1 > 0 ? 0xff : 0xffffff);
	mlx_pixel_put(env->mlx, env->win, x2, y2, z1 > 0 ? 0xff : 0xffffff);
	if (dx > dy)
		print_line_dx(env, dx, dy, xincr, yincr, x1, y1, z1);
	else
		print_line_dy(env, dx, dy, xincr, yincr, x1, y1, z1);
}
