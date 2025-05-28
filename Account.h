#pragma once
class Account
{
public:
	Account(
		double acc_balance
	)
		: m_accBalance{acc_balance}
	{ }


private:
	double m_accBalance{};

};

