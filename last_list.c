/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 09:09:25 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/11 11:04:37 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void		last_list(t_struct *e)
{
	int		i;

	e->last_list = (float**)malloc(sizeof(float*) * e->nb_form + 1);
	while (e->q <= e->float_tablen)
	{
		e->last_list[e->r] = (float*)malloc(sizeof(float) * 2);
		i = 0;
		while (e->list_form[i])
		{
			if (e->list_pwr[e->q] == e->list_form[i][1])
				e->tmp += e->list_form[i][0];
			i++;
		}
		if (e->tmp != 0)
		{
			e->last_list[e->r][1] = e->list_pwr[e->q];
			e->last_list[e->r][0] = e->tmp;
			e->r++;
		}
		e->q++;
		e->tmp = 0;
	}
	e->new_tablen = e->r;
	power_top(e);
}
