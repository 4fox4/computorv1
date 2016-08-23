/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 10:05:21 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/19 20:52:31 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# define DB(x) ft_putendl(x)

# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef struct		s_struct
{
	float			a;
	float			b;
	float			c;
	int				i;
	int				j;
	int				k;
	int				l;
	int				m;
	int				n;
	int				o;
	int				p;
	int				q;
	int				r;
	int				s;
	int				count;
	int				space;
	int				eg;
	float			delta;
	char			*e;
	char			**forms;
	int				degre;
	int				err;
	int				nb_form;
	float			**list_form;
	float			*list_pwr;
	float			**last_list;
	int				float_tablen;
	int				new_tablen;
	float			power_top;
	int				sol;
	float			x;
	float			x1;
	float			x2;
	float			tmp;
	char			**tmp2;
}					t_struct;

void				ft_parse(t_struct *e);
void				ft_delta(t_struct *e);
float				ft_power(float x, int y);
double				ft_sqrt(float n);
void				ft_second_deg(t_struct *e);
void				ft_premier_deg(t_struct *e);
int					ft_error(int err_code);
int					ft_str_match(char *str, char *find);
void				ft_init(t_struct *e);
void				ft_abc(t_struct *e);
void				ft_print_tab(t_struct *e);
void				ft_print_2nd_deg(t_struct *e);
void				ft_parse_nb2(t_struct *e);
void				power_top(t_struct *e);
void				det_polynome(t_struct *e);
void				print_2_sol(t_struct *e);
void				print_1_sol(t_struct *e);
void				print_no_sol(t_struct *e, float tmp);
void				ft_print_1st_deg(t_struct *e);
void				print_parse_nb(t_struct *e);
void				print_sol_deg_1(t_struct *e);
void				last_list(t_struct *e);
void				list_pwr(t_struct *e);
void				ft_equal(t_struct *e);
void				ft_print_no_deg(t_struct *e);
void				no_sol(t_struct *e);

#endif
