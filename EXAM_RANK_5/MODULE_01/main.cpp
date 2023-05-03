/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:23:31 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/01 14:08:54 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"
#include "ASpell.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "Warlock.hpp"

int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}