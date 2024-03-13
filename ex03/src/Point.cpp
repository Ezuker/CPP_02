/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:46:09 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/12 17:00:56 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
    this->_x = Fixed();
    this->_y = Fixed();
}

Point::Point(const float x, const float y)
{
    this->_x = Fixed(x);
    this->_y = Fixed(y);
}

Point::Point(const Point &copy)
{
    *this = copy;
}

Point::~Point()
{
}

Point    &Point::operator=(const Point &rhs)
{
    this->_x = rhs._x;
    this->_y = rhs._y;
    return (*this);
}

const Fixed   Point::getX()
{
    return (this->_x);
}

const Fixed   Point::getY()
{
    return (this->_y);
}