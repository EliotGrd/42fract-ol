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
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
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
		ft_printf("Program closing...");
		free_fractol(f);
	}
	else if (errcode == MALLOC)
	{
		ft_printf("Malloc Error :(");
		free_fractol(f);
	}
	else if (errcode == INPUT)
	{
		ft_printf("Bad Input try this :\n    ./fractol mandelbrot\n    ./fractol julia <a> <b> (where a and b included between -2.0 et 2.0)\n    ./fractol burningship");
		exit(0);
	}
}
