/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:17:52 by mkhavari          #+#    #+#             */
/*   Updated: 2025/09/03 17:44:25 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
    _displayTimestamp();
    _nbAccounts++;
    _totalAmount += initial_deposit;
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account()
{
    
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp()
{
    std::tm tm;
    tm.tm_year = 2025 - 1900;
    tm.tm_mon = 0;
    tm.tm_mday = 4;
    tm.tm_hour = 9;
    tm.tm_min = 15;
    tm.tm_sec = 32;

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", &tm);

    std::cout << "[" << buffer << "]";
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
    
	std::cout << " accounts:" << getNbDeposits();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbAccounts();
	std::cout << ";withdrawals:" << getNbWithdrawals() << '\n';
}


//const means: this functon is not allowed to modify any member of object
int Account::checkAmount() const 
{
	return (this->_amount);
}

void Account::displayStatus() const 
{
	this->_displayTimestamp();
    std:: cout << " index:" << this->_accountIndex << ";amount: " << this-> _amount << " deposits:" << this->_nbDeposits << " withdrawals:" << this->_nbWithdrawals << std::endl;
}


void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit ;

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << "amount:" << _amount << " nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << " p_amount:" << _amount << " withdrawal:" ;
    if (withdrawal > _amount)
    {
        std::cout << "refused" << std::endl;
        return false;
    } 
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << withdrawal << " amount:" << _amount << " nb_withdrawals:" << _nbWithdrawals << std::endl;

    return true;
}

/* 
*/