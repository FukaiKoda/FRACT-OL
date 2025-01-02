/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:35:08 by habdella          #+#    #+#             */
/*   Updated: 2025/01/01 14:39:50 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_fun(t_all *fract)
{
	mlx_destroy_image(fract->mlx, fract->img);
	mlx_destroy_window(fract->mlx, fract->window);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	free(fract);
	exit(0);
}

void	zoom_viewpoint(t_all *fract, int x, int y, double zoom_factor)
{
	double	mouse_r;
	double	mouse_i;
	double	range_r;
	double	range_i;

	mouse_r = fract->m.r_min + (x / (double)WIDTH)
		* (fract->m.r_max - fract->m.r_min);
	mouse_i = fract->m.i_min + (y / (double)HEIGHT)
		* (fract->m.i_max - fract->m.i_min);
	range_r = (fract->m.r_max - fract->m.r_min) * zoom_factor;
	range_i = (fract->m.i_max - fract->m.i_min) * zoom_factor;
	fract->m.r_min = mouse_r - range_r / 2.0;
	fract->m.r_max = mouse_r + range_r / 2.0;
	fract->m.i_min = mouse_i - range_i / 2.0;
	fract->m.i_max = mouse_i + range_i / 2.0;
}

int	mouse_fun(int button, int x, int y, t_all *fract)
{
	if (button == BUTTON5)
	{
		zoom_viewpoint(fract, x, y, 0.9);
	}
	else if (button == BUTTON4)
	{
		zoom_viewpoint(fract, x, y, 1.05);
	}
	mlx_clear_window(fract->mlx, fract->window);
	fractal_render(fract);
	return (0);
}

int	key_fun(int keysym, t_all *fract)
{
	if (keysym == KEY_ESC)
		close_fun(fract);
	else if (keysym == KEY_LEFT)
		fract->shift_x -= (0.5 * fract->zoom);
	else if (keysym == KEY_RIGHT)
		fract->shift_x += (0.5 * fract->zoom);
	else if (keysym == KEY_UP)
		fract->shift_y -= (0.5 * fract->zoom);
	else if (keysym == KEY_DOWN)
		fract->shift_y += (0.5 * fract->zoom);
	else if (keysym == KEY_PLUS)
		fract->loop += 10;
	else if (keysym == KEY_MINUS)
		fract->loop -= 10;
	mlx_clear_window(fract->mlx, fract->window);
	fractal_render(fract);
	return (0);
}

int	julia_track(int x, int y, t_all *fract)
{
	if (!ft_strcmp(fract->name, "julia"))
	{
		fract->julia.r = scale(x, -2, 2, WIDTH) * fract->zoom + fract->shift_x;
		fract->julia.i = scale(y, -2, 2, HEIGHT) * fract->zoom + fract->shift_y;
		fractal_render(fract);
	}
	return (0);
}
