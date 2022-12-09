/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:03:11 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/09 18:16:15 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

using namespace std;

Brain::Brain(void) {
	index = 0;
	cout << "Brain default constructor called" << endl;
}

Brain::~Brain()	{
	cout << "Brain default destructor called" << endl;
}

Brain::Brain(Brain const &copy)	{
	*this = copy;
	cout << "Brain copy constructor called" << endl;
}

Brain	&Brain::operator=(Brain const &rhs)	{
	for (int i = 0; i < 100; i++)	{
		ideas[i] = rhs.ideas[i];
	}
	return *this;
}

void	Brain::hasNewIdea(std::string idea)	{
	ideas[index] = idea;
	index++;
}

void	Brain::printIdeas(void)	{
	for (int i = 0; i < index; i++)	{
		cout << "idea " << i << " > " << ideas[i] << endl;
	}
}
