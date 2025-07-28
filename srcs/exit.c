/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:13:41 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/20 22:42:54 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	free_fractol(t_fractol *f)
{
	if (f->img.img && f->mlx)
		mlx_destroy_image(f->mlx, f->img.img);
	if (f->mlx && f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
#ifdef __linux__
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
#endif
		free(f->mlx);
	}
	if (f->color_table)
		free(f->color_table);
	ft_printf("Program terminated successfully :) ");
	exit(0);
}

void	exit_fractol(int errcode, t_fractol *f)
{
	if (errcode == QUIT)
	{
		ft_printf("\nProgram closing...");
		free_fractol(f);
	}
	else if (errcode == MALLOC)
	{
		ft_printf("\nMalloc Error :(\n");
		free_fractol(f);
	}
	else if (errcode == INPUT)
	{
		ft_printf("Bad Input try this :\n    ./fractol mandelbrot\n    \
./fractol julia <cr> <ci> (where cr and ci are numbers included between \
-2.0 et 2.0)\n    ./fractol burningship\n    ./fractol pheonix <kr> <ki>\
 <cr> <ci> (where numbers included between -1.0 et 1.0)\n\nHere some cool \
examples of params :\n  Julia\n(0.285 0.01), (-1.476 0), (-0.8 0.156), (-0.4 0.6),\n\
(-0.8696 0.26), (-0.78 -0.13), (-0.097 -0.841), (0.234 0.543)\n  Phoenix\n\
(-0.5 0 0.5666 0), (0.2955 0 -0.4 0.1),\n(-0.25 0 0.4 0), (-0.35 0 0.1 0.6),\n\
(-0.8 0 0.6 -0.1), (0 -0.01 0.269 0),\n(-0.53 0 0.55 -0.1), (0.855 0 0.1 0.1)");
		exit(0);
	}
}
