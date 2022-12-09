/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/09 18:28:58 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

using namespace std;

int main( void ) {

	cout << endl;
	const Animal	*cat = new Cat();
	const Animal	*dog = new Dog();

	cout << endl;
	delete cat;
	delete dog;

	cout << endl;
	const Animal	*animal[2];
	animal[0] = new Cat();
	animal[1] = new Dog();

	cout << endl;
	delete animal[0];
	delete animal[1];

	cout << endl;
	Cat	pimento;
	Cat	copain;

	cout << endl;
	pimento.getBrain().hasNewIdea("oh no im dead");
	copain.getBrain().hasNewIdea("please dont die pimento my friend");
	pimento.getBrain().hasNewIdea("it's too late copain, ill see you on the other side");
	copain.getBrain().hasNewIdea("i will always love you, fwiend");
	pimento.getBrain().printIdeas();
	copain.getBrain().printIdeas();
	cout << endl;
	// system ("leaks Brain");
	return 0;
}
