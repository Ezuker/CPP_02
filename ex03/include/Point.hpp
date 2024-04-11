/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:42:12 by bcarolle          #+#    #+#             */
/*   Updated: 2024/04/11 12:09:27 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point{
	public:
		Point();
		Point(const float x, const float y);
		Point(Point const &copy);
		~Point();

		Point	&operator=(Point const &rhs);

		const Fixed	getX();
		const Fixed	getY();
	private:
		Fixed	_x;
		Fixed	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
