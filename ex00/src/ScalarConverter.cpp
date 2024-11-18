/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:56:30 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/18 17:05:34 by brandebr         ###   ########.fr       */
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

	std::string	toChar = "";
	int 		toInt = 0;
	float		toFloat = 0;
	double		toDouble = 0;
	bool 		isSpecial = false;
	//	char 		buffer[50];
	//
	for (int i = 0; i < 6; ++i) {
		if (literal == specialTypes[i]) {
			isSpecial = true;
		}
	}

	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		toChar = literal[0];

		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
		return ;
	}
		if (isSpecial == false && (literal.size() > 1 && std::isprint(literal[1]) && !std::isdigit(literal[1]))) {
		//toChar = literal[1];

		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "impossible" << std::endl;
		std::cout << "double: " << "impossible" << std::endl;
		return ;
		}


	std::istringstream iss(literal);
	if (iss >> toInt) {
		toDouble = static_cast<double>(toInt);
		toFloat = static_cast<float>(toDouble);
		std::cout << "char: " << (toInt >= 32 && toInt <= 126 ? "'" + std::string(1, static_cast<char>(toInt)) + "'" : "Not printable") << std::endl;
		std::cout << "int: " << toInt << std::endl;

		// Use setprecision and fixed to control the number of decimal places printed
		std::cout << std::fixed << std::setprecision(1); // corrected
		std::cout << "float: " << toFloat << "f" << std::endl; // corrected

		std::cout << std::fixed << std::setprecision(1); // corrected
		std::cout << "double: " << toDouble << std::endl; // corrected
		return;
	}



	if (toInt > 31 && toInt < 127) {
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	} else if (toChar == "")
		toChar = "Not printable";

	std::cout << "char: " << toChar << std::endl;
	std::cout << "int: " << toInt << std::endl;


	std::stringstream ss;

	size_t dotPos = literal.find('.');  // To check if there's a decimal point in the input
	size_t precision = 0;

	if (dotPos != std::string::npos) {
		precision = literal.size() - dotPos - 1;
		if (literal[literal.size() -1] == 'f') --precision; // Adjust for 'f' in float literals
	}
	ss.str("");
	ss.clear();
	if (isSpecial == true) {
		Options input = stringEnum(literal);
		switch(input) {
			case PINFF:
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: inff" << std::endl;
				std::cout << "double: inf" << std::endl;
				return;
			case NINFF:
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
				return;
			case NANF:
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: nanf" << std::endl;
				std::cout << "double: nan" << std::endl;
				return;
			case PINF:
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: inff" << std::endl;
				std::cout << "double: inf" << std::endl;
				return;
			case NINF:
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
				return;
			case INAN:
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: nanf" << std::endl;
				std::cout << "double: nan" << std::endl;
				return;
			default:
				break;
		}

	}

	if (toInt > 16777216L && toInt <= 2147483647L) {
		ss << std::fixed << toInt << ".0f";
	} else if (toFloat == static_cast<int>(toFloat) || toFloat - static_cast<int>(toFloat) < 1e-6) {
		ss << std::fixed << std::setprecision(precision) << toFloat << ".0f";
	} else {
		ss << std::fixed << std::setprecision(precision) << toFloat << "f";
	}
	std::cout << "float: " << ss.str() << std::endl;

	ss.str("");
	ss.clear();

	if (toDouble == static_cast<int>(toDouble) || toDouble - static_cast<int>(toDouble) < 1e-6) {
		ss << std::fixed << std::setprecision(precision) << toDouble << ".0";
	} else {
		ss << std::fixed << std::setprecision(precision) << toDouble ;
	}
	std::cout << "double: " << ss.str() << std::endl;
}

/*
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
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: inff" << std::endl;
                std::cout << "double: inf" << std::endl;
                return;
            case NINFF:
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: -inff" << std::endl;
                std::cout << "double: -inf" << std::endl;
                return;
            case NANF:
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: nanf" << std::endl;
                std::cout << "double: nan" << std::endl;
                return;
            case PINF:
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: inff" << std::endl;
                std::cout << "double: inf" << std::endl;
                return;
            case NINF:
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: -inff" << std::endl;
                std::cout << "double: -inf" << std::endl;
                return;
            case INAN:
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: nanf" << std::endl;
                std::cout << "double: nan" << std::endl;
                return;
            default:
                break;
        }
    }

    // Handling single character input
    if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        toChar = literal[0];
        std::cout << "char: " << toChar << std::endl;
        std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
        return ;
    }

    // Handling invalid input and characters
    if (literal.size() > 1 && !std::isdigit(literal[0])) {
        toChar = literal[0];
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }

    std::istringstream iss(literal);
    if (iss >> toInt) {
        toDouble = static_cast<double>(toInt);
        toFloat = static_cast<float>(toDouble);
        std::cout << "char: " << (toInt >= 32 && toInt <= 126 ? "'" + std::string(1, static_cast<char>(toInt)) + "'" : "Not printable") << std::endl;
        std::cout << "int: " << toInt << std::endl;

        // Output float and double with dynamic precision
        std::cout << "float: " << toFloat << "f" << std::endl;
        std::cout << "double: " << toDouble << std::endl;
        return;
    }

    // Handling float/double input
    size_t dotPos = literal.find('.');  // To check if there's a decimal point in the input
    size_t precision = 0;

    if (dotPos != std::string::npos) {
        precision = literal.size() - dotPos - 1;
        if (literal[literal.size() - 1] == 'f') --precision; // Adjust for 'f' in float literals
    }

    std::stringstream ss;
    ss << std::fixed;  // Use fixed notation for both float and double

    // Output float with dynamic precision
    ss << std::setprecision(precision) << toFloat << "f";
    std::cout << "float: " << ss.str() << std::endl;

    // Reset stringstream and adjust for double precision
    ss.str("");
    ss.clear();
    ss << std::fixed << std::setprecision(precision) << toDouble;
    std::cout << "double: " << ss.str() << std::endl;
}*/
