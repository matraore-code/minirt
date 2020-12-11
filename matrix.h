/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 05:37:53 by matraore          #+#    #+#             */
/*   Updated: 2020/12/11 06:01:11 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MATRIX_H
# define MATRIX_H

# include "../tuples/tuples.h"
# include "../tools/tools.h"

typedef	struct	s_matrix
{
	int			dim;
	double		*entries;
}				t_mat;

t_mat			*create_matrix(int i);

#endif
