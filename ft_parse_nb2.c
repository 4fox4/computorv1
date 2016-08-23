/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nb2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 12:06:13 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/26 10:15:54 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void		float_convert(t_struct *e)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	e->count = 1;
	e->list_form = (float**)malloc(sizeof(float*) * e->nb_form + 1);
	while (i < (e->nb_form) * 2)
	{
		e->list_form[j] = (float*)malloc(sizeof(float) * 2);
		while (e->count <= 2)
		{
			e->list_form[j][k] = strtof(e->tmp2[i], NULL);
			e->count++;
			k++;
			i++;
		}
		k = 0;
		e->count = 1;
		j++;
	}
	e->list_form[j] = NULL;
	list_pwr(e);
}

void		stock_nb(t_struct *e)
{
	e->tmp2[e->o] = (char*)malloc(sizeof(char) * ft_strlen(e->forms[e->m]) + 1);
	while (e->space < 2)
	{
		if (e->forms[e->m][e->n] == ' ')
			e->space++;
		else
		{
			e->tmp2[e->o][e->p] = e->forms[e->m][e->n];
			e->p++;
		}
		e->n++;
	}
	e->tmp2[e->o][e->p] = '\0';
	e->o++;
	e->p = 0;
	e->n += 4;
}

void		ft_parse_nb2(t_struct *e)
{
	e->tmp2 = (char**)malloc(sizeof(char*) * (e->nb_form * 2) + 1);
	while (e->m < e->nb_form)
	{
		stock_nb(e);
		e->tmp2[e->o] = (char*)malloc(sizeof(char) * (ft_strlen(e->forms[e->m])\
															- e->n) + 1);
		while (e->n < ft_strlen(e->forms[e->m]))
		{
			e->tmp2[e->o][e->p] = e->forms[e->m][e->n];
			e->p++;
			e->n++;
		}
		e->tmp2[e->o][e->p] = '\0';
		e->o++;
		e->m++;
		e->space = 0;
		e->n = 0;
		e->p = 0;
	}
	e->tmp2[e->o] = NULL;
	float_convert(e);
}
