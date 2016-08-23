/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_deg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 11:13:10 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/11 20:17:33 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void		ft_second_deg(t_struct *e)
{
	if (e->delta < 0.0)
	{
		e->sol = 0;
		ft_print_2nd_deg(e);
	}
	else if (e->delta == 0.0)
	{
		e->sol = 1;
		e->x = (-e->b) / (2 * e->a);
		ft_print_2nd_deg(e);
	}
	else if (e->delta > 0.0)
	{
		e->sol = 2;
		e->x1 = (-e->b + ft_sqrt(e->delta)) / (2 * e->a);
		e->x2 = (-e->b - ft_sqrt(e->delta)) / (2 * e->a);
		ft_print_2nd_deg(e);
	}
	else
		ft_error(3);
	exit(0);
}
