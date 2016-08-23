/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynome.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 11:03:49 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/19 16:10:04 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void		ft_power_error(t_struct *e)
{
	int		i;

	i = 0;
	printf("\033[1m\n");
	printf(" Equation de base    |   %s\n\033[35m", e->e);
	printf("\033[37m Equation simplifiee | ");
	while (i < e->nb_form)
	{
		printf("%s ", e->forms[i]);
		i++;
	}
	printf("= 0\n\n\033[35m");
	ft_error(2);
}

void		pol_0_filter(t_struct *e)
{
	e->degre = 0;
	if (e->last_list[0][1] == 0 && e->last_list[0][0] == 0)
		ft_abc(e);
	else if (e->last_list[0][1] == 0 && e->last_list[0][0] != 0)
		ft_abc(e);
	else
		ft_error(9);
}

void		pol_1_filter(t_struct *e)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < 1 && j == 1)
	{
		if (e->last_list[i][1] == 0)
			j = 1;
		else if (e->last_list[i][1] == 1)
			j = 1;
		else
			j = 0;
		i++;
	}
	if (j == 1)
	{
		e->degre = 1;
		ft_abc(e);
	}
	else
		ft_error(7);
}

void		pol_2_filter(t_struct *e)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < 2 && j == 1)
	{
		if (e->last_list[i][1] == 0)
			j = 1;
		else if (e->last_list[i][1] == 1)
			j = 1;
		else if (e->last_list[i][1] == 2)
			j = 1;
		else
			j = 0;
		i++;
	}
	if (j == 1)
	{
		e->degre = 2;
		ft_abc(e);
	}
	else
		ft_error(7);
}

void		det_polynome(t_struct *e)
{
	if (e->power_top == 2)
		pol_2_filter(e);
	else if (e->power_top > 2)
		ft_power_error(e);
	else if (e->power_top == 1)
		pol_1_filter(e);
	else if (e->power_top == 0)
		pol_0_filter(e);
	else if (e->power_top < 1)
		ft_error(8);
}
