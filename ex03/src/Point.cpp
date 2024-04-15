/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:46:09 by bcarolle          #+#    #+#             */
/*   Updated: 2024/04/15 18:19:19 by bcarolle         ###   ########.fr       */
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
	(Fixed)this->_y = copy.getY();
	(Fixed)this->_x = copy.getX();
}

Point::~Point()
{
}

Point	&Point::operator=( Point &rhs)
{
	(Fixed)this->_y = rhs.getY();
	(Fixed)this->_x = rhs.getX();
	return (*this);
}

Fixed	Point::getX() const
{
	return (this->_x);
}

Fixed	Point::getY() const
{
	return (this->_y);
}
