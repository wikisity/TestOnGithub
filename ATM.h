// This file contains the header information for the ATM c++ file.
#ifndef PROJ1_H
#define PROJ1_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*
Name: menuStart()
PreCondition: None
PostCondition: Returns the selected option (1, 2, or 3)
*/
int menuStart();

/*
Name: menuMain()
PreCondition: The user input has either been loaded from file or entered by user
PostCondition: Returns the selected option (1, 2, 3, 4, or 5)
*/
int menuMain();

/*
Name: displayAccountDetails
PreCondition: Relevant data (fName, lName, age, accountBalance) has been loaded/entered
PostCondition: None (void)
 */
void displayAccountDetails(string fName, string lName, int age, float accountBalance);

/*
Name: displayBalance
PreCondition: Relevant data (accountBalance) has been loaded/entered
PostCondition: None (void)
*/
void displayBalance(float accountBalance);

/*
Name: deposit
PreCondition: Variable accountBalance is passed-by-reference
PostCondition: accountBalance is permanently changed via pass-by-reference
*/
void deposit(float &accountBalance);

/*
Name: withdraw
PreCondition: Variable accountBalance is passed-by-reference
PostCondition: accountBalance is permanently changed via pass-by-reference
*/
void withdraw(float &accountBalance);

#endif
