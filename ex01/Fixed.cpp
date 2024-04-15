/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:52:38 by bcarolle          #+#    #+#             */
/*   Updated: 2024/04/15 20:48:01 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _integer(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_integer = integer << Fixed::_nbBits;
}

Fixed::Fixed(float const floating_point)
{
	std::cout << "Float constructor called" << std::endl;
	this->_integer = (int)roundf(floating_point * (1 << Fixed::_nbBits));
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_integer = rhs.getRawBits();
	return (*this);
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
