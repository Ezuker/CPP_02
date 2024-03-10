/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:52:40 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/10 15:28:49 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(int const integer);
		Fixed(float const floating_point);
		Fixed(Fixed const &copy);
		~Fixed();

		Fixed	&operator=(Fixed const &rhs);
		Fixed	&operator<<(std::ostream &o, Fixed const &rhs);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

	private:
		int			_integer;
		static int	_nbBits;
};

#endif
