/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motanha- <motanha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:49:39 by motanha-          #+#    #+#             */
/*   Updated: 2023/10/06 18:11:49 by motanha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/** Here 0,05 is a factor of direction **/

void	move_keys(int key, t_mlx *mlx)
{
	t_oper	delta;

	delta = complex_init((mlx->max.r - mlx->min.r) * 0.05,
			(mlx->max.i - mlx->min.i) * 0.05);
	if (key == KEY_A)
	{
		mlx->min.r = mlx->min.r - delta.r;
		mlx->max.r = mlx->max.r - delta.r;
	}
	else if (key == KEY_D)
	{
		mlx->min.r = mlx->min.r + delta.r;
		mlx->max.r = mlx->max.r + delta.r;
	}
	else if (key == 1)
	{
		mlx->min.i = mlx->min.i - delta.i;
		mlx->max.i = mlx->max.i - delta.i;
	}
	else if (key == KEY_W)
	{
		mlx->min.i = mlx->min.i + delta.i;
		mlx->max.i = mlx->max.i + delta.i;
	}
}

/** fnc to shift colors around **/

void	shift_color(t_mlx *mlx)
{
	mlx->shift++;
	if (mlx->shift > 3)
		mlx->shift = 1;
}

int	keymap(int key, t_mlx *mlx)
{
	if (key == KEY_E)
	{
		if (mlx->iter_max < 50)
			mlx->iter_max += 1;
		else if (mlx->iter_max < 1000000000)
			mlx->iter_max *= 1.05;
	}
	if (key == KEY_Q)
	{
		if (mlx->iter_max > 50)
			mlx->iter_max *= 0.95;
		else if (mlx->iter_max > 1)
			mlx->iter_max -= 1;
	}
	if (key == KEY_SPACE)
		default_init(mlx);
	if (key == KEY_ESC)
		close_window(mlx);
	if (key == KEY_A || key == KEY_D || key == KEY_S \
			|| key == KEY_W)
		move_keys(key, mlx);
	if (key == KEY_C)
		shift_color(mlx);
	render_fractal(mlx);
	return (0);
}
