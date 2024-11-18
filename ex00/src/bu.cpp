/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:56:30 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/14 19:31:04 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy) {
	*this = cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy) {
	(void)cpy;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal) {
	std::string specialTypes[6] = { 
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan" 
	};

	std::string	toChar = "";
	int 		toInt = 0;
	float		toFloat = 0;
	double		toDouble = 0;
	bool 		isSpecial = false;
	char 		buffer[50];

	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		toChar = literal[0];

		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
		return ;
	}
	toInt = std::atoi(literal.c_str());

	if (literal[literal.length() -1] == 'f') {
		toDouble = static_cast<double>(std::atof(literal.c_str()));
		toFloat = static_cast<float>(toDouble);
	} 
	else {
		toDouble = std::atof(literal.c_str());
		toFloat = static_cast<float>(toDouble);
	}

	for (int i = 0; i < 6; ++i) {
		if (literal == specialTypes[i]) {
			toChar = "impossible";
			isSpecial = true;
			break;
		}
	}

	if (toChar == "" && (toInt > 31 && toInt < 127)) {
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	} 
	else if (toChar == "")
		toChar = "Not printable";

	std::cout << "char: " << toChar << std::endl;

	if (toChar == "impossible")
		std::cout << "int: " << toChar << std::endl;
	else 
		std::cout << "int: " << toInt << std::endl;

	if (toChar == "impossible" && isSpecial) {
		std::cout << "float: " << toFloat << std::endl;
		std::cout << "double: " << toDouble << std::endl;
	} else {
		if (toFloat >= FLT_MAX || toFloat <= -FLT_MAX) {
			std::sprintf(buffer, "%.1ff", toFloat);
		} else if (toChar == "impossible" && toFloat == static_cast<int>(toFloat)) {
			std::sprintf(buffer, "%.1ff", toFloat);
		} else {
			std::sprintf(buffer, "%.6ff", toFloat);
		}
		std::cout << "float: " << buffer << std::endl;
		if (toDouble == static_cast<int>(toDouble)) {
			std::sprintf(buffer, "%.1f", toDouble);
		} else {
			std::sprintf(buffer, "%.6f", toDouble);
		}
		std::cout << "double: " << buffer << std::endl;
	}
}


