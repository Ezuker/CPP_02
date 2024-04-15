/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:52:40 by bcarolle          #+#    #+#             */
/*   Updated: 2024/04/15 20:47:43 by bcarolle         ###   ########.fr       */
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

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

	private:
		int					_integer;
		static const int	_nbBits = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);
#endif
