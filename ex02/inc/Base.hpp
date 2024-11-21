/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:11:20 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/21 12:14:08 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <string>
#include <iostream>
#include <stdint.h>

#define RESET   "\033[0m"

#define ORANGE "\033[1m\033[38;5;208m"
#define GREEN   "\033[1m\033[1;32m"
#define YELLOW "\033[1m\033[1;33m"

class Base {
	public:
		Base();
		virtual ~Base() {};
};


#endif
