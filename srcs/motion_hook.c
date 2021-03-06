/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:36:38 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/01 12:42:10 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_press(int mousecode, int x, int y, void *params)
{
	if (mousecode == 1)
		rd((t_mlx *)params, 0);
	if (mousecode == 5 || mousecode == 4)
		mouse_hook(mousecode, x, y, params);
	return (0);
}

int			key_release(int mousecode, int x, int y, void *params)
{
	int x1;
	int y1;

	x1 = x;
	y1 = y;
	if (mousecode == 1)
		rd((t_mlx *)params, 1);
	return (0);
}

void		motion(int x, int y, t_mlx *mlx)
{
	mlx->datas->c_r = (double)x / RESO_X * 4 - 2;
	mlx->datas->c_i = (double)y / RESO_Y * 4 - 2;
	try_to_redraw(mlx);
}

int			motion_mouse(int x, int y, void *params)
{
	t_mlx *mlx;

	mlx = params;
	if (x >= 0 && y >= 0 && x <= RESO_X && y <= RESO_Y && mlx->tt == 1)
		motion(x, y, (t_mlx *)params);
	return (1);
}
