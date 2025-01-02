/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:58:46 by habdella          #+#    #+#             */
/*   Updated: 2025/01/01 09:33:47 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_strlowcase(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_input(int ac, char **av)
{
	if (ac == 1)
		return (1);
	ft_strlowcase(av[1]);
	if (!ft_strcmp(av[1], "mandelbrot"))
		return (0);
	if (!ft_strcmp(av[1], "julia"))
		return (0);
	if (!ft_strcmp(av[1], "burningship"))
		return (0);
	return (1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

void	puterror(t_all *fract)
{
	ft_putstr("\tError!\nTry again with one of these params:\n");
	ft_putstr("1: \"Mandelbrot\"\n2: \"Julia\" <Real> <Imaginary>\n");
	ft_putstr("3: \"BurningShip\"\n");
	free(fract);
	exit(1);
}
