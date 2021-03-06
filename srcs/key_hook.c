/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:39:27 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/01 13:13:40 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		movement_hook(int keycode, void *params)
{
	if (123 <= keycode && keycode <= 126)
		redraw_key_position((t_mlx *)params, keycode);
	return (0);
}

void	re_init(t_mlx *mlx)
{
	mlx->zoom = 100;
	mlx->iter_max = 18;
	mlx->tt = 1;
	free(mlx->datas);
	mlx->datas = NULL;
	mlx->datas = init_datas(mlx);
	try_to_redraw(mlx);
}

void	change_colors(int keycode, t_mlx *mlx)
{
	if (0 < mlx->color_style && mlx->color_style < 5)
	{
		if (keycode == 121)
		{
			if (--mlx->color_style == 0)
				mlx->color_style = 4;
		}
		else if (keycode == 116)
		{
			if (++mlx->color_style == 5)
				mlx->color_style = 1;
		}
	}
	else
		mlx->color_style = 1;
	try_to_redraw(mlx);
}

int		key_hook(int keycode, void *params)
{
	t_mlx *mlx;

	mlx = params;
	if (keycode == 50)
		re_init(mlx);
	if (keycode >= 83 && keycode <= 88)
	{
		mlx->color_style = keycode;
		try_to_redraw(mlx);
	}
	if (keycode == 121 || keycode == 116)
		change_colors(keycode, mlx);
	if (keycode == 53)
		exit(0);
	return (0);
}
