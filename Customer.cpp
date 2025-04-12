#include "Customer.h"

#include <iostream>

Customer::Customer(
	std::string_view firstName
	, std::string_view lastName
	, std::string_view username
	, std::string_view password
)
	: m_firstName{ firstName }
	, m_lastName{ lastName }
	, m_username{ username }
	, m_password{ password }
{
}

bool Customer::accessAccount(std::string_view user, 
	std::string_view pass) {

}

void Customer::newAccount() {
	// This probably doesn't need to exist since setupNew can return an obj
}

// This function is ran by default constructor to initialize new account
Customer Customer::setupNewAccount() {
	std::cout << "\n\nWelcome! Let's setup your new account:\n" << "To start, please enter your first and last name: ";
	
	std::string firstName{""};
	std::string lastName{""};
	while (1) {
			
		std::cin >> firstName >> lastName;

		if (firstName == "") {
			std::cin.ignore();
			std::cout << "Please enter your first name: ";
			std::cin >> firstName;
		}
		
		if (lastName == "") {
			std::cin.ignore();
			std::cout << "Please enter your last name: ";
			std::cin >> firstName;
		}

		break;
	}

	std::cout << "\nThank you.\n What is your username?: ";
	std::string username{ "" };
	std::cin >> username;

	std::string passwd{ "" };
	std::cout << "\nSet a password: ";
	std::cin >> passwd;


	return Customer(firstName, lastName, username, passwd);
}