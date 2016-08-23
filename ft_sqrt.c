/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 13:38:57 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/11 11:04:13 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

double		ft_sqrt(float n)
{
	float	s;
	double	d;
	double	x;

	s = 1;
	while (s * s <= n)
		s++;
	s--;
	d = 0.001;
	while (d < 1.0)
	{
		x = s + d;
		if (x * x > n)
		{
			x -= 0.001;
			break ;
		}
		d += 0.001;
	}
	return (x);
}
