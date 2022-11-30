/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:58:27 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/30 12:28:13 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)	{
    char 		buffer[20];
	std::time_t rawtime;
    std::tm* 	timeinfo;

    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);

	std::strftime(buffer, 20, "%Y%m%d_%H%M%S", timeinfo);
    std::cout << "[" << buffer << "]";
}

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created";
	std::cout << std::endl;
	return ;
}

void	Account::displayAccountsInfos(void)	{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts;
	std::cout << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits;
	std::cout << ";withdrawals:" << Account::_totalNbWithdrawals;
	std::cout << std::endl;
}

void	Account::displayStatus(void) const	{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)	{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)	{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (this->_amount - withdrawal >= 0)	{
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << this->_amount;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
		std::cout << std::endl;
		return (1);
	}
	std::cout << ";withdrawal:refused" << std::endl;
	return (0);
}

int		Account::checkAmount(void) const	{
	return (this->_amount);
}

int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

Account::~Account(void)	{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed";
	std::cout << std::endl;
	return ;
}