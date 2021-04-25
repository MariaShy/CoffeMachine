using namespace std;
#include <iostream>
#include "CoffeeMain.cpp"
#define PIN_CODE 1234

void printServiceMenu();
void checkPIN();
void showCoffeeMachineBalance();
void showRemainingCoffeeCups();
void withdrawCash();

void printServiceMenu()
{
    cout << endl << "LEI700 Service Menu" << endl;
    cout << "1. Show coffee machine balance" << endl;
    cout << "2. Show remaining coffee cups" << endl;
    cout << "3. Withdraw cash" << endl;
    cout << "4. Return to main menu" << endl;
}

void checkPIN()
{
    int numOfAttempts = 3, userPin = 0;

    while (true)
    {
        if (numOfAttempts == 0)
        {
            cout << "You entered a wrong PIN code 3 times. The coffee machine is blocked. Contact EspressoBiancci." << endl;
            while (true)
            {
            }
        }
        cout << "Enter the four-digit PIN (" << numOfAttempts << " attempt(-s) left): ";
        cin >> userPin;
        if (userPin == PIN_CODE)
            break;
        else
        {
            cout << "Wrong PIN." << endl;
            numOfAttempts--;
        }
    }
}

void showCoffeeMachineBalance()
{
    cout << "Coffee machine balance: " << coffeeMachineBalance << " BYN" << endl;
}

void showRemainingCoffeeCups()
{
    cout << "Remaining coffee cups: " << totalCups << endl;
}

void withdrawCash()
{
    if (coffeeMachineBalance == 0)
        cout << "All cash withdrawn. Coffee machine balance: " << coffeeMachineBalance << " BYN" << endl;
    else
    {
        cout << "Get the sum of cash withdrawal: " << coffeeMachineBalance << " BYN" << endl;
        coffeeMachineBalance = 0.0;
    }
}