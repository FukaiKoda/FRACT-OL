/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:16:12 by habdella          #+#    #+#             */
/*   Updated: 2025/01/01 13:52:26 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_all *fract, int color)
{
	int	offset;

	offset = (y * fract->l_line) + (x * (fract->bpp / 8));
	*(unsigned int *)(fract->pixel + offset) = color;
}

static void	which_set(t_complex *z, t_complex *c, t_all *fract)
{
	if (!ft_strcmp(fract->name, "julia"))
	{
		c->r = fract->julia.r;
		c->i = fract->julia.i;
	}
	else
	{
		c->r = z->r;
		c->i = z->i;
	}
}

void	check_pixels(int x, int y, t_all *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;

	z.r = (scale(x, fract->m.r_min, fract->m.r_max, WIDTH)
			* fract->zoom) + fract->shift_x;
	z.i = (scale(y, fract->m.i_min, fract->m.i_max, HEIGHT)
			* fract->zoom) + fract->shift_y;
	which_set(&z, &c, fract);
	i = 0;
	while (i < fract->loop)
	{
		if (!ft_strcmp(fract->name, "burningship"))
			z = sum_complex(square_complex_abs(z), c);
		else
			z = sum_complex(square_complex(z), c);
		if ((z.r * z.r) + (z.i * z.i) > 4)
		{
			fract->color = scale(i, BLACK, WHITE, fract->loop);
			my_pixel_put(x, y, fract, fract->color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, fract, BLACK);
}

void	fractal_render(t_all *fract)
{
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			check_pixels(x, y, fract);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->img, 0, 0);
}
