/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:46:09 by bcarolle          #+#    #+#             */
/*   Updated: 2024/04/13 18:32:51 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)) , _y(Fixed(0))
{
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(const Point &copy)
{
	*this = copy;
}

Point::~Point()
{
}

Point	&Point::operator=(const Point &rhs)
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	return (*this);
}

Fixed	Point::getX()
{
	return (this->_x);
}

Fixed	Point::getY()
{
	return (this->_y);
}
