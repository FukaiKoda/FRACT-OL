/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:03:44 by habdella          #+#    #+#             */
/*   Updated: 2025/01/01 14:01:07 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_free(void)
{
	perror("Error with allocation in malloc");
	exit(1);
}

void	events_init(t_all *fract)
{
	mlx_hook(fract->window, 2, 1L << 0, key_fun, fract);
	mlx_hook(fract->window, 4, 1L << 2, mouse_fun, fract);
	mlx_hook(fract->window, 17, 1L << 17, close_fun, fract);
	mlx_hook(fract->window, 6, 1L << 6, julia_track, fract);
}

void	initialize(t_all *fract)
{
	fract->mlx = mlx_init();
	if (fract->mlx == NULL)
		error_free();
	fract->window = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->name);
	if (fract->window == NULL)
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		error_free();
	}
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (fract->img == NULL)
	{
		mlx_destroy_window(fract->mlx, fract->window);
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		error_free();
	}
	fract->pixel = mlx_get_data_addr(fract->img,
			&fract->bpp, &fract->l_line, &fract->endian);
	events_init(fract);
}
