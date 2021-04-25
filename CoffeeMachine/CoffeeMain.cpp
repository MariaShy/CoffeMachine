using namespace std;
#include <iostream>

#define ESPRESSO_PRICE 2.00
#define CAPPUCCINO_PRICE 2.50
#define LATTE_PRICE 3.00
#define MIN_VALUE_BYN 1.00
#define MAX_VALUE_BYN 100.00
#define MIN_CUPS_ORDER 1
#define MAX_CUPS_ORDER 9

void printMainMenu();
double checkUserBalance();
double insertMoney();
int makeCoffee(int neededCups, double price);
bool isEnoughMoney(int neededCups, double price);
bool isEnoughCups(int neededCups);

double userBalance = 0.0, coffeeMachineBalance = 0.0, clientMoney = 0.0;
int totalCups = 7;

void printMainMenu()
{
    cout << "1. Insert money" << endl;
    cout << "2. Make espresso (" << ESPRESSO_PRICE << " BYN)" << endl;
    cout << "3. Make cappuccino (" << CAPPUCCINO_PRICE << " BYN)" << endl;
    cout << "4. Make latte (" << LATTE_PRICE << " BYN)" << endl;
    cout << "0. Service" << endl;
}

double checkUserBalance()
{
    userBalance += clientMoney;
    clientMoney = 0.0;
    return userBalance;
}

double insertMoney()
{
    double money = 0.0;

    while (true) {
        cout << "Insert your money (from " << MIN_VALUE_BYN << " to " << MAX_VALUE_BYN << "): ";
        cin >> money;
        if (money >= MIN_VALUE_BYN && money <= MAX_VALUE_BYN)
            break;
        else {
            cout << "Wrong amount of money" << endl;
            continue;
        }
    }
    cout << "Your balance has been increased by " << money << " BYN" << endl;
    return money;
}

bool isEnoughMoney(int neededCups, double price)
{
    return (neededCups * price <= userBalance) ? true : false;
}

bool isEnoughCups(int neededCups)
{
    return (neededCups <= totalCups) ? true : false;
}

int makeCoffee(int neededCups, double price)
{
    int result;

    if (!isEnoughCups(neededCups))
        result = -1;
    else if (!isEnoughMoney(neededCups, price))
        result = -2;
    else
        result = neededCups;
    return result;
}