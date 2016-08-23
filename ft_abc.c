/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 12:57:36 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/12 12:49:45 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void		ft_abc(t_struct *e)
{
	int		i;

	i = 0;
	while (i < e->new_tablen)
	{
		if (e->last_list[i][1] == 2)
			e->a = e->last_list[i][0];
		else if (e->last_list[i][1] == 1)
			e->b = e->last_list[i][0];
		else if (e->last_list[i][1] == 0)
			e->c = e->last_list[i][0];
		else
			ft_error(5);
		i++;
	}
	if (e->degre == 1)
		ft_premier_deg(e);
	else if (e->degre == 2)
		ft_delta(e);
	else if (e->degre == 0)
		ft_print_no_deg(e);
}
