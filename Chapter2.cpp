#include <iostream>
using namespace std;
main()
{
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
    cout << endl;

    float price1, price2, price3;
    int quantity1, quantity2, quantity3;
    float tax;

    // Input the price and quantity of the three products
    cout << "Enter the price of Apples: ";
    cin >> price1;
    cout << "Enter the quantity of Apples: ";
    cin >> quantity1;
    cout << "Enter the price of Mangos: ";
    cin >> price2;
    cout << "Enter the quantity of Mangos: ";
    cin >> quantity2;
    cout << "Enter the price of Peaches: ";
    cin >> price3;
    cout << "Enter the quantity of Peaches: ";
    cin >> quantity3;

    // Calculate the price of each product based on its quantity
    float total1 = price1 * quantity1;
    float total2 = price2 * quantity2;
    float total3 = price3 * quantity3;

    // Print the price of each product
    cout << "Price of Apples: " << total1 << endl;
    cout << "Price of Mangos: " << total2 << endl;
    cout << "Price of Peaches: " << total3 << endl;

    // Calculate the total payable amount
    float totalPayable = total1 + total2 + total3;

    // Print the total payable amount
    cout << "Total Amount: " << totalPayable << endl;
    // Input the tax
    cout << "Enter the tax rate (%): ";
    cin >> tax;

    // Calculate the final total payable price after applying tax
    float finalTotalPayable = totalPayable * (1 + (tax / 100));

    // Print the final total payable price
    cout << "Final Total Payable Price (including tax): " << finalTotalPayable << endl;
}