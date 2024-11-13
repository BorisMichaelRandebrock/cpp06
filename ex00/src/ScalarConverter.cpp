/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:56:30 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/13 18:25:39 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp "

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy) {
	*this = cpy;
}

ScalarConverter &ScalarConverter::operator(const ScalarConverter &cpy) {
	(void)cpy;
	return *this;
}
ScalarConverter::~ScalarConverter() {};

void ScalarConverter::convert(const std::string &literal) {
	std::string specialTypes[6] = { 
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan" 
	}

	std::string	toChar = "";
	int 		toInt = 0;
	float		toFloat = 0;
	double		toDouble = 0;

	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		toChar = literal[0];

		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
	}
}


