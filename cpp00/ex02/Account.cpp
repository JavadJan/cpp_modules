#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
}

Account::Account()
{
}

Account::~Account()
{
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
	// struct time t;
	std::time_t t = std::time(nullptr);
	std::tm *now = std::localtime(&t);
	std::cout << (now->tm_year + 1900) << '.'                                   
		// Year
				<< std::setw(2) << std::setfill('0') << now->tm_mon
					+ 1 << '.'     // Month
				<< std::setw(2) << std::setfill('0') << now->tm_mday              
					// Day
				<< "_" << std::setw(2) << std::setfill('0') << now->tm_hour << ":"
					// Hour
				<< std::setw(2) << std::setfill('0') << now->tm_min << ":"        
					// Minute
				<< std::setw(2) << std::setfill('0') << now->tm_sec << "\n";      
					// Second
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbDeposits() << '\n';
	std::cout << "total:" << getNbWithdrawals() << '\n';
	std::cout << "deposits:" << getNbAccounts() << '\n';
	std::cout << "withdrawals:" << getTotalAmount() << '\n';
}

// const means: this functon is not allowed to modify any member of object
int Account::checkAmount() const
{
	return (this->_amount);
}

void Account::displayStatus() const
{
	this->_displayTimestamp();

	std::cout << this->_accountIndex << '\n';
	std::cout << this->_amount << '\n';
	std::cout << this->_nbDeposits << '\n';
	std::cout << this->_nbWithdrawals << '\n';
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << '\n' << "p_amount:" << _amount << '\n' << "deposit:" << deposit << '\n';
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "amount:" << _amount << '\n' << "nb_deposits:" << _nbDeposits << '\n' << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << '\n' << "p_amount:" << _amount << '\n' << "withdrawal:";

	if (withdrawal > _amount)
	{
		std::cout << "unsuccessfull !" << std::endl;
		return (false);
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << withdrawal << "amount:" << _amount << '\n' << "nb_withdrawals:" << _nbWithdrawals << '\n' << std::endl;

	return (true);
}