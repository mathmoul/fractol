/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 17:42:25 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 17:43:07 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double			carre(double x)
{
	return (x * x);
}

double			cube(double x)
{
	return (x * x * x);
}

double			p_4(double x)
{
	return (x * x * x * x);
}
