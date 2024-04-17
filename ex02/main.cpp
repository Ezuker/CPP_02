/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:52:35 by bcarolle          #+#    #+#             */
/*   Updated: 2024/04/17 17:09:35 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << "max is " << Fixed::max( a, b ) << std::endl;
	std::cout << "min is " << Fixed::min( a, b ) << std::endl; 

	Fixed	c(-10.20f);
	Fixed	d(11.20f);
	if (c > d)
		std::cout << "C is superior to D" << std::endl;
	if (d > c)
		std::cout << "D is superior to C" << std::endl;
		
	Fixed	e(10.20f);

	if (c == e)
		std::cout << "C is equal to E" << std::endl;
	if (c != d)
		std::cout << "C is not equal to D" << std::endl;

	if (c >= e)
		std::cout << "C is superior or equal to E" << std::endl;
	c++;
	if (c <= e)
		std::cout << "C is inferior or equal to E" << std::endl;

	std::cout << c * e << std::endl;
	std::cout << c << std::endl;
	std::cout << c / e << std::endl;
	std::cout << c + e << std::endl;
	std::cout << c - e << std::endl;

	return 0;
}
