/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motanha- <motanha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:49:07 by motanha-          #+#    #+#             */
/*   Updated: 2023/09/27 14:49:18 by motanha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fractol.h"
#include <stdio.h>

/**
 * @brief  Finding the no of iterations for mandlebrot

 */
void	mandelbrot(t_mlx *mlx)
{
	t_oper	z;

	z = complex_init(mlx->c.r, mlx->c.i);
	mlx->iter = 0;
	while (pow(z.r, 2) + pow(z.i, 2) <= 4 && mlx->iter < mlx->iter_max)
	{
		z = complex_init(pow(z.r, 2) - pow(z.i, 2) + mlx->c.r, \
			2 * z.r * z.i + mlx->c.i);
		mlx->iter++;
	}
}

void	julia(t_mlx *mlx)
{
	t_oper	z;

	z = complex_init(mlx->c.r, mlx->c.i);
	mlx->iter = 0;
	while (pow(z.r, 2.0) + pow(z.i, 2.0) <= 4
		&& mlx->iter < mlx->iter_max)
	{
		z = complex_init(pow(z.r, 2) - pow(z.i, 2) + mlx->k.r, \
		2.0 * z.r * z.i + mlx->k.i);
		mlx->iter++;
	}
}

void	burning_ship(t_mlx *mlx)
{
	t_oper	z;

	z = complex_init(mlx->c.r, mlx->c.i);
	mlx->iter = 0;
	while (pow(z.r, 2.0) + pow(z.i, 2.0) <= 4 && \
				mlx->iter < mlx->iter_max)
	{
		z = complex_init(pow(z.r, 2) - pow(z.i, 2) + \
			(mlx->c.r), -2 * fabs(z.r * z.i) + mlx->c.i);
		mlx->iter++;
	}
}
