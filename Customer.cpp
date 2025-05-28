#include "Customer.h"

#include <iostream>

bool Customer::accessAccount(std::string_view user, 
	std::string_view pass) {

}

void Customer::newAccount() {
	// This probably doesn't need to exist since setupNew can return an obj
}

/// <summary>
/// Validates any user input looking for a single word response.
/// </summary>
/// <returns></returns>
std::string getUserInput() {
	while (true) {
		std::string temp_input{};
			std::cin.clear(); // clear cin prior to asking for input
			
			std::cin >> temp_input;
			
			// If the previous extraction failed
			if (!std::cin) {
				std::cin.clear();
				ignoreLine();
				continue;
			}

			// Additional input was still in the input buffer.
			// Assume failed extraction and retry.
			if (hasUnextractedInput() || temp_input == "") {
				ignoreLine();
				continue;
			}
			
			// Otherwise extraction was successful
			std::cin.clear();
			ignoreLine();
			return temp_input;
	}
}



// This function is ran by default constructor to initialize new account
Customer Customer::setupNewAccount() {
	
	std::cout << "\n\nWelcome! Let's setup your new account:\n";
	
	std::string firstName{""};
	while (true) {
		
		std::cout << "Please enter your first name: ";

		firstName = getUserInput();

		if (!validateInputOnlyAlpha(firstName)) {
			std::cout << "\nInvalid input. ";
			continue;
		}

		break;
	}

	std::string lastName{""};
	while (true) {

		std::cout << "\nPlease enter your last name: ";

		lastName = getUserInput();

		if (!validateInputOnlyAlpha(lastName)) {
			std::cout << "\nInvalid input. ";
			continue;
		}


		break;
	}


	std::cout << "\nThank you.\n Choose a username. Must be at least 8 characters in length, cannot include your last name.";

	std::string username{""};
	int username_minlength{ 8 };
	while (true) {

		std::cout << "\Enter your desired username: ";

		username = getUserInput();

		if (username.length() < username_minlength) {
			std::cout << "\nUsername is invalid. Must be at least " << username_minlength << " characters in length.\n";
			continue;
		}

		break;
	}
	
	std::cout << "\nChoose your password. Password must be at least " << passwd_minlength << " characters in length and include one number.\n";
	
	std::string passwd{ "" };
	int passwd_minlength{ 12 };
	while (true) {

		std::cout << "Enter your desired password: ";

		passwd = getUserInput();

		if (passwd.length() < passwd_minlength) {
			std::cout << "\Password is invalid. Must be at least " << passwd_minlength << " characters in length.\n";
			continue;
		}
		else {

			bool has_number{ false };
			for (int i = 0; i < passwd.length(); ++i) {
				if (std::isalpha(passwd[i])) {
					has_number = true;
					break;
				}
			}
			
			std::cout << "\Password is invalid. Must contain at least one number.\n";
			continue;
		}
	}

	return Customer(firstName, lastName, username, passwd);
}




////// HELPER FUNCTIONS /////////
void ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool hasUnextractedInput() {
	return !std::cin.eof() && std::cin.peek() != '\n';
}

bool clearFailedExtraction() {

	if (std::cin.fail()) {
		std::cin.clear();
		ignoreLine();
	}

	if (!std::cin) {
		if (std::cin.eof()) {
			std::exit(0)
		}
	}
}

bool validateInputOnlyAlpha(std::string& s) {
	for (int i = 0; i < s.length(); ++i) {
		if (!std::isalpha(s[i])) {
			return false;
		}
	}

	return true;
}