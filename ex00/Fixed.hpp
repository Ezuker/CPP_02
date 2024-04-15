/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:52:40 by bcarolle          #+#    #+#             */
/*   Updated: 2024/04/15 20:47:39 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &copy);
		~Fixed();

		Fixed &operator=(Fixed const &rhs);

		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int					_integer;
		static const int	_nbBits = 8;
};

#endif
