/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:15:32 by habdella          #+#    #+#             */
/*   Updated: 2025/01/01 11:29:33 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_set(t_all *fract, int ac, char **av)
{
	if (!ft_strcmp(av[1], "julia") && ac == 4)
	{
		fract->julia.r = atodbl(av[2]);
		fract->julia.i = atodbl(av[3]);
	}
	else if (!ft_strcmp(av[1], "mandelbrot") && ac == 2)
	{
		fract->julia.r = 0.0;
		fract->julia.i = 0.0;
	}
	else if (!ft_strcmp(av[1], "burningship") && ac == 2)
	{
		fract->julia.r = 0.0;
		fract->julia.i = 0.0;
	}
	else
		return (1);
	return (0);
}

void	struct_init(t_all *fract)
{
	fract->mlx = NULL;
	fract->window = NULL;
	fract->img = NULL;
	fract->pixel = NULL;
	fract->endian = 0;
	fract->color = 0;
	fract->loop = 50;
	fract->shift_x = 0.0;
	fract->shift_y = 0.0;
	fract->zoom = 1.0;
	fract->m.r_min = -2.0;
	fract->m.r_max = 2.0;
	fract->m.i_min = -2.0;
	fract->m.i_max = 2.0;
}

int	main(int ac, char **av)
{
	t_all	*fract;

	fract = malloc(sizeof(t_all));
	if (!fract)
		return (0);
	if (check_input(ac, av))
		puterror(fract);
	if (check_set(fract, ac, av))
		puterror(fract);
	fract->name = av[1];
	struct_init(fract);
	initialize(fract);
	fractal_render(fract);
	mlx_loop(fract->mlx);
	free(fract);
	return (0);
}
