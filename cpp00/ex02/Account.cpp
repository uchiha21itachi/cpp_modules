#include "Account.hpp"
#include "iostream"
#include "ctime"

Account::Account(int initial_deposit): _amount(initial_deposit)
{
    Account::_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created"<< std::endl;
}

Account::~Account()
{
    Account::_nbAccounts -= 1;
    Account::_totalAmount -= _amount;
	Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed"<< std::endl;
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

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
	char time_str[18];

	time_str[17] = '\0';
    std::tm tm = *std::localtime(&t);
	std::strftime(time_str, 17, "%Y%m%d_%H%M%S", &tm);
    std::cout << "[" << time_str << "] ";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    int     num;

    num = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalNbDeposits += 1;
    Account::_totalAmount += deposit;
	Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << num
		<< ";deposit:" << deposit
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
    return;
}

bool    Account::makeWithdrawal(int withdrawl)
{
    int     num;

    num = this->_amount;
	Account::_displayTimestamp();
    if (withdrawl <= this->_amount)
    {
        this->_amount -= withdrawl;
        this->_nbWithdrawals += 1;
        Account::_totalNbWithdrawals += 1;
        Account::_totalAmount -= withdrawl;
        std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << num
			<< ";withdrawal:" << withdrawl
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return true;
    }
    else
	{
		std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << num
			<< ";withdrawal:refused" << std::endl;
		return false;
	}
    return false;
}

int    Account::checkAmount(void) const
{
    return(this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
int     Account::_nbAccounts = 0;
int     Account::_totalAmount = 0;
int     Account::_totalNbDeposits = 0;
int     Account::_totalNbWithdrawals = 0;