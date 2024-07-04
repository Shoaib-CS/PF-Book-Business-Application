#include <iostream>
#include <conio.h>
using namespace std;

void header();
void adminHeader();
void customerHeader();

int choiceMenu();
int adminMenu();
int customerMenu();

char startMenu();
void signUpMenu();
bool signUpFunctionality(string usernameInput, string passwordInput, string roleInput);
bool isUsernameAlreadySignedUp(string usernameInput);

string signInMenu();
string signInFunctionality(string usernameInput, string passwordInput);

float calculateTotal(float price, float quantity, float taxPercentage);
float calculateTax(float price, float taxPercentage);
void printAllProducts(string name1, float price1, int quantity1, float tax1, float total1, string name2, float price2, int quantity2, float tax2, float total2);
void printProductData(string name, float price, float quantity, float taxPercentage, float total);
float calculateDiscountedPrice(string day, string month, float amount);

int quantityInput();
float priceInput();
float taxInput();
string nameInput();

void printTotal(float total);

bool IsPositiveValue(int value);
bool IsValueBetweenOrEqual(int value, int lowerLimit, int higherLimit);

string username[100];
string password[100];
string role[100];
int credentialsCount = 0;

string currentSignedInUser;
int main()
{

    string name1 = "";
    string name2 = "";

    float price1 = 0;
    float price2 = 0;

    float quantity1 = 0;
    float quantity2 = 0;

    float tax1 = 0;
    float tax2 = 0;

    float total1 = 0;
    float total2 = 0;

    bool isProduct1Discounted = false;
    bool isProduct2Discounted = false;

    while (true)
    {
        system("cls");
        header();
        char option = startMenu();
        if (option == '1')
        {
            system("cls");
            header();
            signUpMenu();
        }
        else if (option == '2')
        {
            system("cls");
            header();
            string signedInRole = signInMenu();

            if (signedInRole == "Admin")
            {
                while (true)
                {
                    system("cls");
                    header();
                    adminHeader();
                    int option = adminMenu();

                    if (option == 1)
                    {

                        if (name1 == "")
                        {

                            name1 = nameInput();
                            price1 = priceInput();
                            quantity1 = quantityInput();
                            tax1 = taxInput();
                            total1 = calculateTotal(price1, quantity1, tax1);
                            printTotal(total1);
                        }
                        else
                        {
                            cout << "Product already exists!" << endl;
                        }
                    }
                    else if (option == 2)
                    {
                        if (name2 == "")
                        {

                            name2 = nameInput();
                            price2 = priceInput();
                            quantity2 = quantityInput();
                            tax2 = taxInput();
                            total2 = calculateTotal(price2, quantity2, tax2);
                            printTotal(total2);
                        }
                        else
                        {
                            cout << "Product already exists!" << endl;
                        }
                    }
                    else if (option == 3)
                    {
                        string day = "";
                        cout << "Enter the day: ";
                        cin >> day;

                        string month = "";
                        cout << "Enter the month: ";
                        cin >> month;

                        if (name1 != "" && price1 != 0.0)
                        {
                            if (!isProduct1Discounted)
                            {
                                total1 = calculateDiscountedPrice(day, month, price1);
                                cout << "Total for product 1 after discount: " << total1 << endl;
                                isProduct1Discounted = true;
                            }
                            else
                            {
                                cout << "Discount is already applied on Product1 " << endl;
                            }
                        }
                        else
                        {
                            cout << "Product1 is not entered yet" << endl;
                        }
                        if (name2 != "" && price2 != 0.0)
                        {
                            if (!isProduct2Discounted)
                            {
                                total2 = calculateDiscountedPrice(day, month, price2);
                                cout << "Total for product 2 after discount: " << total2 << endl;
                                isProduct2Discounted = true;
                            }
                            else
                            {
                                cout << "Discount is already applied on Product1 " << endl;
                            }
                        }
                        else
                        {
                            cout << "Product1 is not entered yet" << endl;
                        }
                    }
                    else if (option == 4)
                    {
                        printAllProducts(name1, price1, quantity1, tax1, total1, name2, price2, quantity2, tax2, total2);
                    }
                    else if (option == 5)
                    {
                        int option;
                        cout << "Press 1 to delete the data of Product1 and delete 2 to clear the data of Product2..";
                        cin >> option;

                        /*Note that we are using the same variable name as in outside.
                        It results that the variable option declared inside an if or other block statement
                        will be accessible only in it's scope, and not outside.
                        Also the variable outside this block will not be accessible in this block, only
                        the inner variable of the same name will be accessible.

                        If it seems confusing, don't worry! You can use some other variable name to prevent confusion
                        Like instead of using option again you may use opt, but its better to learn this mechanism by practice
                        */

                        if (option == 1)
                        {
                            name1 = "";
                            price1 = 0;
                            quantity1 = 0;
                            tax1 = 0;
                            total1 = 0;
                            isProduct1Discounted = false;
                        }
                        else if (option == 2)
                        {
                            name2 = "";
                            price2 = 0;
                            quantity2 = 0;
                            tax2 = 0;
                            total2 = 0;
                            isProduct2Discounted = false;
                        }
                    }
                    else if (option == 6)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid Option, please try again" << endl;
                    }
                    cout << "Press any key to continue...";
                    getch();
                }
            }
            else if (signedInRole == "Customer")
            {
                while (true)
                {
                    system("cls");
                    header();
                    customerHeader();
                    int option = customerMenu();
                    if (option == 1)
                    {
                        printAllProducts(name1, price1, quantity1, tax1, total1, name2, price2, quantity2, tax2, total2);
                    }
                    if (option == 2)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid Option, please try again" << endl;
                    }
                    cout << "Press any key to continue...";
                    getch();
                }
            }
        }
        else if (option == '3')
        {
            return 0;
        }
        else
        {
            cout << "Invalid Option, please try again" << endl;
            cout << "Press any key to continue...";
            getch();
        }
    }
    return 0;
}

