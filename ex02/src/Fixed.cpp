/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:52:38 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/10 16:30:52 by bcarolle         ###   ########.fr       */
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
	this->_integer = copy._integer;
	setRawBits(copy.getRawBits());
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	this->_integer = rhs._integer;
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed	&Fixed::operator+(Fixed const &rhs)
{
	*this = this->toFloat() + rhs.toFloat();
	return (*this);
}

Fixed	&Fixed::operator-(Fixed const &rhs)
{
	*this = this->toFloat() - rhs.toFloat();
	return (*this);
}

Fixed	&Fixed::operator*(Fixed const &rhs)
{
	*this = this->toFloat() * rhs.toFloat();
	return (*this);
}

Fixed	&Fixed::operator/(Fixed const &rhs)
{
	*this = this->toFloat() / rhs.toFloat();
	return (*this);
}

int	Fixed::operator>(Fixed &rhs)
{
	if (this->_integer > rhs._integer)
		return (1);
	return (0);
}

int	Fixed::operator<(Fixed &rhs)
{
	if (this->_integer < rhs._integer)
		return (1);
	return (0);
}

int	Fixed::operator>=(Fixed &rhs)
{
	if (this->_integer >= rhs._integer)
		return (1);
	return (0);
}

int	Fixed::operator<=(Fixed &rhs)
{
	if (this->_integer <= rhs._integer)
		return (1);
	return (0);
}

int	Fixed::operator==(Fixed &rhs)
{
	if (this->_integer == rhs._integer)
		return (1);
	return (0);
}

int	Fixed::operator!=(Fixed &rhs)
{
	if (this->_integer != rhs._integer)
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
	return ((float)(this->getRawBits()) / (float)(1 << Fixed::_nbBits));
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> Fixed::_nbBits);
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

Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._integer > b._integer)
		return (const_cast<Fixed &>(a));
	return (const_cast<Fixed &>(b));
}

Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._integer < b._integer)
		return (const_cast<Fixed &>(a));
	return (const_cast<Fixed &>(b));
}

int	Fixed::_nbBits = 8;
