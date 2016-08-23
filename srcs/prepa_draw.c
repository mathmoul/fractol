/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepa_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 17:53:41 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 19:14:06 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	prepa_draw(void *params)
{
	t_mlx *mlx;

	mlx = params;
	mlx->img = mlx_new_image(mlx->mlx, RESO_X, RESO_Y);
	mlx->d_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, \
			&mlx->endian);
	draw(mlx, mlx->funct);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}