/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/09 16:45:04 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void ) {

	std::cout << std::endl << "|  CONSTRUCTORS | " << std::endl;
	const Animal		*animal = new Animal();
	const Animal		*cat = new Cat();
	const Animal		*dog = new Dog();
	const WrongAnimal	*wrongAnimal = new WrongAnimal();
	const WrongAnimal	*wrongCat = new WrongCat();

	std::cout << std::endl << "|  TYPES | " << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << animal->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;
	std::cout << wrongAnimal->getType() << std::endl;
	std::cout << std::endl << "|  SOUNDS | " << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	wrongCat->makeSound();
	wrongAnimal->makeSound();

	std::cout << std::endl << "|  DESTRUCTORS | " << std::endl;
	delete cat;
	delete dog;
	delete animal;
	delete wrongCat;
	delete wrongAnimal;
	return 0;
}
