#include "Account.hpp"
#include "iostream"

Account::Account(int initial_deposit): _amount(initial_deposit)
{
    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    std::cout << "Account created with amount -" << initial_deposit << std::endl;
}

Account::~Account()
{
    Account::_nbAccounts -= 1;
    Account::_totalAmount -= _amount;
    std::cout <<"Account destroyed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return(Account::_nbAccounts);
}


int Account::getTotalAmount(void)
{
    return(Account::_totalAmount);
}


int Account::getNbDeposits(void)
{
    return(Account::_totalNbDeposits);
}


int Account::getNbWithdrawals(void)
{
    return(Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	// Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalNbDeposits += 1;
    Account::_totalAmount += deposit;
    return;
}

bool    Account::makeWithdrawal(int withdrawl)
{
    if (withdrawl <= this->_amount)
    {
        this->_amount -= withdrawl;
        this->_nbWithdrawals += 1;
        Account::_totalNbWithdrawals += 1;
        Account::_totalAmount -= withdrawl;
        return true;
    }
    return false;
}

int    Account::checkAmount(void) const
{
    return(this->_amount);
}

void	Account::displayStatus(void) const
{
	// Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
int     Account::_nbAccounts = 0;
int     Account::_totalAmount = 0;
int     Account::_totalNbDeposits = 0;
int     Account::_totalNbWithdrawals = 0;