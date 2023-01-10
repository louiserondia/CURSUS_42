/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:56 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/10 13:17:20 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

using namespace std;

int main( void ) {

	cout << "\n	| FIRST SET OF TESTS |	\n\n";
	const Animal	*cat = new Cat();
	const Animal	*dog = new Dog();

	cout << endl;
	delete cat;
	delete dog;

	cout << "\n	| SECOND SET OF TESTS |	\n\n";
	const Animal	*animal[2];
	animal[0] = new Cat();
	animal[1] = new Dog();

	cout << endl;
	delete animal[0];
	delete animal[1];

	cout << "\n	| THIRD SET OF TESTS |	\n\n";
	Cat	pimento;
	Cat	copain;

	cout << "\n		| Animals' ideas |	\n\n";
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
