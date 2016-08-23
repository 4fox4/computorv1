/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 14:57:25 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/19 19:53:35 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void		stock_form2(t_struct *e)
{
	if (e->e[e->j] == '+' && e->eg == 1)
	{
		e->forms[e->k][e->l] = '-';
		e->forms[e->k][e->l + 1] = ' ';
		e->l += 2;
		e->j += 2;
		e->forms[e->k][e->l] = e->e[e->j];
	}
	else if (e->e[e->j] == '-' && e->eg == 1)
	{
		e->forms[e->k][e->l] = '+';
		e->forms[e->k][e->l + 1] = ' ';
		e->l += 2;
		e->j += 2;
		e->forms[e->k][e->l] = e->e[e->j];
	}
	else
		e->forms[e->k][e->l] = e->e[e->j];
	e->j++;
	e->l++;
}

void		stock_form1(t_struct *e)
{
	if (e->j == 0 && ft_isdigit(e->e[e->j]) && e->eg == 0)
	{
		e->forms[e->k][e->l] = '+';
		e->forms[e->k][e->l + 1] = ' ';
		e->l += 2;
		e->forms[e->k][e->l] = e->e[e->j];
	}
	if (e->e[e->j] == '=' && e->e[e->j + 2] == '=' && !(e->e[e->j + 3]))
		ft_equal(e);
	if (e->e[e->j] == '=')
	{
		e->eg = 1;
		e->j += 2;
	}
	if ((ft_isdigit(e->e[e->j]) && e->e[e->j - 1] == ' ') && e->eg == 1)
	{
		e->forms[e->k][e->l] = '-';
		e->forms[e->k][e->l + 1] = ' ';
		e->l += 2;
		e->forms[e->k][e->l] = e->e[e->j];
	}
	stock_form2(e);
}

void		check_form(t_struct *e)
{
	if (ft_issign(e->e[e->i]) && e->e[e->i + 1] == ' ')
		e->i += 2;
	if (e->e[e->i] == '-' && e->e[e->i - 2] == '=')
		e->i += 2;
	if (e->e[e->i] == '0' && e->e[e->i - 2] == '=')
		ft_parse_nb2(e);
	if (ft_isdigit(e->e[e->i]))
	{
		while (ft_isdigit(e->e[e->i]) || e->e[e->i] == '.')
			e->i++;
		e->i++;
	}
	if (e->e[e->i] == '*' && e->e[e->i + 1] == ' ')
		e->i += 2;
	if (e->e[e->i] == 'X' && ft_isdigit(e->e[e->i + 2]))
		e->i += 2;
	while (e->e[e->i + 1] != ' ' && (e->e[e->i + 1]))
		e->i++;
}

int			ft_form_nb(t_struct *e)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (e->e[i])
	{
		if (e->e[i] == 'X')
			j++;
		i++;
	}
	e->nb_form = j;
	return (j);
}

void		ft_parse(t_struct *e)
{
	e->forms = (char**)malloc(sizeof(char*) * ft_form_nb(e) + 1);
	while (e->e[e->i])
	{
		check_form(e);
		if (e->e[e->i + 1] == ' ' || e->e[e->i + 1] == '\0')
		{
			e->forms[e->k] = (char*)malloc(sizeof(char) * (e->i - e->j) + 1);
			while (e->j <= e->i)
				stock_form1(e);
			e->forms[e->k][e->l] = '\0';
			e->k++;
			e->l = 0;
			if (!(e->e[e->i + 1]))
			{
				e->forms[e->k] = NULL;
				break ;
			}
			else
				e->i += 2;
			e->j++;
		}
	}
	ft_parse_nb2(e);
}
