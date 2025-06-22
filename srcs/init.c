/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:45:03 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/20 22:46:26 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_clear(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img.img = NULL;
	f->type = NULL;
	f->c_max_iter = 0;
	f->color_mode = 0;
	f->color_table = NULL;
	f->zoom = 0;
	f->offset_x = 0;
	f->offset_y = 0;
	f->jr = 0;
	f->ji = 0;
}

void	init_image(t_fractol *f)
{
	t_img	nimg;
	nimg.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!nimg.img)
		exit_fractol(MALLOC, f);
	nimg.addr = mlx_get_data_addr(nimg.img, &nimg.bits_per_pixel, &nimg.line_length, &nimg.endian);
	if (!nimg.addr)
		exit_fractol(MALLOC, f);
	f->img = nimg;
}

void	init_fractol(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		exit_fractol(MALLOC, f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->type);
	if (!f->win)
		exit_fractol(MALLOC, f);
	f->c_max_iter = MAX_ITER;
	f->zoom = 1;
	update_color_table(f);
}
