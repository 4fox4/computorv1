/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_top.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 14:12:36 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/26 11:13:11 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void		power_top(t_struct *e)
{
	int		i;
	float	tmp;

	i = 0;
	tmp = 0;
	while (e->last_list[i])
	{
		if (e->last_list[i][1] > tmp)
			tmp = e->last_list[i][1];
		i++;
	}
	e->power_top = tmp;
	det_polynome(e);
}
