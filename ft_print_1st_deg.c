/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_1st_deg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 16:06:30 by houlekhi          #+#    #+#             */
/*   Updated: 2016/08/12 20:32:11 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void		equ_red_1(t_struct *e)
{
	if (e->b >= 0)
		printf("\033[36m+ %.2f \033[37m* X¹ ", e->b);
	else
		printf("\033[36m- %.2f \033[37m* X¹ ", -e->b);
	if (e->c >= 0)
		printf("\033[36m+ %.2f \033[37m* X⁰ = 0\n\033[35m", e->c);
	else
		printf("\033[36m- %.2f \033[37m* X⁰ = 0\n\033[35m", -e->c);
}

void		ft_print_1st_deg(t_struct *e)
{
	printf("\033[1m\n");
	printf("   Equation de base    |   %s\n\033[35m", e->e);
	ft_print_tab(e);
	printf("|\033[37m  Equation reduite    | ");
	equ_red_1(e);
	printf("|\033[37m  Equation format     | ");
	printf("a * X¹ + b * X⁰ = 0\n\033[0m");
	printf("\033[1m\033[35m|\033[36m");
	printf("                        ^         ^\n");
	printf("\033[35m|\n");
	printf("\033[35m`->\033[37m Nombre de formes : %d\n", e->nb_form);
	printf("\033[35m|\n");
	print_parse_nb(e);
	printf("\033[37mPolynome de degre : %d\n\n", e->degre);
	printf("\033[36ma = %.2f\n", e->b);
	printf("\033[36mb = %.2f\n\n", e->c);
	print_sol_deg_1(e);
}
