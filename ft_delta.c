/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 15:13:28 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/11 10:47:52 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void		ft_delta(t_struct *e)
{
	e->delta = ft_power(e->b, 2) - 4 * e->a * e->c;
	ft_second_deg(e);
}
