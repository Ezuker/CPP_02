/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:45:07 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/13 13:54:31 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float    calcul_area(Point a, Point b, Point c)
{
    float x = a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat());
    float y = b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat());
    float z = c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat());
    float result = (x + y + z) / 2;
    if (result < 0)
        return (-result);
    return (result);
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    if (calcul_area(a, b, c) == calcul_area(a, b, point) + calcul_area(a, c, point) + calcul_area(b, c, point))
        return (true);
    return (false);
}