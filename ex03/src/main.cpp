/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:52:35 by bcarolle          #+#    #+#             */
/*   Updated: 2024/04/15 18:13:53 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
	Point	a(1.0f, 3.0f);
	Point	b(4.0f, 1.0f);
	Point	c(5.0f, 5.0f);
	Point	point1(3.36f, 3.18f);
	Point	point2(5.92f, 2.62f);

	std::cout << a.getX() << std::endl;
	std::cout << a.getY() << std::endl;
	std::cout << b.getX() << std::endl;
	std::cout << b.getY() << std::endl;
	if (bsp(a, b, c, point1))
		std::cout << "Is inside" << std::endl;
	else
		std::cout << "Is outside" << std::endl;
	if (bsp(a, b, c, point2))
		std::cout << "Is inside" << std::endl;
	else
		std::cout << "Is outside" << std::endl;
	return 0;
}
