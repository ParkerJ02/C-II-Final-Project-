/*
Parker Haynie
12/15/2022
The Source File For The New & Improved Expanded C++ Calculator
*/

// This is the header file that contains all of the functions like "cout" and "cin".
#include <iostream>
// This is the header that tells the program to use a variable that has a type std::string. 
#include <string>
// This is a header file for a stream class that can read and write from/to files.
#include <fstream>
// This is the header file that includes built-in support for threads, atomic operations, mutual exclusions, condition variables, and futures.
#include <thread>
// This includes my own header file that I created for this project.
#include "finProj.h"
// This tells the program to look at the standard namespace for everything that is not declared.
using namespace std;

// This initializes the char variable "loginOption".
char loginOption;
// This initializes the char variable "nOrR".
char nOrR;
// This initializes the int variables "a" and "b".
int a, b;
// This initializes the int pointer variables "p1" and "p2".
int* p1, * p2;
// This initializes the int variable "choice".
int choice;
// This initializes the char variable "again" and sets it equal to "Y".
char again = 'Y';
// This initializes the string variable "line".
string line;

// This line initializes a fstream called "loginFile". I can use this to create a file,
// write information to files, and read information from files.
fstream loginFile;

// This is the "loginSystem" class. It is the parent class to "userLogin" and "newLogin".
// The "userLogin" and "newLogin" classes inherit the "usernameEntered" variable and the "passwordEntered" variable.
// This class is also an abstract class due to the use of the pure virtual function that is "virtual void login() = 0;".
class loginSystem
{
	// Everything underneath this line is under the encapsulation of public.
public:
	// This line is a pure virtual function that makes this class an abstract class.
	// It also allows for the "userLogin" class and "newLogin" class to override this "logic()" function with their own "logic()" function.
	virtual void login() = 0;
	// Everything underneath this line is under the encapsulation of protected.
protected:
	// "usernameEntered" is a string varaible that is inherited by "userLogin" and "newLogin".
	string usernameEntered;
	// "passwordEntered" is a string varaible that is inherited by "userLogin" and "newLogin".
	string passwordEntered;
};

// This is the "userLogin" class. It is the child class to "loginSystem". An object is made from
// this class if the user is a registered user.
class userLogin : public loginSystem
{
	// Everything underneath this line is under the encapsulation of public.
public:
	// This is the function that allows the registered user to login.
	void login()
	{
		cout << "\nPlease enter your login info" << endl;
		cout << "-----------------------------" << endl;
		cout << "Username:";
		// This line allows the user to enter their username.
		cin >> usernameEntered;

		// This line sets the string variable "regUsername" to the line that is found in the "usernames.txt" file.
		regUsername = getLogData("usernames.txt");

		// This if else statement is for if the user enters the correct username.
		if (usernameEntered == regUsername)
		{
			cout << "Password:";
			// This line allows the user to enter their password.
			cin >> passwordEntered;

			// This line sets the string variable "regPassword" to the line that is found in the "usernames.txt" file.
			regPassword = getLogData("passwords.txt");

			// This if else statement is for if the user enters the correct password.
			if (passwordEntered == regPassword)
			{
				cout << "\nYou have successfully logged in as a user and you now have access to the program." << endl;
				cout << "---------------------------------------------------------------------------------" << endl;
			}
			else
			{
				// This line calls the function that ask the user if they want to use a registered account or make a new once.
				nOrRagain();
			}
		}
		else
		{
			// This line calls the function that ask the user if they want to use a registered account or make a new once.
			nOrRagain();
		}
	}
	// This string function is responsible for opening the loginFile and retriving the first line of the file before finally returning that line.
	string getLogData(const char* p_fileName)
	{
		// This line opens the loginFile and puts it into input mode so that the information on the file can be read.
		loginFile.open(p_fileName, ios::in);
		// This if statement determines what happends deppending on the programs success in opening the loginFile.
		if (loginFile.is_open())
		{
			// If the loginFile is successfully opened then the first line of the .txt file will be taken and set to line.
			getline(loginFile, line);
		}
		// This line closes the loginFile after the process has been completed.
		loginFile.close();
		// This line returns the string variable, "line", once it has been set to the first line of the .txt file.
		return line;
	}
	// Everything underneath this line is under the encapsulation of private
private:
	// This string variable will be set to the same string as the "line" string to determine if the username that was entered was correct.
	string regUsername;
	// This string variable will be set to the same string as the "line" string to determine if the password that was entered was correct.
	string regPassword;
};

