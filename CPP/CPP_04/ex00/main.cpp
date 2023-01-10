/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:56 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/10 11:14:46 by lrondia          ###   ########.fr       */
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
	const Animal		*dog = new Dog();
	const Animal		*cat = new Cat();
	const WrongAnimal	*wrongAnimal = new WrongAnimal();
	const WrongAnimal	*wrongCat = new WrongCat();

	std::cout << std::endl << "|  TYPES | " << std::endl;
	std::cout << "dog : " << dog->getType() << std:: endl;
	std::cout << "cat : " << cat->getType() << std::endl;
	std::cout << "animal : " << animal->getType() << std::endl;
	std::cout << "wrong cat : " << wrongCat->getType() << std::endl;
	std::cout << "wrong animal : " << wrongAnimal->getType() << std::endl;
	
	std::cout << std::endl << "|  SOUNDS | " << std::endl;
	std::cout << "cat : ";
	cat->makeSound();
	std::cout << "dog : ";
	dog->makeSound();
	std::cout << "animal : ";
	animal->makeSound();
	std::cout << "wrong cat : ";
	wrongCat->makeSound();
	std::cout << "wrong animal : ";
	wrongAnimal->makeSound();

	std::cout << std::endl << "|  DESTRUCTORS | " << std::endl;
	delete cat;
	delete dog;
	delete animal;
	delete wrongCat;
	delete wrongAnimal;
	return 0;
}
