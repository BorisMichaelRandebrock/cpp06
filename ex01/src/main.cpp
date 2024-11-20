/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:55:48 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/20 18:01:58 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <unistd.h>

int main() {
	std::cout << "\033[2J\033[1;1H";
	std::cout << GREEN << "Welcome to the Hitchhiker's Guide to the Galaxy Serialization Program!" << RESET << std::endl << std::endl;
	sleep(1);
    std::cout << BOLD << "Today, we'll serialize and deserialize our favorite intergalactic hitchhikers." << RESET << std::endl << std::endl;

	sleep(1);
    std::cout << std::endl << "******************************************" << std::endl << std::endl;
    Data zaphod;
    zaphod.firstName = "Zaphod";
    zaphod.lastName = "Beeblebrox";
    zaphod.age = 200; 

    Data ford;
    ford.firstName = "Ford";
    ford.lastName = "Prefect";
    ford.age = 42; 

    uintptr_t zaphodSerialized = Serializer::serialize(&zaphod);
    std::cout << GREEN << "Serialized Zaphod's data: " << RESET << zaphodSerialized << std::endl;
	sleep(1);

    Data *zaphodDeserialized = Serializer::deserialize(zaphodSerialized);
    std::cout << BOLD_RED << "Deserialized Zaphod:" << RESET << std::endl;
    std::cout << GREEN << "Name: " << RESET << zaphodDeserialized->firstName << " " << zaphodDeserialized->lastName << std::endl;
    std::cout << GREEN << "Age: " << RESET << zaphodDeserialized->age << std::endl;
	sleep(2);
	std::cout << CYAN << "Age is just a number for a galactic president" << RESET << std::endl;

    std::cout << std::endl << "******************************************" << std::endl << std::endl;
	sleep(1);
    uintptr_t fordSerialized = Serializer::serialize(&ford);
    std::cout << GREEN << "Serialized Ford's data: " << RESET << fordSerialized << std::endl;
	sleep(1);

    Data *fordDeserialized = Serializer::deserialize(fordSerialized);
    std::cout << BOLD_RED << "Deserialized Ford:" << RESET << std::endl;
    std::cout << GREEN << "Name: " << RESET << fordDeserialized->firstName << " " << fordDeserialized->lastName << std::endl;
    std::cout << GREEN << "Age: " << RESET << fordDeserialized->age << std::endl;
	sleep(2);
	std::cout << CYAN << "Of course, it's 42!" << RESET << std::endl;
	sleep(2);

    std::cout << std::endl << CYAN << "Remember: Don’t Panic, and always carry a towel!" << RESET << std::endl << std::endl << "******************************************" << std::endl << std::endl;

    return 0;
}