// This is the "newLogin" class. It is the child class to "loginSystem". An object is made from
// this class if the user is trying to make a new account with new login info.
class newLogin : public loginSystem
{
	// Everything underneath this line is under the encapsulation of public.
public:
	// This is the function that allows the guest to login.
	void login()
	{
		// This line is used to open the "usernames.txt" file in "output mode".
		loginFile.open("usernames.txt", ios::out);
		// This if/else statement will detect if the "username.txt" file can be opened.
		if (loginFile.is_open())
		{
			cout << "\nPlease enter your new login information" << endl;
			cout << "---------------------------------------" << endl;
			cout << "Username:" << endl;
			// This line will take the string that is entered and set it to the "usernameEntered" variable.
			getline(cin.ignore(1, '\n'), usernameEntered);
			// This line will write the string that is called "usernameEntered" to the loginFile that is opened.
			loginFile << usernameEntered << endl;
			// This line closes the "LivFile" after allowing the user to add something on to the new list.
			loginFile.close();
		}
		// This line is used to open the "passwords.txt" file in "output mode".
		loginFile.open("passwords.txt", ios::out);
		// This if/else statement will detect if the "username.txt" file can be opened.
		if (loginFile.is_open())
		{
			cout << "Password:" << endl;
			// This line will take the string that is entered and set it to the "passwordEntered" variable.
			getline(cin.ignore(0, '\n'), passwordEntered);
			// This line will write the string that is called "passwordEntered" to the loginFile that is opened.
			loginFile << passwordEntered << endl;
			// This line closes the "LivFile" after allowing the user to add something on to the new list.
			loginFile.close();
		}
	}
};

// This is a void function that displays the title of the program.
void displayTitle()
{
	cout << "                        <-[The Expanded C++ Calculator]->" << endl;
	cout << "----------------------------------------------------------------------------------\n";
	cout << "This Expanded C++ Calculator is a great tool for solving multiple different types\n";
	cout << "of math equations but you have to sign in first in order to use the calculator.\n";
}

// This is a void function that lets the user decide whether they want to continue as a guest or use a registered account.
void loginOptions()
{
	cout << "\nWould you like to sign in to an existing account, make a new account, or continue\n";
	cout << "to use the program as a guest?\n";
	cout << "(Enter 'u' for signing in or making a new account and 'g' to continue as a guest)\n";
	// This line allows the user to input their option of how they would like to login.
	cin >> loginOption;
	// This if statement only happens if the user enters "u" or "U".
	if (loginOption == 'u' || loginOption == 'U')
	{
		// This line calls the function that allows the user to enter information for a account that is already registered or make a new account.
		newOrRegistered();
	}
	// This else if statement only happens if the user enters "g" or "G".
	else if (loginOption == 'g' || loginOption == 'G')
	{
		cout << "\nYou have entered guest mode\n";
		cout << "---------------------------\n";
		// This calls the function that displays the welcome message for the program.
		displayWelcomeMessage();
		// This calls the function that allows the user to input numbers for their math equations.
		enterEquation();
	}
	// This else statement only happens if the user enters an invalid letter.
	else
	{
		// This line calls the function that asks the user if they would like to try picking a login method again.
		loginAgain();
	}
}

// This is a void function that allows the user to try logging in again after making an invalid input.
void loginAgain()
{
	cout << "\nError: You entered an invalid letter. Would you like to try again?" << endl;
	cout << "(Please enter 'y' for yes and 'n' for no)" << endl;
	// This line allows the user to determine whether they try logging in again after failing to properly pick a login method.
	cin >> again;
	// This if statement only occurs if the user entered "y" or "Y".
	if (again == 'y' || again == 'Y')
	{
		// This line calls the function that allows the user to try another login method.
		loginOptions();
	}
	// This else statement only happens when the user enters anything but "y" or "Y".
	else
	{
		// This line calls a function that displays a goodbye message and then exits the program.
		displayGoodbyeMessage();
	}
}

