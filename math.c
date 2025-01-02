/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:26:55 by habdella          #+#    #+#             */
/*   Updated: 2025/01/01 11:14:58 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double num, double new_min, double new_max, double old_max)
{
	return (new_min + ((num - 0) * (new_max - new_min) / (old_max - 0)));
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	rs;

	rs.r = z1.r + z2.r;
	rs.i = z1.i + z2.i;
	return (rs);
}

t_complex	square_complex(t_complex z)
{
	t_complex	rs;

	rs.r = (z.r * z.r) - (z.i * z.i);
	rs.i = 2 * z.r * z.i;
	return (rs);
}

t_complex	square_complex_abs(t_complex z)
{
	t_complex	rs;

	rs.r = (z.r * z.r) - (z.i * z.i);
	rs.i = 2 * fabs(z.r) * fabs(z.i);
	return (rs);
}

double	atodbl(char *s)
{
	long	num;
	double	exp;
	double	pow;
	int		sign;

	(1) && (num = 0, exp = 0, pow = 1, sign = 1);
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign *= -1;
	while (*s >= '0' && *s <= '9')
		num = (*s++ - '0') + (num * 10);
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		exp = exp + (*s++ - 48) * pow;
	}
	return ((double)((num + exp) * sign));
}
