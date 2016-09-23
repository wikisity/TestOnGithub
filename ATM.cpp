/* This c++ file contains the main function to the ATM app.
  This application simulates the interface that a user might have for
  an Automate Teller Machine(ATM). the parogram  stores basic information
  of the user like name, age and address. It gives to the user the opportunity to apply
  basic banking transactions like deposit money, withdraw money, etc.
******************/


#include "proj1.h"


int main()
{
  int user_choice = 0;  // Stores user choice from the menu start
  int menu_choice = 0;  // Stores user choice once profile is completed or loaded
  const int THREE = 3;  // Exit the menu start
  const int FIVE = 5;   // Exit the menu main
  const char USER_PROFILE[10] = "proj1.txt"; //File to load or save user profile

  string first_name, last_name, usr_response;//user information and action
  int age; // user age to be saved on file as well as names
  float balance; // user account balance to be saved on file
  fstream input_stream; // read user infos from file
  fstream output_stream; // write user infos to file
  
  do
  {

    user_choice = menuStart();
    switch(user_choice)

    {
      case 1:
        // Load a user profile from file
        input_stream.open(USER_PROFILE);
        input_stream >> first_name
                     >> last_name
                     >> age
                     >> balance;

        cout << first_name
             << " "
             << last_name
             << " "
             << age
             << " "
             << '$'
             << balance
             << endl;
        input_stream.close();
        
        do
          {

            menu_choice = menuMain();
            switch(menu_choice)

              {
              case 1:
                displayBalance(balance);
                break;

              case 2:
                deposit(balance);
                break;

              case 3:
                withdraw(balance);
                break;

              case 4:
                displayAccountDetails(first_name, last_name, age, balance);
                break;
              case 5:
                cout << "Would you like to save your account information?:"
                     << endl
                     << "yes or no"
                     << endl;
                cin >> usr_response;
                
                if ((usr_response == "yes") or (usr_response == "y"))
                  {
                    output_stream.open(USER_PROFILE);
                    output_stream << first_name
                                  << " "
                                  << last_name
                                  << " "
                                  << age
                                  << " "
                                  << fixed
                                  << setprecision(2)
                                  << setfill('0')
                                  << balance
                                  << endl;
                    output_stream.close();

                    cout << "File Saved"
                         << endl
                         << "Thank you for using the UMBC ATM"
                         << endl
                         << endl;
                    menu_choice = FIVE;
                    user_choice = THREE;
                  }
                else
                  {
                    cout << "Okay!" << endl
                         << "Thank you for using the UMBC ATM"
                         << endl
                         << endl;
                    //Exit the ATM app
                    menu_choice = FIVE;
                    user_choice = THREE;
                  }
                break;

              default:
                //user enter invalid choice, prompt back the 5 choices
                cout << "Invalid Choice" << endl
                     << "Hit on the 5 choices you have!"
                     << endl
                     << endl;


              }

          } while(menu_choice != FIVE);

        break;
        
    case 2:
        // ENter a new User Profile
        cout << "Please enter the following:"
             << endl
             << "First Name:"
             << endl;
        cin >> first_name;

        cout << "Last Name:"
             << endl;
        cin >> last_name;

        cout << "Age:"
             << endl;
        cin >> age;

        cout << "Initial Deposit:"
             << endl;
        cin >> balance;
        
        cout << fixed
             << setprecision(2)
             << setfill('0')
             <<'$'
             << balance
             << " deposited"
             << endl;
             
        do
          {

            menu_choice = menuMain();
            switch(menu_choice)

              {
              case 1:
                displayBalance(balance);
                break;

              case 2:
                deposit(balance);
                break;

              case 3:
                withdraw(balance);
                break;

              case 4:
                displayAccountDetails(first_name, last_name, age, balance);
                break;

              case 5:
                cout << "Would you like to save your account information?:"
                     << endl
                     << "yes or no"
                     << endl;
                cin >> usr_response;
                
                if ((usr_response == "yes") or (usr_response == "y"))
                  {
                    output_stream.open(USER_PROFILE);
                    output_stream << first_name
                                  << " "
                                  << last_name
                                  << " "
                                  << age
                                  << " "
                                  << fixed
                                  << setprecision(2)
                                  << setfill('0')
                                  << balance
                                  << endl;
                    output_stream.close();

                    cout << "File Saved"
                         << endl
                         << "Thank you for using the UMBC ATM"
                         << endl
                         << endl;
                    // Exit the ATM app
                    menu_choice = FIVE;
                    user_choice = THREE;
                  }
                else
                  {
                    cout << "Okay!" << endl
                         << "Thank you for using the UMBC ATM"
                         << endl
                         << endl;
                    // Exit the ATM app
                    menu_choice = FIVE;
                    user_choice = THREE;
                  }

                break;

              default:
                //user is prompt 5 choices again
                cout << "Invalid Choice" << endl
                     << "Hit on the 5 choices you have!"
                     << endl
                     << endl;

              }

          } while(menu_choice != FIVE);
          
      break;
      
  case 3:
        cout << "Thank you for using the UMBC ATM"
             << endl
             << endl;
        user_choice = THREE;

        break;

      default:
        cout << "Invalid Choice" << endl
             << "Hit on the 3 choices you have!"
             << endl
             << endl;

    }


  } while(user_choice != THREE);


  return 0;

} 

