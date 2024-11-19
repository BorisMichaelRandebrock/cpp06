/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:56:30 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/19 13:45:35 by brandebr         ###   ########.fr       */
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

Options stringEnum(const std::string &input) {
	if (input == "+inff") return PINFF;
	else if (input == "-inff") return NINFF;
	else if (input == "nanf") return NANF;
	else if (input == "+inf") return PINF;
	else if (input == "-inf") return NINF;
	else if (input == "nan") return INAN;
	else if (input == "inf") return DEF;
	else return OK; 
}

void ScalarConverter::convert(const std::string &literal) {
	std::string specialTypes[6] = {
		"+inff", "-inff", "nanf", "+inf", "-inf", "nan"
	};

	std::string toChar = "";
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;
	bool isSpecial = false;

	for (int i = 0; i < 6; ++i) {
		if (literal == specialTypes[i]) {
			isSpecial = true;
		}
	}

	if (isSpecial == true) {
		Options input = stringEnum(literal);
		switch(input) {
			case PINFF:
				std::cout << "char: " << RED << "impossible" << RESET << std::endl;
				std::cout << "int: " << RED << "impossible" << RESET << std::endl;
				std::cout << "float: " << GREEN << "inff" << RESET << std::endl;
				std::cout << "double: " << GREEN << "inf" << RESET << std::endl;
				return;
			case NINFF:
				std::cout << "char: " << RED << "impossible" << RESET << std::endl;
				std::cout << "int: " << RED << "impossible" << RESET << std::endl;
				std::cout << "float: " << GREEN << "-inff" << RESET << std::endl;
				std::cout << "double: " << GREEN << "-inf" << RESET << std::endl;
				return;
			case NANF:
				std::cout << "char: " << RED << "impossible" << RESET << std::endl;
				std::cout << "int: " << RED << "impossible" << RESET << std::endl;
				std::cout << "float: " << GREEN << "nanf" << RESET << std::endl;
				std::cout << "double: " << GREEN << "nan" << RESET << std::endl;
				return;
			case PINF:
				std::cout << "char: " << RED << "impossible" << RESET << std::endl;
				std::cout << "int: " << RED << "impossible" << RESET << std::endl;
				std::cout << "float: " << GREEN << "inff" << RESET << std::endl;
				std::cout << "double: " << GREEN << "inf" << RESET << std::endl;
				return;
			case NINF:
				std::cout << "char: " << RED << "impossible" << RESET << std::endl;
				std::cout << "int: " << RED << "impossible" << RESET << std::endl;
				std::cout << "float: " << GREEN << "-inff" << RESET << std::endl;
				std::cout << "double: " << GREEN << "-inf" << RESET << std::endl;
				return;
			case INAN:
				std::cout << "char: " << RED << "impossible" << RESET << std::endl;
				std::cout << "int: " << RED << "impossible" << RESET << std::endl;
				std::cout << "float: " << GREEN << "nanf" << RESET << std::endl;
				std::cout << "double: " << GREEN << "nan" << RESET << std::endl;
				return;
			default:
				break;
		}
	}

	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		toChar = literal[0];
		std::cout << "char: " << GREEN << toChar << RESET << std::endl;
		std::cout << "int: " << GREEN << static_cast<int>(toChar[0]) << RESET << std::endl;
		std::cout << "float: " << GREEN << static_cast<float>(toChar[0]) << ".0f" << RESET << std::endl;
		std::cout << "double: " << GREEN << static_cast<double>(toChar[0]) << ".0" << RESET << std::endl;
		return ;
	}

	if (literal.size() > 1 && std::isprint(literal[1]) && !std::isdigit(literal[1]) && literal[0] >= 'A' && literal[0] <= 'z') {
		std::cout << "char: " << RED << "impossible" << RESET << std::endl;
		std::cout << "int: " << RED << "impossible" << RESET << std::endl;
		std::cout << "float: " << RED << "impossible" << RESET << std::endl;
		std::cout << "double: " << RED << "impossible" << RESET << std::endl;
		return ;
	}
	
	std::istringstream iss(literal);

	if (toChar == "" && (toInt > 31 && toInt < 127)) {
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	} 
	else if (toChar == "")
		toChar = "Not printable";
try
{
toInt = std::atoi(literal.c_str());
toDouble = static_cast<double>(toInt);
toFloat = static_cast<float>(toDouble);
std::cout << "char: " << (toInt >= 32 && toInt <= 126 ? "\033[32m'" + std::string(1, static_cast<char>(toInt)) + "'\033[0m" : "\033[31mNot printable\033[0m") << std::endl;
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}
std::cout << "int: " << GREEN << toInt << RESET << std::endl;


	if (literal[literal.length() - 1] == 'f') 
	{
		toFloat = std::atof(literal.c_str());
		toDouble = static_cast<double>(toFloat);
	} else 
	{
		toDouble = std::atof(literal.c_str());
		toFloat = static_cast<float>(toDouble);
	}
if (toFloat == static_cast<int>(toFloat)) {
    std::cout << "float: " << GREEN << toFloat << ".0f" << RESET << std::endl;
} else {
    std::cout << "float: " << GREEN << toFloat << "f" << RESET << std::endl;
}

if (toDouble == static_cast<int>(toDouble)) {
    std::cout << "double: " << GREEN << toDouble << ".0" << RESET << std::endl;
} else {
    std::cout << "double: " << GREEN << toDouble << RESET << std::endl;
}
	return ;
}