void printAllProducts(string name1, float price1, int quantity1, float tax1, float total1, string name2, float price2, int quantity2, float tax2, float total2)
{
    cout << "Following products exist in the system:" << endl;
    cout << "Name\tPrice\tQuantity\tTax%\tTotal" << endl;
    printProductData(name1, price1, quantity1, tax1, total1);
    printProductData(name2, price2, quantity2, tax2, total2);
}
void printTotal(float total)
{
    cout << "The total price is: " << total << endl;
}

int quantityInput()
{
    int input = 0;
    while (true)
    {
        cout << "Enter Quantity: ";
        cin >> input;
        if (IsValueBetweenOrEqual(input, 0, 100))
        {
            break;
        }
        cout << "Invalid quantity! Please enter a number between 0 and 100" << endl;
        cout << "Enter any key to continue" << endl;
        getch();
    }

    return input;
}
float priceInput()
{
    float input = 0;
    while (true)
    {
        cout << "Enter Price: ";
        cin >> input;
        if (IsPositiveValue(input))
        {
            break;
        }
        cout << "Invalid Price! Please enter a positive price" << endl;
        cout << "Enter any key to continue" << endl;
        getch();
    }

    return input;
}
float taxInput()
{
    float input = 0;
    while (true)
    {
        cout << "Enter Tax Percentage: ";
        cin >> input;
        if (IsValueBetweenOrEqual(input, 0, 50))
        {
            break;
        }
        cout << "Invalid quantity! Please enter a number between 0 and 50" << endl;
        cout << "Enter any key to continue" << endl;
        getch();
    }

    return input;
}
string nameInput()
{
    string name;
    while (true)
    {
        cout << "Enter product name: ";
        cin >> name;
        if (name != "")
        {
            break;
        }
        cout << "Invalid Name! Please enter a valid name" << endl;
        cout << "Enter any key to continue" << endl;
        getch();
    }

    return name;
}
bool IsPositiveValue(int value)
{
    if (value >= 0)
        return true;
    return false;
}
bool IsValueBetweenOrEqual(int value, int lowerLimit, int higherLimit)
{
    if (value >= lowerLimit && value <= higherLimit)
    {
        return true;
    }
    return false;
}

