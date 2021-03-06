/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_east_south.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:03:05 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/13 19:03:06 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_east_south(t_env *env, t_pt3d pt0, t_pt3d pt1, float *d)
{
	float	e;
	float	ez;
	float	ht;

	ht = (pt1.z - pt0.z) / d[X];
	ez = pt0.z;
	e = d[X];
	d[X] = e * 2;
	d[Y] = d[Y] * 2;
	while (1)
	{
		ft_put_pixel_in_image(env, pt0, ez);
		ez += ht;
		pt0.x += 1;
		if (pt0.x >= pt1.x)
			break ;
		e -= d[Y];
		if (e < 0.0)
		{
			pt0.y += 1;
			e += d[X];
		}
	}
}