// This is a void function that asks the user would like to use a registered account or make a new account.
// If the user decides to use a registered then they will have to login with a certain username and password.
// If the user decides to make a new account then they will have to input a new username and password and then login using that new username and password.
void newOrRegistered()
{
	cout << "\nWould you like to sign in as a registered user or make a new account?" << endl;
	cout << "(Enter 'r' for registered user and 'n' for making a new account)" << endl;
	// This line allows the user to enter their login option.
	cin >> nOrR;
	// This if/else is used to let the user choose if they want to use a registered account or make a new account.
	// This if only happens if the user enters "r" or "R"
	if (nOrR == 'r' || nOrR == 'R')
	{
		// This line uses the "loginSystem" parent class to make a new "userLogin()" object.
		loginSystem* ul1 = new userLogin();
		// This line uses the pointer that is pointing at the new "userLogin()" object and tells it to execute the login() function.
		ul1->login();
		// This calls the function that displays the welcome message for the program.
		displayWelcomeMessage();
		// This calls the function that allows the user to input numbers for their math equations.
		enterEquation();
	}
	// This else if only happens if the user enters "n" or "N"
	else if (nOrR == 'n' || nOrR == 'N')
	{
		// This line uses the "loginSystem" parent class to make a new "newLogin()" object.
		loginSystem* nl1 = new newLogin();
		// This line uses the pointer that is pointing at the new "newLogin()" object and tells it to execute the login() function.
		nl1->login();
		// This line uses the "loginSystem" parent class to make a new "userLogin()" object.
		loginSystem* ul1 = new userLogin();
		// This line uses the pointer that is pointing at the new "userLogin()" object and tells it to execute the login() function.
		ul1->login();
		// This calls the function that displays the welcome message for the program.
		displayWelcomeMessage();
		// This calls the function that allows the user to input numbers for their math equations.
		enterEquation();
	}
	// This else statement onlt happens if the user enters an invalid letter.
	else
	{
		// This line calls the function that ask the user if they want to try using a registered account or making a new account again.
		nOrRagain();
	}
}

// This void function ask the user if they want to try using a registered account or make a new account again.
void nOrRagain()
{
	cout << "\nError: You entered an invalid letter. Would you like to try again?" << endl;
	cout << "(Please enter 'y' for yes and 'n' for no)" << endl;
	// This line allows the user to decide whether they want to try to login again via make a new account or using a registered account.
	cin >> again;
	// This if statement only occurs if the user enters "y" or "Y". 
	if (again == 'y' || again == 'Y')
	{
		// This line calls the function that ask if they would like to use a registered account or make a new account.
		newOrRegistered();
	}
	// This else statement only occurs if the user enters anything other than "y" or "Y". 
	else
	{
		// This line calls the function that displays a goodbye message and then exits the program.
		displayGoodbyeMessage();
	}
}

// This is a void function that displays the welcome message. It explains what the program is.
void displayWelcomeMessage()
{
	cout << "\nHello, and welcome to the Expanded C++ Calculator. With this calculator you will be" << endl;
	cout << "able to add, subtract, multiply, and divide any two numbers. Go ahead and enter the" << endl;
	cout << "equation that you would like the answer to." << endl;
}

