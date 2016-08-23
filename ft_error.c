/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 13:33:15 by houlekhi          #+#    #+#             */
/*   Updated: 2016/08/12 20:24:50 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

int			ft_error(int err_code)
{
	if (err_code == 1)
		printf("\033[1m\033[31mEqution au format non valide\n");
	if (err_code == 2)
		printf("\033[1m\033[31mPolynome > 2eme degre non supporte\n");
	if (err_code == 3)
		printf("\033[1m\033[31mDelta indetermine, equation non soluble\n");
	if (err_code == 4)
		printf("Δ < 0,\033[1m\033[31m donc il n'y a aucune solution\n\n");
	if (err_code == 5)
		printf("\033[1m\033[31mValeurs de a, b et c non determinees\n");
	if (err_code == 6)
		printf("\033[1m\033[31mL'equation n'a pu etre determinee\n");
	if (err_code == 7)
		printf("\033[1m\033[31mPolynome non valide\n");
	if (err_code == 8)
		printf("\033[1m\033[31mErreur lors de la verification du polynome\n");
	if (err_code == 9)
		printf("\033[1m\033[31mErreur resolution polynome de degre 0\n");
	if (err_code == 10)
		printf("\033[1m\033[31mVeuillez entrer une equation en argument\n");
	exit(0);
}
