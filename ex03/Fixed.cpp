/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:52:38 by bcarolle          #+#    #+#             */
/*   Updated: 2024/04/15 20:48:16 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _integer(0)
{
}

Fixed::Fixed(int const integer)
{
	this->_integer = integer << Fixed::_nbBits;
}

Fixed::Fixed(float const floating_point)
{
	this->_integer = (int)roundf(floating_point * (1 << Fixed::_nbBits));
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	this->_integer = rhs.getRawBits();
	return (*this);
}

float	Fixed::operator+(Fixed const &rhs)
{
	float result = this->toFloat() + rhs.toFloat();
	return (result);
}

float	Fixed::operator-(Fixed const &rhs)
{
	float result = this->toFloat() - rhs.toFloat();
	return (result);
}

float	Fixed::operator*(Fixed const &rhs)
{
	float result = this->toFloat() * rhs.toFloat();
	return (result);
}

float	Fixed::operator/(Fixed const &rhs)
{
	float result = this->toFloat() / rhs.toFloat();
	return (result);
}

int	Fixed::operator>(Fixed &rhs)
{
	if (this->_integer > rhs.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator<(Fixed &rhs)
{
	if (this->_integer < rhs.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator>=(Fixed &rhs)
{
	if (this->_integer >= rhs.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator<=(Fixed &rhs)
{
	if (this->_integer <= rhs.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator==(Fixed &rhs)
{
	if (this->_integer == rhs.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator!=(Fixed &rhs)
{
	if (this->_integer != rhs.getRawBits())
		return (1);
	return (0);
}

//Prefix operator 
Fixed	&Fixed::operator++()
{
	this->_integer++;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	this->_integer--;
	return (*this);
}

//Postfix operator
Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++*this;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--*this;
	return (tmp);
}

int	Fixed::getRawBits() const
{
	return (this->_integer);
}

void	Fixed::setRawBits(int const raw)
{
	this->_integer = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->_integer) / (float)(1 << Fixed::_nbBits));
}

int	Fixed::toInt(void) const
{
	return (this->_integer >> Fixed::_nbBits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
