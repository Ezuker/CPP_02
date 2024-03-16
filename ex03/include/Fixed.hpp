/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:52:40 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/16 15:26:55 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>
class Fixed
{
	public:
		Fixed();
		Fixed(int const integer);
		Fixed(float const floating_point);
		Fixed(Fixed const &copy);
		~Fixed();

		Fixed	&operator=(Fixed const &rhs);
		float	operator+(Fixed const &rhs);
		float	operator-(Fixed const &rhs);
		float	operator*(Fixed const &rhs);
		float	operator/(Fixed const &rhs);
		int		operator>(Fixed &rhs);
		int		operator<(Fixed &rhs);
		int		operator>=(Fixed &rhs);
		int		operator<=(Fixed &rhs);
		int		operator==(Fixed &rhs);
		int		operator!=(Fixed &rhs);
		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static Fixed	&max(const Fixed &a, const Fixed &b);
		static Fixed	&min(const Fixed &a, const Fixed &b);



	private:
		int			_integer;
		static int	_nbBits;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);
#endif