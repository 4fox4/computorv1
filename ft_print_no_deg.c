/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_no_deg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 11:21:03 by houlekhi          #+#    #+#             */
/*   Updated: 2016/08/12 20:32:04 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void		print_sol_deg_0(t_struct *e)
{
	printf("\n\033[31m a * X⁰ = 0\n");
	printf(" %.1f * X⁰ = 0\n", e->c);
	printf(" %.1f * 1 = 0\n", e->c);
	printf(" %.1f = 0\n\n", e->c);
	if (e->last_list[0][1] == 0 && e->last_list[0][0] == 0)
		printf("0 = 0, Donc la solution comprend tout nombre reel\n\n");
	else if (e->last_list[0][1] == 0 && e->last_list[0][0] != 0)
		printf("Equation insolvable. Donc aucune solution possible\n\n");
}

void		equ_red_0(t_struct *e)
{
	if (e->c >= 0)
		printf("\033[36m+ %.2f \033[37m* X⁰ = 0\n\033[35m", e->c);
	else
		printf("\033[36m- %.2f \033[37m* X⁰ = 0\n\033[35m", -e->c);
}

void		ft_print_no_deg(t_struct *e)
{
	printf("\033[1m\n");
	printf("   Eqution de base  |   %s\n\033[35m", e->e);
	ft_print_tab(e);
	printf("|\033[37m  Eqution reduite  | ");
	equ_red_0(e);
	printf("|\033[37m  Eqution format   | ");
	printf("a * X⁰ = 0\n\033[0m");
	printf("\033[1m\033[35m|\033[36m");
	printf("                     ^\n");
	printf("\033[35m|\n");
	printf("\033[35m`->\033[37m Nombre de formes : %d\n", e->nb_form);
	printf("\033[35m|\n");
	print_parse_nb(e);
	printf("\033[37mPolynome de degre : %d\n\n", e->degre);
	printf("\033[36ma = %.2f\n", e->c);
	print_sol_deg_0(e);
	exit(0);
}
