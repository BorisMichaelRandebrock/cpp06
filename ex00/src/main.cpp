/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:16:17 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/14 13:34:11 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << RED << "Error: no literals entered" << std::endl
			<< GREEN << "Please enter: program & literals." << RESET << std::endl;
		return 1;
	}
	else if (argc > 2) {
		std::cout << RED << "Error: too many arguments" << std::endl
			<< GREEN << "Please enter: program & literals." << RESET << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}


