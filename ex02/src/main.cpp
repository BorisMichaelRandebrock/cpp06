/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:42:44 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/21 12:25:35 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
    Base *newClass = NULL;
    std::srand(std::time(0));
    switch (std::rand() % 3) {
        case 0:
            newClass = new A();
            break;
        case 1:
            newClass = new B();
            break;
        case 2:
            newClass = new C();
            break;
        default:
            break;
    }
    return newClass;
}

void identify(Base* p) {
    if (p == NULL) {
        std::cout << "Pointer is NULL. Cannot identify type." << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p))
        std::cout << "Identified by pointer: "  << ORANGE << "A" << RESET << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified by pointer: "  << GREEN << "B" << RESET << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified by pointer: "  << YELLOW << "C" << RESET << std::endl;
    else
        std::cout << "Type could not be identified by pointer." << std::endl;
}

void identify(Base& p) {
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Identified by reference: "  << ORANGE << "A" << RESET << std::endl;
        return;
    } catch (const std::exception&) {}
    try {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Identified by reference: "  << GREEN << "B" << RESET << std::endl;
        return;
    } catch (const std::exception&) {}
    try {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Identified by reference: "  << YELLOW << "C" << RESET << std::endl;
        return;
    } catch (const std::exception&) {}
    std::cout << "Type could not be identified by reference." << std::endl;
}

int main(void) {
    Base *base = generate();

    identify(base);

    if (base != NULL) { 
        identify(*base);
        delete base;
    }
    return 0;
}

