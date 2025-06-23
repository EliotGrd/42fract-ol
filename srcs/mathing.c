/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:37:41 by egiraud           #+#    #+#             */
/*   Updated: 2025/06/16 21:46:57 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	c_add(t_complex a, t_complex b)
{
	t_complex	res;

	res.reel = a.reel + b.reel;
	res.imag = a.imag + b.imag;
	return (res);
}

t_complex	c_mult(t_complex a, t_complex b)
{
	t_complex	res;

	res.reel = a.reel * b.reel - a.imag * b.imag;
	res.imag = a.reel * b.imag + a.imag * b.reel;
	return (res);
}

int	c_abs(t_complex a)
{
	return (sqrt(a.reel * a.reel + a.imag * a.imag));
}

double	scale(double to_scale, double n_min, double n_max, double o_max)
{
	return (n_min + (n_max - n_min) * (to_scale - 0) / (o_max - 0));
}
