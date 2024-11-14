/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:15:03 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/14 19:29:15 by brandebr         ###   ########.fr       */
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
#include <cstdio>
#include <float.h>
#include <cmath>

#define RESET   "\033[0m"
#define BOLD     "\033[1m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"


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