// This is a void function that will take the equation that was entered by the user and then it will
// show you the answer to that equation. The user has the option to add, subtract, multiply and divide.
void enterEquation()
{
	// This line sets the int pointer "p1" equal to the address of the intger "a".
	p1 = &a;
	// This line sets the int pointer "p2" equal to the address of the intger "b".
	p2 = &b;
	cout << "\nGo ahead and select the type of equation you want answered." << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "[1] Addition" << endl;
	cout << "[2] Subtraction" << endl;
	cout << "[3] Multiplication" << endl;
	cout << "[4] Division" << endl;
	cout << "\nPlease enter numbers 1-4 to chose the type of equation." << endl;
	// This line allows the user to make a choice on what type of equation that they want the answer to.
	cin >> choice;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Enter the first number of the equation." << endl;
	// This line allows the user to enter the first number of the equation.
	cin >> a;
	cout << "Enter the second number of the equation." << endl;
	// This line allows the user to enter the second number of the equation.
	cin >> b;

	// This determines what is displayed depending on the type of equation that is chosen by the user.
	switch (choice)
	{
		// This case only occurs if the user decides on addition.
	case 1:
		cout << "-----------------------------------------" << endl;
		// This line takes the two numbers given, gets the answer, and displays the full equation with the answer at the end.
		cout << *p1 << " + " << *p2 << " = " << *p1 + *p2 << endl;
		// This line calls a function that asks the user if they would like to enter another function.
		equationAgain();
		break;
		// This case only occurs if the user decides on subtraction.
	case 2:
		cout << "-----------------------------------------" << endl;
		// This line takes the two numbers given, gets the answer, and displays the full equation with the answer at the end.
		cout << *p1 << " - " << *p2 << " = " << *p1 - *p2 << endl;
		// This line calls a function that asks the user if they would like to enter another function.
		equationAgain();
		break;
		// This case only occurs if the user decides on multiplication.
	case 3:
		cout << "----------------------------------------" << endl;
		// This line takes the two numbers given, gets the answer, and displays the full equation with the answer at the end.
		cout << *p1 << " * " << *p2 << " = " << *p1 * *p2 << endl;
		// This line calls a function that asks the user if they would like to enter another function.
		equationAgain();
		break;
		// This case only occurs if the user decides on division.
	case 4:
		// This try/catch block detects if the input for "p2" (the denominator) is valid.
		try
		{
			// This if statement sees if the second number, "p2", is less than 0.
			// If the number is 0 then it will throw an error message to the catch.
			if (*p2 == 0)
			{
				// This throw statement throws an error message to the catch when "p2" equals 0.
				throw "---------------------------------\nYou can not divide a number by 0.";
			}
			// This happens when "p2" does not equal 0.
			else if (*p2 != 0)
			{
				cout << "----------------------------------------" << endl;
				// This line takes the two numbers given, gets the answer, and displays the full equation with the answer at the end.
				cout << *p1 << " / " << *p2 << " = " << *p1 / (float)*p2 << endl;
				// This line calls a function that asks the user if they would like to enter another function.
				equationAgain();
			}
		}
		// This is the catch that catches the error message of the exception.
		// The exception is if "p2" (the denominator) is equal to 0.
		catch (const char* Exception1)
		{
			// This line displays the error message for the exception.
			cout << Exception1 << endl;
			// This line calls a function that asks the user if they would like to enter another function.
			equationAgain();
		}
		break;
	default:
		// This line calls the function asking if they would like to enter another function after entering an invalid number.
		tryAgain();
	}
}

// This void function allows the user to decide whether they want to try another equation or not.
void equationAgain()
{
	cout << "\nWould you like to try another equation?" << endl;
	cout << "(Please enter 'y' for yes and 'n' for no)" << endl;
	// This line allows the user to make the decision of entering another equation.
	cin >> again;
	// This if only happens when the user enters "y" or "Y"
	if (again == 'y' || again == 'Y')
	{
		// This line calls the function that allows the user to enter another function.
		enterEquation();
	}
	// This else only happens if the user enters anything else but "y" or "Y".
	else
	{
		// This line calls the function that displays a goodbye message and then exits the program.
		displayGoodbyeMessage();
	}
}

// This void function allows the user to decide whether they want to try another equation after entering an equation unsuccessfully.
void tryAgain()
{
	cout << "------------------------------------------------------------------" << endl;
	cout << "\nError: You entered an invalid letter. Would you like to try again?" << endl;
	cout << "(Please enter 'y' for yes and 'n' for no)" << endl;
	// This line allows the user to make the decision of entering another equation.
	cin >> again;
	if (again == 'y' || again == 'Y')
	{
		// This line calls the function that allows the user to enter another equation.
		enterEquation();
	}
	else
	{
		// This line calls the function that displays a goodbye message and then exits the program.
		displayGoodbyeMessage();
	}
}

// This is a void function that displays the goodbye message if the user is done using the program.
void displayGoodbyeMessage()
{
	cout << "\nThank you for using my calculator program!" << endl;
	// This line is used to stop and exit the program once the goodbye message has been displayed.
	exit(EXIT_SUCCESS);
}
