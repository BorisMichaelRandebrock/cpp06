/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:27:51 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/20 17:53:50 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SERIALIZER_HPP
# define  SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h> 

#define RESET   "\033[0m"
#define BOLD     "\033[1m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"

typedef struct s_Data {
	std::string firstName;
	std::string lastName;
	int			age;
} 				Data; 

class  Serializer {
	private:
		Serializer();
		Serializer(const Serializer &);
		Serializer &operator=(const Serializer &);

	public:
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