void header()
{
    // function to print header
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|   ######    #####    ######  ###  ##   ######            #####   #######            #####    #####   ####     #######   #####      |" << endl;
    cout << "|    ##  ##  ##   ##     ##    #### ##     ##             ##   ##   ##  ##           ##   ##  ##   ##   ##       ##  ##  ##   ##     |" << endl;
    cout << "|    ##  ##  ##   ##     ##    #######     ##             ##   ##   ##               ##       ##   ##   ##       ##      ##          |" << endl;
    cout << "|    #####   ##   ##     ##    ## ####     ##             ##   ##   ####              #####   #######   ##       ####     #####      |" << endl;
    cout << "|    ##      ##   ##     ##    ##  ###     ##             ##   ##   ##                    ##  ##   ##   ##       ##           ##     |" << endl;
    cout << "|    ##      ##   ##     ##    ##   ##     ##             ##   ##   ##               ##   ##  ##   ##   ##  ##   ##  ##  ##   ##     |" << endl;
    cout << "|   ####      #####    ######  ##   ##     ##              #####   ####               #####   ##   ##   ######  #######   #####      |" << endl;
    cout << "|                                                                                                                                    |" << endl;
    cout << "|              #####   ######   ######   ####      ######   #####    #####    ######   ######   #####   ###  ##                      |" << endl;
    cout << "|             ##   ##   ##  ##   ##  ##   ##         ##    ##   ##  ##   ##     ##       ##    ##   ##  #### ##                      |" << endl;
    cout << "|             ##   ##   ##  ##   ##  ##   ##         ##    ##       ##   ##     ##       ##    ##   ##  #######                      |" << endl;
    cout << "|             #######   #####    #####    ##         ##    ##       #######     ##       ##    ##   ##  ## ####                      |" << endl;
    cout << "|             ##   ##   ##       ##       ##         ##    ##       ##   ##     ##       ##    ##   ##  ##  ###                      |" << endl;
    cout << "|             ##   ##   ##       ##       ##  ##     ##    ##   ##  ##   ##     ##       ##    ##   ##  ##   ##                      |" << endl;
    cout << "|             ##   ##  ####     ####      ######   ######   #####   ##   ##     ##     ######   #####   ##   ##                      |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
int choiceMenu()
{
    int option;
    cout << endl;
    cout << "Select the choice of user..." << endl;
    cout << "1. Admin" << endl;
    cout << "2. Customer" << endl;
    cout << "3. Exit." << endl;
    cout << "Your Option: ";
    cin >> option;
    return option;
}
char startMenu()
{
    char option;

    cout << endl;
    cout << "Select the choice of user..." << endl;
    cout << "1. SignUp" << endl;
    cout << "2. SignIn" << endl;
    cout << "3. Exit." << endl;
    cout << "Your Option: ";

    option = getch();

    cout << endl;

    return option;
}
void signUpMenu()
{
    string usernameInput = "";
    string passwordInput = "";
    string roleInput = "";

    cout << "Enter Username: ";
    cin >> usernameInput;
    cout << "Enter Password: ";
    cin >> passwordInput;
    cout << "Enter Role: ";
    cin >> roleInput;

    if (signUpFunctionality(usernameInput, passwordInput, roleInput))
    {
        cout << "Successfully Sign Up!" << endl;
    }
    else
    {
        cout << "Error Signingup!";
        cout << endl;
        cout << " Username already exists!" << endl;
    }
    cout << "Press any key to return" << endl;
    getch();
}
bool signUpFunctionality(string usernameInput, string passwordInput, string roleInput)
{
    if (isUsernameAlreadySignedUp(usernameInput))
    {
        return false;
    }
    username[credentialsCount] = usernameInput;
    password[credentialsCount] = passwordInput;
    role[credentialsCount] = roleInput;

    credentialsCount++;
    return true;
}
bool isUsernameAlreadySignedUp(string usernameInput)
{
    for (int i = 0; i < credentialsCount; i++)
    {
        if (username[i] == usernameInput)
        {
            return true;
        }
    }
    return false;
}

string signInMenu()
{
    string usernameInput = "";
    string passwordInput = "";

    cout << "Enter Username: ";
    cin >> usernameInput;
    cout << "Enter Password: ";
    cin >> passwordInput;

    string roleOfSignedInUser = signInFunctionality(usernameInput, passwordInput);

    if (roleOfSignedInUser != "")
    {
        cout << "Successfully Signed In!" << endl;
    }
    else
    {
        cout << "Error Signing In!";
        cout << endl;
        cout << " Credentials are not valid!" << endl;
    }
    cout << "Press any key to Continue" << endl;
    getch();
    return roleOfSignedInUser;
}

string signInFunctionality(string usernameInput, string passwordInput)
{
    for (int i = 0; i < credentialsCount; i++)
    {
        if (username[i] == usernameInput && password[i] == passwordInput)
        {
            currentSignedInUser = username[i];
            return role[i];
        }
    }
    return "";
}
void adminHeader()
{

    cout << " ------------------------" << endl;
    cout << " |                      |" << endl;
    cout << " |                      |" << endl;
    cout << " |      ADMIN MENU      |" << endl;
    cout << " |                      |" << endl;
    cout << " |                      |" << endl;
    cout << " ------------------------" << endl;
}
void customerHeader()
{

    cout << " ------------------------" << endl;
    cout << " |                      |" << endl;
    cout << " |                      |" << endl;
    cout << " |    CUSTOMER MENU     |" << endl;
    cout << " |                      |" << endl;
    cout << " |                      |" << endl;
    cout << " ------------------------" << endl;
}

int adminMenu()
{
    int option;
    cout << "Select one of the following options number..." << endl;
    cout << "1. Add First Product Record" << endl;
    cout << "2. Add Second Product Record" << endl;
    cout << "3. Apply Discount" << endl;
    cout << "4. Print Both Products Data" << endl;
    cout << "5. Delete the data of a Product" << endl;
    cout << "6. Exit" << endl;
    cout << "Your Option: ";
    cin >> option;
    return option;
}
int customerMenu()
{
    int option;
    cout << "Select one of the following options number..." << endl;
    cout << "1. View All Products" << endl;
    cout << "2. Exit" << endl;
    cout << "Your Option: ";
    cin >> option;
    return option;
}

float calculateTotal(float price, float quantity, float taxPercentage)
{
    float tax = calculateTax(price, taxPercentage);
    float total = (price + tax) * quantity;
    return total;
}

float calculateTax(float price, float taxPercentage)
{
    return (price * taxPercentage) / 100;
}

void printProductData(string name, float price, float quantity, float taxPercentage, float total)
{
    cout << name << "\t" << price << "\t" << quantity << "\t" << taxPercentage << "\t" << total << endl;
}
float calculateDiscountedPrice(string day, string month, float amount)
{
    /* “Store Policy is to give a 20% discount on the total purchase amount
    on every Sunday and Month is October, March and August and 10% discount on the
    total purchase amount of every Monday of November and December, else apply discount
    of 5% .This can be done using the complex if else if and logical operators.*/

    float payable = amount;
    if (day == "Sunday" && (month == "October" || month == "March" || month == "August"))
    {
        payable = amount - (amount * 20) / 100;
    }
    else if (day == "Monday" && (month == "November" || month == "December"))
    {
        payable = amount - (amount * 10) / 100;
    }
    else
    {
        payable = amount - (amount * 5) / 100;
    }
    return payable;
}
