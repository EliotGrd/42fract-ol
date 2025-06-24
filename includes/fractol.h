/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:33:59 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/22 16:57:17 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* Window */
# define WIDTH 720
# define HEIGHT 720

/* Misc */
# define MAX_ITER 50
# define ITER_TRESHOLD 310

/* Err Codes */
# define QUIT 0
# define INPUT 1
# define MALLOC 2

/* Libraries */
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

/* COLORS */
# define BLACK   0xFF000000

/* Structs */
typedef struct s_pixel
{
	double	x;
	double	y;
}			t_pixel;

typedef struct s_complex
{
	double	reel;
	double	imag;
}			t_complex;

typedef struct s_pvalues
{
	t_complex	k;
	t_complex	c;
}				t_pvalues;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_img		img;
	char		*type;
	int			c_max_iter;
	int			color_mode;
	int			*color_table;
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		jr;
	double		ji;
	t_pvalues	pv;
}				t_fractol;

/* Maths */
t_complex	c_add(t_complex a, t_complex b);
t_complex	c_mult(t_complex a, t_complex b);
int			c_abs(t_complex a);
double		scale(double to_scale, double n_min, double n_max, double o_max);

/* Init */
void		init_clear(t_fractol *f);
void		init_fractol(t_fractol *f);

/* Controller */
void		key_controller(t_fractol *f);

/* Fractals */
int			mandelbrot(t_complex c, int c_max_iter);
int			julia(t_complex c, t_complex z, int c_max_iter);
int			burningship(t_complex c, int c_max_iter);
int			phoenix(t_complex z, t_complex k, t_complex c, int c_max_iter);

/* Palettes */
int			poli_gradiant(int iter, int max_iter);
int			sin_tripy(int iter, int max_iter);
int			fire_thing(int iter, int max_iter);
int			purple_trip(int iter, int max_iter);

int			colorize(int nb_iter, t_fractol *f);
void		update_color_table(t_fractol *f);

void		init_image(t_fractol *f);
void		render_fractal(t_fractol *f);
void		exit_fractol(int errcode, t_fractol *f);

void		handle_close(t_fractol *f);
void		handle_key(int keycode, t_fractol *f);
void		handle_mouse_key(int keycode, int x, int y, t_fractol *f);

#endif
