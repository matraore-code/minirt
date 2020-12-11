/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:40:35 by matraore          #+#    #+#             */
/*   Updated: 2020/12/11 05:37:03 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H
# include "../tools/tools.h"

typedef	struct		s_tuple
{
	double x;
	double y;
	double z;
}					t_tuple;

t_tuple				*create_tuple(double x, double y, double z);
void				destroy_tuple(t_tuple **p);
double				magnetude_tuple(t_tuple *p);
t_tuple				*add_tuple(t_tuple *a, t_tuple *b);
t_tuple				*sub_tuple(t_tuple *a, t_tuple *b);
t_tuple				*scalar_tuple(t_tuple *p, double a);
t_tuple				*normalize_tuple(t_tuple *p);
double				dot_product(t_tuple *a, t_tuple *b);
t_tuple				*cross_product(t_tuple *a, t_tuple *b);

#endif
