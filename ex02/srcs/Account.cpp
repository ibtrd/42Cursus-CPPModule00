/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:40:48 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/18 01:17:05 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return  Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return  Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return  Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	 Account::_displayTimestamp();
	std::cout
		<< "accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals()
		<< std::endl;
}

Account::Account(int initial_deposit)
: _accountIndex(Account::_nbAccounts), _amount(initial_deposit)
{
	Account::_nbAccounts++;
	Account::_totalAmount += this->checkAmount();
	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";created" << std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << this->checkAmount()
		<< ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout
		<< ";amount:" << this->checkAmount()
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << this->checkAmount()
		<< ";withdrawal:";
	if (withdrawal <= this->checkAmount())
	{	
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout
			<< withdrawal
			<< ";amount:" << this->checkAmount()
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		return true;
	}
	else
	{
		std::cout << "refused" << std::endl;
		return false;
	}
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t		rawtime;
  	struct tm	*time_infos;
  	char 		buffer [80];

	time(&rawtime);
  	time_infos = localtime(&rawtime);
	strftime (buffer, 80, "[%G%m%e_%H%M%S] ",time_infos);
	
	std::cout << buffer;
}
