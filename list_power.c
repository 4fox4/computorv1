/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_power.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 09:08:10 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/11 12:47:51 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void		list_pwr(t_struct *e)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	e->list_pwr = (float*)malloc(sizeof(float) * e->nb_form + 1);
	while (e->list_form[i])
	{
		j = 0;
		while ((e->list_form[i][1] != e->list_form[j][1]) && j < i)
			j++;
		if (i == j)
		{
			e->list_pwr[k] = e->list_form[i][1];
			k++;
		}
		i++;
	}
	e->float_tablen = k - 1;
	last_list(e);
}
