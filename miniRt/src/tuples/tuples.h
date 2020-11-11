/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:00:03 by matraore          #+#    #+#             */
/*   Updated: 2020/11/11 05:25:38 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../utils/libft/libft.h"
#include "../utils/tools/tools.h"


typedef struct tuples {
    double x;
    double y;
    double z;
    double w;
} t_tuple;

typedef struct colorvec {
    float red;
    float green;
    float blue;
} colorVec;

// A tuple with w=1.0 is a point
// A tuple with w=0.0 is a vector
t_tuple point(double x, double y, double z);
t_tuple create_tuple(double x, double y, double z,  double w);
t_tuple vector(double x, double y, double z);
int equal(double a, double b);
int comparingTuples(t_tuple a, t_tuple b);
double scalarTuples(t_tuple a, t_tuple b);
t_tuple normalizeVector(t_tuple vect);
double magnetudeVector(t_tuple vect);
t_tuple crossTuples(t_tuple a, t_tuple b);
t_tuple sumTuples(t_tuple a, t_tuple b);
t_tuple subTuples(t_tuple a, t_tuple b);
t_tuple multiTuples(double a, t_tuple b);
t_tuple divTuples(double a, t_tuple b);

//color implementation 
colorVec color(float red, float green, float blue);
colorVec addingColor(colorVec c, colorVec d);
colorVec subColor(colorVec c, colorVec d);
colorVec multipColor(colorVec c, colorVec d);
colorVec scalarColor(float c, colorVec d);
#endif