/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 12:32:44 by houlekhi          #+#    #+#             */
/*   Updated: 2016/08/12 20:33:03 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void		print_sol_deg_1(t_struct *e)
{
	printf("\033[31mPolynome du 1er degre donc 1 solution possible :\n\n");
	printf(" X = \033[4m- (b)\n");
	printf("\033[0m\033[31m\033[1m      (a)\n");
	printf(" X = \033[4m- (%.1f)\n", e->c);
	printf("\033[0m\033[31m\033[1m      (%.1f)\n", e->b);
	printf(" X = %.3f\n\n", e->x);
}

void		print_2_sol(t_struct *e)
{
	printf("Δ > 0,\033[31m donc 2 solutions possibles :\n\n");
	printf(" X1 = \033[4m- (b) + √(Δ)\n");
	printf("\033[0m\033[31m\033[1m         2 * (a)\n");
	printf(" X1 = \033[4m- (%.1f) + √(%.1f)\n", e->b, e->delta);
	printf("\033[0m\033[31m\033[1m         2 * (%.1f)\n", e->a);
	printf(" X1 = %.3f\n\n\n", e->x1);
	printf(" X2 = \033[4m- (b) - √(Δ)\n");
	printf("\033[0m\033[31m\033[1m         2 * (a)\n");
	printf(" X2 = \033[4m- (%.1f) - √(%.1f)\n", e->b, e->delta);
	printf("\033[0m\033[31m\033[1m         2 * (%.1f)\n", e->a);
	printf(" X2 = %.3f\n", e->x2);
}

void		print_1_sol(t_struct *e)
{
	printf("Δ = 0,\033[31m donc 1 solution possible :\n\n");
	printf(" X = \033[4m- (b)  \n");
	printf("\033[0m\033[31m\033[1m     2 * (a)\n");
	printf(" X = \033[4m - (%.1f) \n", e->b);
	printf("\033[0m\033[31m\033[1m     2 * (%.1f)\n", e->a);
	printf(" X = %.3f\n\n", e->x);
}

void		print_no_sol(t_struct *e, float tmp)
{
	printf("Δ < 0,\033[31m donc 2 solutions complexes possibles :\n\n");
	printf(" X1 = \033[4m- (b) + i * √(|Δ|)\n");
	printf("\033[0m\033[31m\033[1m         2 * (a)\n");
	printf(" X1 = \033[4m- (%.1f) + i * √(%.1f)\n", e->b, -e->delta);
	printf("\033[0m\033[31m\033[1m         2 * (%.1f)\n", e->a);
	printf(" X1 = %.3f + i * %.3f\n\n\n", tmp, e->x1);
	printf(" X2 = \033[4m- (b) - i * √(|Δ|)\n");
	printf("\033[0m\033[31m\033[1m         2 * (a)\n");
	printf(" X2 = \033[4m- (%.1f) - i * √(%.1f)\n", e->b, -e->delta);
	printf("\033[0m\033[31m\033[1m         2 * (%.1f)\n", e->a);
	printf(" X1 = %.3f + i * %.3f\n\n", tmp, e->x1);
}

void		no_sol(t_struct *e)
{
	float	tmp;

	tmp = (-e->b) / (2 * e->a);
	e->x1 = (ft_sqrt(-e->delta)) / (2 * e->a);
	e->x2 = -((ft_sqrt(-e->delta)) / (2 * e->a));
	print_no_sol(e, tmp);
}