/*
Name: menuStart()
PreCondition: None
PostCondition: Returns the selected option (1, 2, or 3)
*/
int menuStart()
{
  int user_choice = 0; // used to return user's option
  const int ONE = 1; //left limit of menu start
  const int THREE = 3; // right limit of menu start

  cout << endl;
  cout << "Welcome to the UMBC ATM" << endl
       << "Choose from below:" << endl
       << "1. Load a User Profile from File" << endl
       << "2. Enter a new User Profile" << endl
       << "3. Exit" << endl
       << "Enter your choice: ";
  cin >> user_choice;

  while ((user_choice < ONE) or (user_choice > THREE))
  {
    cout << endl;
    cout << "Welcome to the UMBC ATM"
         << endl
         << "Choose from below:" << endl
         << "1. Load a User Profile from File" << endl
         << "2. ENter a new Profile" << endl
         << "3. Exit" << endl
         << "Enter your choice: ";
    cin >> user_choice;
  }

  return user_choice;

}

/*
Name: menuMain()
PreCondition: The user input has either been loaded from file or entered by user
PostCondition: Returns the selected option (1, 2, 3, 4, or 5)
*/
int menuMain()
{
  int menu_choice = 0; // select user's choice
  const int ONE = 1; // left limit menu choices
  const int FIVE = 5; // right limit menu choices

  cout << endl;
  cout << "******Please choose option from the menu******" << endl
       << "1. Account Balance" << endl
       << "2. Deposit money" << endl
       << "3. Withdraw money" << endl
       << "4. Display your account details" << endl
       << "5. Exit" << endl
       << "Enter your choice: ";
  cin >> menu_choice;

  while ((menu_choice < ONE) or (menu_choice > FIVE))
  {
    cout << endl;
    cout << "******Please choose option from the menu******:"
         << endl
         << "1. Account Balance" << endl
         << "2. Deposit money" << endl
         << "3. Withdraw money" << endl
         << "4. Display your account details" << endl
         << "5. Exit" << endl
         << "Enter your choice: ";
    cin >> menu_choice;
  }

    return menu_choice;

}

/*
Name: displayAccountDetails
PreCondition: Relevant data (fName, lName, age, accountBalance) has been loaded/entered
PostCondition: None (void)
*/
void displayAccountDetails(string fName, string lName, int age, float accountBalance)
{
  cout << endl;
  cout << "First Name: " << fName
       << endl
       << "Last Name: " << lName
       << endl
       << "Age: " << age
       << endl
       << "Account Balance: " << '$' << accountBalance
       << endl;


}

/*
Name: displayBalance
PreCondition: Relevant data (accountBalance) has been loaded/entered
PostCondition: None (void)
*/
void displayBalance(float accountBalance)
{
  cout << endl;
  cout << "Account Balance: "
       << '$' << accountBalance
       << endl;

}

/*
Name: deposit
PreCondition: Variable accountBalance is passed-by-reference
PostCondition: accountBalance is permanently changed via pass-by-reference
*/
void deposit(float &accountBalance)
{
  float this_balance = 0; // save user entry
  cout << endl;
  cout << "Please enter the amount to be deposited"
       << endl;
  cin >> this_balance;
  if (this_balance <= 0)
    cout << "Amount should be greater than 0" << endl;
  else
  {
    cout << '$' << this_balance
         << " " << "deposited to your account"
         << endl;
    accountBalance += this_balance;
  }

}

/*
Name: withdraw
PreCondition: Variable accountBalance is passed-by-reference
PostCondition: accountBalance is permanently changed via pass-by-reference
*/
void withdraw(float &accountBalance)
{
  float this_balance = 0; // save user entry
  cout << endl;
  cout << "Please enter the amount to be withdrawn"
       << endl;
  cin >> this_balance;
  if (this_balance < 0)
    cout << "Amount can not be less than 0" << endl;
  else if (this_balance > accountBalance)
    cout << "Sorry cannot withdraw more than current balance" << endl;
  else
    {
      cout << '$' << this_balance
           << " " << "withdrawn from your account"
           << endl;
      accountBalance -= this_balance;
    }
  }
