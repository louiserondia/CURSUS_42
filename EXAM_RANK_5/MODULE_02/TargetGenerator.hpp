/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:14:25 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/01 14:11:31 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "ATarget.hpp"

class ATarget;

class TargetGenerator
{
	private:

			typedef	std::map<std::string, ATarget *>	map;

			map	_book;

			TargetGenerator(const TargetGenerator &) {}
			
			TargetGenerator	&operator=(const TargetGenerator &) { return *this; }
			
	public:
		
		TargetGenerator() {}

		~TargetGenerator() {}

		void	learnTargetType(ATarget *target) {
			_book.insert(std::make_pair(target->getType(), target));
		}

		void	forgetTargetType(std::string target) {
			_book.erase(target);
		}
		
		ATarget	*createTarget(std::string const &type) {
			map::iterator	find = _book.find(type);
			if (find != _book.end())
				return find->second;
			return NULL;
		}

};
