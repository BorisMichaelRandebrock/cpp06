/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:15:03 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/20 12:08:58 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <limits>
#include <cstdio>
#include <float.h>
#include <cmath>
#include <iomanip>
#include <sstream>

#define RESET   "\033[0m"
#define BOLD     "\033[1m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"

enum	Options {
	PINFF,
	NINFF,
	NANF,
	PINF,
	NINF,
	INAN,
	DEF,
	OK
};

class ScalarConverter {
	private:
		std::string _char;
	//	int			_number;
	//	float		_float;
	//	double		_double;

		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);

	public:
		~ScalarConverter();
		static void convert(const std::string &literal);
};
#endif
