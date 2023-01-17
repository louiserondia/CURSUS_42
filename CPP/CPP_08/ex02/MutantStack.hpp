/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:31:10 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/17 19:07:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) : std::stack<T>()	{}
		MutantStack(MutantStack<T> const &copy) : std::stack<T>(copy)	{}
		MutantStack<T>	&operator=(MutantStack<T> const &rhs)	{
			return MutantStack::stack::operator=(rhs);
		}
		~MutantStack(void)	{}
		
		typedef typename MutantStack::stack::container_type::iterator				iterator;
		typedef typename MutantStack::stack::container_type::const_iterator			const_iterator;
		typedef typename MutantStack::stack::container_type::reverse_iterator		reverse_iterator;
		typedef typename MutantStack::stack::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator	begin(void)	{
			return this->c.begin();
		}

		const_iterator	begin(void) const	{
			return this->c.cbegin();
		}

		const_iterator	rbegin(void)	{
			return this->c.rbegin();
		}
		
		const_iterator	rbegin(void) const	{
			return this->c.rbegin();
		}

		iterator	end(void)	{
			return this->c.end();
		}
		
		const_iterator	end(void) const	{
			return this->c.cend();
		}

		const_iterator	rend(void)	{
			return this->c.rend();
		}

		const_iterator	rend(void) const	{
			return this->c.rend();
		}

	private:
};

#endif
