/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:37:25 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/20 17:00:08 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../inc/Serializer.hpp"
#include "Serializer.hpp"


Serializer::Serializer() {}

Serializer::Serializer(const Serializer &cpy) {
	*this = cpy;
}

Serializer &Serializer::operator=(const Serializer &cpy)  {
	(void)cpy;
	return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data * Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
