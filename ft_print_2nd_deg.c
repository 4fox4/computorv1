/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2nd_deg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 14:25:48 by houlekhi          #+#    #+#             */
/*   Updated: 2016/08/23 02:34:10 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void		ft_print_tab(t_struct *e)
{
	int		i;

	i = 0;
	printf(".-\033[37m Equation simplifiee | ");
	while (i < e->nb_form)
	{
		printf("%s ", e->forms[i]);
		i++;
	}
	printf("= 0\n\033[35m");
}

void		print_delta_sol(t_struct *e)
{
	printf("\033[32mΔ = (b)² - 4 * (a) * (c)\n");
	printf("Δ = (%.2f)² - 4 * (%.2f) * (%.2f)\n", e->b, e->a, e->c);
	printf("Δ = %.2f\n\n", e->delta);
	if (e->delta < 0.0)
		no_sol(e);
	if (e->delta == 0.0)
		print_1_sol(e);
	if (e->delta > 0.0)
		print_2_sol(e);
}

void		equ_red_2(t_struct *e)
{
	if (e->a >= 0)
		printf("\033[36m+ %.2f \033[37m* X² ", e->a);
	else
		printf("\033[36m- %.2f \033[37m* X² ", -e->a);
	if (e->b >= 0)
		printf("\033[36m+ %.2f \033[37m* X¹ ", e->b);
	else
		printf("\033[36m- %.2f \033[37m* X¹ ", -e->b);
	if (e->c >= 0)
		printf("\033[36m+ %.2f \033[37m* X⁰ = 0\n\033[35m", e->c);
	else
		printf("\033[36m- %.2f \033[37m* X⁰ = 0\n\033[35m", -e->c);
}

void		print_parse_nb(t_struct *e)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (i < e->nb_form)
	{
		printf("`-> Forme %d : %s\n", i + 1, e->forms[i]);
		printf("     Extraction du nombre : %s\n", e->tmp2[k]);
		i++;
		k += 2;
	}
	printf("\n");
}

void		ft_print_2nd_deg(t_struct *e)
{
	printf("\033[1m\n");
	printf("   Equation de base    |   %s\n\033[35m", e->e);
	ft_print_tab(e);
	printf("|\033[37m  Equation reduite    | ");
	equ_red_2(e);
	printf("|\033[37m  Equation format     | ");
	printf("a * X² + b * X¹ + c * X⁰ = 0\n\033[0m");
	printf("\033[1m\033[35m|\033[36m");
	printf("                        ^        ^        ^\n");
	printf("\033[35m|\n");
	printf("\033[35m`->\033[37m Nombre de formes : %d\n", e->nb_form);
	printf("\033[35m|\n");
	print_parse_nb(e);
	printf("\033[37mPolynome de degre : %d\n\n", e->degre);
	printf("\033[36ma = %.2f\n", e->a);
	printf("\033[36mb = %.2f\n", e->b);
	printf("\033[36mc = %.2f\n\n", e->c);
	print_delta_sol(e);
}
