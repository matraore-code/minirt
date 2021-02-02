/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:32:10 by matraore          #+#    #+#             */
/*   Updated: 2021/01/31 10:07:19 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include <math.h>

typedef struct	s_tuple
{
	double		x;
	double		y;
	double		z;
}				t_tuple;

typedef struct	s_matrix
{
	double		d[4][4];
}				t_matrix;

t_tuple			create_tuple(double x, double y, double z);
double			vector_len(t_tuple vector);
double			dot_product(t_tuple a, t_tuple b);
t_tuple			substract(t_tuple vec1, t_tuple vec2);
void			normalize_vector(t_tuple *vector);
t_tuple			tuple_add(t_tuple vec1, t_tuple vec2);
t_tuple			tuple_multiply(t_tuple vec1, double x);
t_tuple			cross_product(t_tuple a, t_tuple b);
t_tuple			multiply_by_matrix(t_tuple p, t_matrix m);
t_matrix		look_at(t_tuple origin, t_tuple cam_vector);

#endif
