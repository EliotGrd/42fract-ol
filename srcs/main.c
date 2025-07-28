/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:44:02 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/20 22:52:11 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	check_julia(char **av)
{
	double	a;
	double	b;

	a = ft_atof(av[2]);
	b = ft_atof(av[3]);
	if ((a >= -2.0 && a <= 2.0) && (b >= -2.0 && b <= 2.0))
		return (1);
	else
		return (0);
}

static int	check_phoenix(char **av)
{
	double	kr;
	double	ki;
	double	cr;
	double	ci;

	kr = ft_atof(av[2]);
	ki = ft_atof(av[3]);
	ci = ft_atof(av[4]);
	cr = ft_atof(av[5]);
	if ((kr >= -1.0 && kr <= 1.0) && (ki >= -1.0 && ki <= 1.0)
		&& (cr >= -1.0 && cr <= 1.0) && (ci >= -1.0 && ci <= 1.0))
		return (1);
	else
		return (0);
}

static void	check_input(t_fractol *f, int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		f->type = "mandelbrot";
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5) && check_julia(av))
	{
		f->type = "julia";
		f->jr = atof(av[2]);
		f->ji = atof(av[3]);
	}
	else if (ac == 2 && !ft_strncmp(av[1], "burningship", 11))
		f->type = "burningship";
	else if (ac == 6 && !ft_strncmp(av[1], "phoenix", 7 && check_phoenix(av)))
	{
		f->type = "phoenix";
		f->pv.k.reel = ft_atof(av[2]);
		f->pv.k.imag = ft_atof(av[3]);
		f->pv.c.reel = ft_atof(av[4]);
		f->pv.c.imag = ft_atof(av[5]);
	}
	else
		exit_fractol(INPUT, f);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	init_clear(&f);
	check_input(&f, ac, av);
	init_fractol(&f);
	ft_printf("Program launched, press h for help\n");
	render_fractal(&f);
	mlx_key_hook(f.win, (int (*)())(void *)handle_key, &f);
	mlx_mouse_hook(f.win, (int (*)())(void *)handle_mouse_key, &f);
	mlx_hook(f.win, 17, 0, (int (*)())(void *)handle_close, &f);
	mlx_loop(f.mlx);
}
