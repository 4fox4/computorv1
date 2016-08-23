/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 10:05:17 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/19 20:55:28 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void			check_valid2(t_struct *e, char *arg)
{
	if (arg[e->s] == '*' && arg[e->s + 1] == ' ')
		e->s += 2;
	else
		ft_error(1);
	if (arg[e->s] == 'X' && arg[e->s + 1] == '^' && ft_isdigit(arg[e->s + 2]))
		e->s += 2;
	else
		ft_error(1);
	while (arg[e->s + 1] != ' ' && (arg[e->s + 1]))
		e->s++;
	if (arg[e->s + 1] == ' ' && ft_issign(arg[e->s + 2]))
		e->s += 2;
}

void			check_valid(t_struct *e, char *arg)
{
	while (arg[e->s] && arg[e->s] != '\0')
	{
		if (ft_issign(arg[e->s]) && arg[e->s + 1] == ' ')
			e->s += 2;
		if (arg[e->s] == '-' && arg[e->s - 2] == '=')
			e->s += 2;
		if (arg[e->s] == '0' && arg[e->s - 2] == '=' && !(arg[e->s + 1]))
			break ;
		if (ft_isdigit(arg[e->s]))
		{
			while (ft_isdigit(arg[e->s]) || arg[e->s] == '.')
				e->s++;
			if (arg[e->s] != ' ')
				ft_error(1);
			e->s++;
		}
		check_valid2(e, arg);
		if (!arg[e->s + 1])
			break ;
	}
	if (arg[0] == '\0')
		ft_error(10);
}

int				main(int argc, char **argv)
{
	t_struct	e;

	e.s = 0;
	if (argc == 2)
	{
		check_valid(&e, argv[1]);
		e.e = argv[1];
		ft_init(&e);
		ft_parse(&e);
	}
	ft_putchar('\n');
	return (0);
}
