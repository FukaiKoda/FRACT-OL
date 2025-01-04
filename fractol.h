/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:16:22 by habdella          #+#    #+#             */
/*   Updated: 2025/01/01 14:36:35 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define WIDTH	800
# define HEIGHT	800
/* ----- Buttons and Keys -----*/
# define KEY_ESC	65307
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_PLUS	61
# define KEY_MINUS	45
# define BUTTON4	4
# define BUTTON5	5
/* ---------- Colors ---------- */
# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define DARK_BLUE	0x00008B
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF
# define GRAY		0x808080
# define LIGHT_GRAY	0xD3D3D3
# define DARK_GRAY	0x404040
# define ORANGE		0xFFA500
# define PURPLE		0x800080
# define BROWN		0xA52A2A

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_MaxMin
{
	double	r_min;
	double	r_max;
	double	i_min;
	double	i_max;
}	t_MaxMin;

typedef struct s_all
{
	void		*mlx;
	char		*name;
	void		*window;
	void		*img;
	char		*pixel;
	int			bpp;
	int			endian;
	int			l_line;
	int			color;
	int			loop;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		o_min;
	double		o_max;
	t_complex	julia;
	t_MaxMin	m;
}	t_all;

/* -------------- input handle ------------ */
int			check_input(int ac, char **av);
int			ft_strcmp(char *s1, char *s2);
void		ft_strlowcase(char *s);
void		puterror(t_all *fract);
void		ft_putstr(char *s);
/* -------------- display setup -------------- */
void		initialize(t_all *fract);
void		error_free(void);
/* -------------- fractal render ------------- */
void		fractal_render(t_all *fract);
void		check_pixels(int x, int y, t_all *fract);
/* --------------- math helpers -------------- */
double		scale(double num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex_abs(t_complex z);
t_complex	square_complex(t_complex z);
double		atodbl(char *s);
/* --------------- events handlers ----------- */
void		events_init(t_all *fract);
int			key_fun(int keysym, t_all *fract);
int			mouse_fun(int button, int x, int y, t_all *fract);
int			julia_track(int x, int y, t_all *fract);
int			close_fun(t_all *fract);

#endif
