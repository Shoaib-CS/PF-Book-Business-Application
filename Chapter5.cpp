#include <iostream>
#include <conio.h>
using namespace std;

void header();
int menu();
float calculateTotal(float price, float quantity, float taxPercentage);
float calculateTax(float price, float taxPercentage);
void printProductData(string name, float price, float quantity, float taxPercentage, float total);
float calculateDiscountedPrice(string day, string month, float amount);
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
        int option = menu();

        if (option == 1)
        {
            cout << "Enter Product Name: ";
            cin >> name1;
            cout << "Enter Price: ";
            cin >> price1;
            cout << "Enter Quantity: ";
            cin >> quantity1;
            cout << "Enter Tax Percentage: ";
            cin >> tax1;
            total1 = calculateTotal(price1, quantity1, tax1);
            cout << "The total price is: " << total1 << endl;
        }
        else if (option == 2)
        {
            cout << "Enter Product Name: ";
            cin >> name2;
            cout << "Enter Price: ";
            cin >> price2;
            cout << "Enter Quantity: ";
            cin >> quantity2;
            cout << "Enter Tax Percentage: ";
            cin >> tax2;
            total2 = calculateTotal(price2, quantity2, tax2);
            cout << "The total price is: " << total2 << endl;
        }
        else if (option == 3)
        {
            string day = "";
            cout << "Enter the day: ";
            cin >> day;

            string month = "";
            cout << "Enter the moth: ";
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
            cout << "Following products exist in the system:" << endl;
            cout << "Name\tPrice\tQuantity\tTax%\tTotal" << endl;
            printProductData(name1, price1, quantity1, tax1, total1);
            printProductData(name2, price2, quantity2, tax2, total2);
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
                price2= 0;
                quantity2 = 0;
                tax2 = 0;
                total2 = 0;
                isProduct2Discounted = false;
            }
        }
        else if (option == 6)
        {
            return 0;
        }
        else
        {
            cout << "Invalid Option, please try again" << endl;
        }

        cout << "Press any key to continue...";
        getch();
    }

    return 0;
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

int menu()
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
