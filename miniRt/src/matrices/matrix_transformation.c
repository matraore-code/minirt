/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:38:39 by matraore          #+#    #+#             */
/*   Updated: 2020/11/03 10:38:40 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "matrix_transformation.h"

t_matrice translation (int x, int y, int z)
{
    t_matrice m;

    m = identity_matrix ();
    m->d[0][3] = x;
    m->d[1][3] = y;
    m->d[2][3] = z;
    return (m);
}

t_matrice scaling (int x, int y, int z)
{
    t_matrice m;

    m = identity_matrix ();
    m->d[0][0] = x;
    m->d[1][1] = y;
    m->d[2][2] = z;
    return (m);
}

t_matrice rotation_x (double degree)
{
    t_matrice m;

    m = identity_matrix ();
    m->d[1][1] = cos (degree);
    m->d[1][2] = sin (degree) * (-1);
    m->d[2][1] = sin (degree);
    m->d[2][2] = cos (degree);
    return (m);
}

t_matrice rotation_y (double degree)
{
    t_matrice m;

    m = identity_matrix ();
    m->d[0][0] = cos (degree);
    m->d[0][2] = sin (degree);
    m->d[2][0] = sin (degree) * -1;
    m->d[2][2] = cos (degree);
    return (m);
}

t_matrice rotation_z (double degree)
{
    t_matrice m;

    m = identity_matrix ();
    m->d[0][0] = cos (degree);
    m->d[0][1] = sin (degree) * -1;
    m->d[1][0] = sin (degree);
    m->d[1][1] = cos (degree);
    return (m);
}

t_matrice shearing (int x_y, int x_z, int y_x, int y_z, int z_x, int z_y)
{
    t_matrice m;

    m = identity_matrix ();
    m->d[0][1] = x_y;
    m->d[0][2] = x_z;
    m->d[1][0] = y_x;
    m->d[1][2] = y_z;
    m->d[2][0] = z_x;
    m->d[2][1] = z_y;
    matrix_debug (m);
    return (m);
}