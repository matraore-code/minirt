/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 05:50:23 by matraore          #+#    #+#             */
/*   Updated: 2020/10/29 04:19:01 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

const double epsilone = 0.00001;

t_tuple     point(double x, double y, double z)
{
    t_tuple t_point;

    t_point.x = x;
    t_point.y = y;
    t_point.z = z;
    t_point.w = 1;
    return (t_point);
}

t_tuple     vector(double x, double y, double z)
{
    t_tuple t_vect;

    t_vect.x = x;
    t_vect.y = y;
    t_vect.z = z;
    t_vect.w = 0;
    return (t_vect);
}

int         equal(double a, double b)
{
    double i;

    i = (fabs(a - b) < epsilone) ? 1 : 0;
    return (i);
}

int         comparingTuples(t_tuple a, t_tuple b)
{
    if(equal(a.x, b.x) && equal(a.y, b.y) && equal(a.z, b.z) && equal(a.w, b.w))
        return (1);
    return (0);
}


