/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:38:49 by matraore          #+#    #+#             */
/*   Updated: 2020/11/03 10:38:50 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "matrices.h"

#include <math.h>

#define PI 3.141593

t_matrice translation (int x, int y, int z);

t_matrice scaling (int x, int y, int z);

/*
** rotation around the x axis
*/
t_matrice rotation_x (double degree);

/*
**  rotation around the y axis 
*/

t_matrice rotation_y (double degree);

/*
**  rotation around the z axis 
*/

t_matrice rotation_z (double degree);

t_matrice shearing (int x_y, int x_z, int y_x, int y_z, int z_x, int z_y);
