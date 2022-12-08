/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/08 20:24:23 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {
	const Animal	*animal = new Animal();
	const Animal	*cat = new Cat();
	const Animal	*dog = new Dog();

	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	return 0;
}
