/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:32:38 by lnagy             #+#    #+#             */
/*   Updated: 2016/04/26 17:32:47 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// void do_colors(int r, int g, int b, t_env *env)
// {
// 	while (r > 139 && g > 101 && b > 8 && env->o_z < env->z)
// 		{
// 			r *= 1,05;
// 			g *= 1,05;
// 			b *= 1,05;
// 			env->o_z++;
// 		}
// }

int		main(int ac, char **av)
{
	t_env	env;
	int		fd;
	char	*line;
	int		*itab;

	env.size = 1;
	if (ac != 2)
	{
		ft_putendl("arg error");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	while(ft_gnl(fd, &line))
	{
		itab = line_to_itab(line, &env);
		env.map = create_map(itab, &env);
		env.size++;
		free(line);
	}
	if (env.size == 1)
	{
		ft_putendl("empty map");
		return (0);
	}
	env.size--;
	print_tab(&env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 900, 900, "win 42");
	env.o_x = 425;
	env.o_y = 425;
	env.mv = 0;
	env.ud = 0;
	env.zoom = 10;
	env.zoomio = 0;
	do_map(&env);
	do_mlx(&env);
	return (0);
}
