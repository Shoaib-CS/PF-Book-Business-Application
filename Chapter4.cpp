#include <iostream>
#include <conio.h>
using namespace std;


void header();
int menu();
float calculateTotal(float price, float quantity, float taxPercentage);
float calculateTax(float price,float taxPercentage);
void printProductData(string name, float price, float quantity, float taxPercentage, float total);
main()
{
    int option;  

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

    while (true)
    {
        system("cls");
        header();
        int option = menu();

        if (option == 1)
        {
            cout << "Enter Product Name...";
            cin >> name1;
            cout << "Enter Price ..";
            cin >> price1;
            cout << "Enter the Quantity..";
            cin >> quantity1;
            cout << "Enter the TaxPercentage on Product ..";
            cin >> tax1;
        }
        if (option == 2)
        {
            cout << "Enter Product Name...";
            cin >> name2;
            cout << "Enter Price ..";
            cin >> price2;
            cout << "Enter the Quantity..";
            cin >> quantity2;
            cout << "Enter the Tax Percentage on Product ..";
            cin >> tax2;
        }
        if (option == 3)
        {
            total1 = calculateTotal(price1, quantity1, tax1);
            total2 = calculateTotal(price2, quantity2, tax2);
        }
        if (option == 4)
        {
            cout << "Following Products Exist in the System" << endl;
            
            cout << "Name"<< "\t"<< "Price "<< "\t"<< "Quantity"<< "\t"<< "Tax %"<< "\t"<< "total" << endl;
            printProductData(name1, price1, quantity1, tax1, total1);
            printProductData(name2, price2, quantity2, tax2, total2);
        }
        if (option == 5)
        {
            return 0;
        }
        cout << "Press any Key to Continue: ";
        getch();
    }
}
void header()
{
    //function to print header
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
float calculateTotal(float price, float quantity, float taxPercentage)
{
    float total;
    float tax;
    tax = calculateTax(price,taxPercentage);
    total = price + tax;
    total = total * quantity;
    return total;
}
float calculateTax(float price,float taxPercentage)
{
    return (price * taxPercentage)/100;
}
void printProductData(string name, float price, float quantity, float tax, float total)
{
    cout << name << "\t" << price << "\t" << quantity << "\t" << tax << "\t" << total << endl;
}
int menu()
{
    int option;
    cout << "Select one of the following options number..." << endl;
    cout << "1. Add First Product Record" << endl;
    cout << "2. Add Second Product Record" << endl;
    cout << "3. Calculate Total" << endl;
    cout << "4. Print Both Products Data" << endl;
    cout << "5. Exit" << endl;
    cout << "Your Option..";
    cin >> option;
    return option;
}

