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

	return res;
}

t_complex	c_mult(t_complex a, t_complex b)
{
	t_complex	res;

	res.reel = a.reel * b.reel - a.imag * b.imag;
	res.imag = a.reel * b.imag + a.imag * b.reel;

	return res;
}

int	c_abs(t_complex a)
{
	return (sqrt(a.reel * a.reel + a.imag * a.imag));
}



double	scale(double to_scale, double new_min, double new_max, double old_max)
{
	return (new_min + (new_max - new_min) * (to_scale - 0) / (old_max - 0));
}
