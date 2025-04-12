#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer
{
public:
	Customer(
		std::string_view firstName
		, std::string_view lastName
		, std::string_view username
		, std::string_view password
	);

	bool accessAccount(std::string_view user, std::string_view pass);
	void newAccount();

private:
	static constexpr long m_accountNumber{ 0 };
	std::string m_firstName{};
	std::string m_lastName{};
	std::string m_username{};
	std::string m_password{};
	short m_pin{};

	Customer setupNewAccount();
};

#endif