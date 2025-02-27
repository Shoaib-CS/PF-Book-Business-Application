#include <iostream>
#include <conio.h>
#include <limits>
#include <string>
#include <cctype>
using namespace std;

void header();
void adminHeader();
void customerHeader();

char adminMenu();
char customerMenu();

char startMenu();
void signUpMenu();
bool signUpFunctionality(string usernameInput, string passwordInput, string roleInput);
bool IsUsernameTaken(string usernameInput);
void addingCredentialsIntoArray(string usernameInput, string passwordInput, string roleInput);

string signInMenu();
string signInFunctionality(string usernameInput, string passwordInput);

void addProductMenu();
void viewProductByNameMenu();
void viewProductByNameFunctionality(int productIndex);
void viewAllProductsMenu();
void viewAllProductsMenuForCustomer();
void deleteProductMenu();
void deleteProductFromArray(int indexToBeRemoved);
void UpdateProductMenu();
int getProductIndex(string productNameInput);
void addProductIntoArray(string productNameInput, string productTypeInput, float productPriceInput, float productTaxInput, float productQuantityInput);
void UpdateProductInArray(int index, string productNameInput, string productTypeInput, float productPriceInput, float productTaxInput, float productQuantityInput);

float calculateTotal(float price, float quantity, float taxPercentage);
float calculateTax(float price, float taxPercentage);
float calculateDiscountedPrice(float amount);

int quantityInput(int lowerLimit, int higherLimit);
float priceInput();
float taxInput(int lowerLimit, int higherLimit);
string nameInput();
string typeInput();
string usernameInput();
string passwordInput();
string roleInput();

bool IsPositiveValue(int value);
bool isAlphabetOnly(string input);
bool isFirstAlphabetCapital(string input);
bool IsValueBetweenOrEqual(int value, int lowerLimit, int higherLimit);
bool isPositveIntegerOnly(string input);

void buyProductMenu();
string buyProductFunctionality(int productIndex, string name, string type, float price, float tax, int toBuyQuantity, float discountedPrice);
void decreaseProductQuantity(int productIndex, int toBuyQuantity);
void addPurchasedProductIntoArray(string name, string type, float price, float tax, int toBuyQuantity, float discountedPrice);

void viewAllPurchasedProductsMenu();

bool isProductPurchased(string name);

string usernames[100];
string passwords[100];
string roles[100];
int credentialsCount = 0;

string productNames[100];
string productTypes[100];
float productPrices[100];
float productTaxes[100];
int productQuantities[100];
int productsCount = 0;

string purchasedProductNames[100];
string purchasedProductTypes[100];
float purchasedProductPrices[100];
float purchasedProductTaxes[100];
int purchasedProductQuantities[100];
float purchasedProductTotalPrices[100];
string purchasersUsernames[100];

int purchasedProductsCount = 0;

string currentSignedInUser = "";
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
                    char option = adminMenu();

                    if (option == '1')
                    {
                        addProductMenu();
                    }
                    else if (option == '2')
                    {
                        UpdateProductMenu();
                    }
                    else if (option == '3')
                    {
                        viewAllProductsMenu();
                    }
                    else if (option == '4')
                    {
                        viewProductByNameMenu();
                    }
                    else if (option == '5')
                    {
                        deleteProductMenu();
                    }
                    else if (option == '6')
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
                    char option = customerMenu();
                    if (option == '1')
                    {
                        viewAllProductsMenuForCustomer();
                    }
                    else if (option == '2')
                    {
                        buyProductMenu();
                    }
                    else if (option == '3')
                    {
                        viewAllPurchasedProductsMenu();
                    }
                    else if (option == '4')
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

int quantityInput(int lowerLimit, int higherLimit)
{
    string input = "";
    while (true)
    {
        cout << "Enter Quantity: ";
        cin >> input;
        if (isPositveIntegerOnly(input))
        {
            if (IsValueBetweenOrEqual(stoi(input), lowerLimit, higherLimit))
            {
                break;
            }
        }

        cout << "Invalid quantity! Please enter a number between " <<lowerLimit<< " and " << higherLimit << endl;
        cout << "Enter any key to continue" << endl;
        getch();
    }

    return stoi(input);
}
float priceInput()
{
    string input = "";
    while (true)
    {
        cout << "Enter Price: ";
        cin >> input;
        if (isPositveIntegerOnly(input))
        {
            break;
        }
        cout << "Invalid Price! Please enter a positive integer" << endl;
        cout << "Enter any key to continue" << endl;
        getch();
    }

    return stoi(input); // converts string to int
}
bool isPositveIntegerOnly(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}
float taxInput(int lowerLimit, int higherLimit)
{
    string input = "";
    while (true)
    {
        cout << "Enter Tax Percentage: ";
        cin >> input;
        if (isPositveIntegerOnly(input))
        {
            if (IsValueBetweenOrEqual(stoi(input), lowerLimit, higherLimit))
            {
                break;
            }
        }

        cout << "Invalid Tax Percentage! Please enter a number between " << lowerLimit <<" and " <<higherLimit << endl;
        cout << "Enter any key to continue" << endl;
        getch();
    }

    return stoi(input);
}
string nameInput()
{
    string name = "";
    while (true)
    {
        cout << "Enter product name: ";
        cin >> name;

        if (name.length() >= 3 && isAlphabetOnly(name) && isFirstAlphabetCapital(name))
        {
            break;
        }
        cout << "Invalid name! Please enter a valid name (alphabets only,first letter capital, length is at least 3)" << endl;
    }
    return name;
}
string usernameInput()
{
    string username;
    while (true)
    {
        cout << "Enter username: ";
        cin >> username;

        if (username.length() >= 3 && isAlphabetOnly(username) && isFirstAlphabetCapital(username))
        {
            break;
        }
        cout << "Invalid username! Please enter a valid userame (alphabets only,first letter capital, length is at least 3)" << endl;
    }
    return username;
}
string roleInput()
{
    string role = "";
    while (true)
    {
        cout << "Enter Role (Admin or Customer): ";
        cin >> role;

        if (role == "Admin" || role == "Customer")
        {
            break;
        }
        cout << "Invalid role! Role can only be Admin or Customer" << endl;
    }
    return role;
}
string passwordInput()
{
    string password = "";
    while (true)
    {
        cout << "Enter password: ";
        cin >> password;

        if (password.length() >= 3)
        {
            break;
        }
        cout << "Invalid password! Please enter a valid password (Length is at least 3)" << endl;
    }
    return password;
}
bool isFirstAlphabetCapital(string input)
{
    if(isupper(input[0]))
    {
        return true;
    }
    return false;
}
bool isAlphabetOnly(string input)
{
    if (input.empty())
    {
        return false;
    }
    for (int i = 0; i < input.length(); i++)
    {
        if (!isalpha(input[i]))
        {
            return false;
        }
    }
    return true;
}

string typeInput()
{
    string type = "";
    while (true)
    {
        cout << "Enter product type: ";
        cin >> type;

        if (type.length() >= 3 && isAlphabetOnly(type))
        {
            break;
        }
        cout << "Invalid type! Please enter a valid type (alphabets only, length is at least 3)" << endl;
    }
    return type;
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
    string username = usernameInput();
    string password = passwordInput();
    string role = roleInput();

    if (signUpFunctionality(username, password, role))
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
    if (IsUsernameTaken(usernameInput))
    {
        return false;
    }
    addingCredentialsIntoArray(usernameInput, passwordInput, roleInput);

    return true;
}
void addingCredentialsIntoArray(string usernameInput, string passwordInput, string roleInput)
{
    usernames[credentialsCount] = usernameInput;
    passwords[credentialsCount] = passwordInput;
    roles[credentialsCount] = roleInput;
    credentialsCount++;
}
bool IsUsernameTaken(string usernameInput)
{
    for (int i = 0; i < credentialsCount; i++)
    {
        if (usernames[i] == usernameInput)
        {
            return true;
        }
    }
    return false;
}
string signInMenu()
{
    string username = usernameInput();
    string password = passwordInput();

    string roleOfSignedInUser = signInFunctionality(username, password);

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
        if (usernames[i] == usernameInput && passwords[i] == passwordInput)
        {
            currentSignedInUser = usernames[i];
            return roles[i];
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
char adminMenu()
{
    cout << "Select one of the following options number..." << endl;
    cout << "1. Add product" << endl;
    cout << "2. Update product" << endl;
    cout << "3. View all products " << endl;
    cout << "4. View product by name" << endl;
    cout << "5. Delete product" << endl;
    cout << "6. Exit" << endl;
    cout << "Your Option: ";
    char option = getch();
    cout << endl;
    return option;
}
char customerMenu()
{
    cout << "Select one of the following options number..." << endl;
    cout << "1. View All Products" << endl;
    cout << "2. Buy a product" << endl;
    cout << "3. View bought products" << endl;
    cout << "4. Exit" << endl;
    cout << "Your Option: ";
    char option = getch();
    cout << endl;
    return option;
}
void addProductMenu()
{

    string productNameInput = nameInput();

    //  string productNameInput="";
    //     cout << "testttt";
    //     cin >> productNameInput;

    if (getProductIndex(productNameInput) == -1)
    {

        string productTypeInput = typeInput(); // test
        // string productTypeInput="";
        // cout << "testttt";
        // cin >> productTypeInput;
        float productPriceInput = priceInput();

        float productTaxInput = taxInput(0, 50);

        float productQuantityInput = quantityInput(1, 100);

        addProductIntoArray(productNameInput, productTypeInput, productPriceInput, productTaxInput, productQuantityInput);

        cout << "Successfully Added Product!" << endl;
    }
    else
    {
        cout << "Error Adding Product!";
        cout << endl;
        cout << " Product Name already exists!" << endl;
    }
}
void viewProductByNameMenu()
{

    string productNameInput = nameInput();
    int productIndex = getProductIndex(productNameInput);
    if (productIndex != -1)
    {
        viewProductByNameFunctionality(productIndex);
    }
    else
    {
        cout << "Error Viewing Product!";
        cout << endl;
        cout << " Product does not exists!" << endl;
    }
}
void viewProductByNameFunctionality(int productIndex)
{
    cout << "Name\t\tType\t\tPrice\t\tTax\t\tTotalQuantity" << endl;
    cout << productNames[productIndex] << "\t\t"
         << productTypes[productIndex] << "\t\t"
         << productPrices[productIndex] << "\t\t"
         << productTaxes[productIndex] << "\t\t"
         << productQuantities[productIndex] << endl;
}
void viewAllProductsMenu()
{
    cout << "Name\t\tType\t\tPrice\t\tTax\t\tQuantity" << endl;

    for (int i = 0; i < productsCount; i++)
    {
        
        cout << productNames[i] << "\t\t"
             << productTypes[i] << "\t\t"
             << productPrices[i] << "\t\t"
             << productTaxes[i] << "\t\t"
             << productQuantities[i] << endl;
    }
}
void viewAllProductsMenuForCustomer()
{
    cout << "Name\t\tType\t\tPrice\t\tTax\t\tQuantity" << endl;

    for (int i = 0; i < productsCount; i++)
    {
        if(productQuantities[i]>0)
        {


        cout << productNames[i] << "\t\t"
             << productTypes[i] << "\t\t"
             << productPrices[i] << "\t\t"
             << productTaxes[i] << "\t\t"
             << productQuantities[i] << endl;
        }
    }
}
void deleteProductMenu()
{

    string productNameInput = nameInput();
    int productIndex = getProductIndex(productNameInput);
    if (productIndex != -1)
    {
        if (!isProductPurchased(productNameInput))
        {
            deleteProductFromArray(productIndex);
            cout << "Product deleted!"<<endl;

        }
        else
        {
            cout << "Error deleting Product!";
            cout << endl;
            cout << " Product already purchased!" << endl;
        }
    }
    else
    {
        cout << "Error deleting Product!";
        cout << endl;
        cout << " Product does not exists!" << endl;
    }
}
void deleteProductFromArray(int indexToBeRemoved)
{
    for (int i = indexToBeRemoved; i < productsCount - 1; i++)
    {
        productNames[i] = productNames[i + 1];
        productTypes[i] = productTypes[i + 1];
        productPrices[i] = productPrices[i + 1];
        productTaxes[i] = productTaxes[i + 1];
        productQuantities[i] = productQuantities[i + 1];
    }

    productsCount--;
}
void UpdateProductMenu()
{
    string productNameInput = nameInput();

    int productIndex = getProductIndex(productNameInput);

    if (productIndex != -1)
    {
        viewProductByNameFunctionality(productIndex);

        string productTypeInput = typeInput();

        float productPriceInput = priceInput();

        float productTaxInput = taxInput(0, 50);

        float productQuantityInput = quantityInput(1, 100);

        UpdateProductInArray(productIndex, productNameInput, productTypeInput, productPriceInput, productTaxInput, productQuantityInput);

        cout << "Successfully Updated Product!" << endl;
    }
    else
    {
        cout << "Error Updating Product!";
        cout << endl;
        cout << " Product does not exists!" << endl;
    }
}
int getProductIndex(string productNameInput)
{
    for (int i = 0; i < productsCount; i++)
    {
        if (productNames[i] == productNameInput)
        {
            return i;
        }
    }
    return -1;
}
void addProductIntoArray(string productNameInput, string productTypeInput, float productPriceInput, float productTaxInput, float productQuantityInput)
{
    productNames[productsCount] = productNameInput;
    productTypes[productsCount] = productTypeInput;
    productPrices[productsCount] = productPriceInput;
    productTaxes[productsCount] = productTaxInput;
    productQuantities[productsCount] = productQuantityInput;

    productsCount++;
}
void UpdateProductInArray(int index, string productNameInput, string productTypeInput, float productPriceInput, float productTaxInput, float productQuantityInput)
{
    productNames[index] = productNameInput;
    productTypes[index] = productTypeInput;
    productPrices[index] = productPriceInput;
    productTaxes[index] = productTaxInput;
    productQuantities[index] = productQuantityInput;
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

float calculateDiscountedPrice(float amount)
{

    if (amount >= 3000)
    {
        return (amount * 80) / 100;
    }
    else if (amount >= 2000)
    {
        return (amount * 90) / 100;
    }
    return amount;
}
void buyProductMenu()
{
    string productNameInput = nameInput();

    int productIndex = getProductIndex(productNameInput);

    if (productIndex != -1 &&productQuantities[productIndex]>0)
    {
        viewProductByNameFunctionality(productIndex);

        string type = productTypes[productIndex];
        int availableQuantity = productQuantities[productIndex];
        float initalPrice = productPrices[productIndex];
        float tax = productTaxes[productIndex];

        int toBuyQuantity = quantityInput(1, availableQuantity);
        float total = calculateTotal(initalPrice, toBuyQuantity, tax);
        float discountedPrice = calculateDiscountedPrice(total);

        cout << endl;
        cout << "Price with tax: " << total << endl;
        cout << "Final Price with discount: " << discountedPrice << endl;

        cout << "Press 1 to confirm purchase, any other key to cancel";
        char input = getch();
        if (input == '1')
        {
            cout << endl;
            cout << buyProductFunctionality(productIndex, productNameInput, type, initalPrice, tax, toBuyQuantity, discountedPrice);
            cout << endl;
        }
        else
        {
            cout << endl;
            cout << "Purchase Cancelled!";
            cout << endl;
        }
    }
    else
    {
        cout << "Error buying Product!";
        cout << endl;
        cout << " Product does not exists!" << endl;
    }
}
string buyProductFunctionality(int productIndex, string name, string type, float price, float tax, int toBuyQuantity, float discountedPrice)
{
    decreaseProductQuantity(productIndex, toBuyQuantity);
    addPurchasedProductIntoArray(name, type, price, tax, toBuyQuantity, discountedPrice);
    return "Product bought successfully!";
}
void decreaseProductQuantity(int productIndex, int toBuyQuantity)
{
    productQuantities[productIndex] = productQuantities[productIndex] - toBuyQuantity; // decreasing quantity from original products array.
}
void addPurchasedProductIntoArray(string name, string type, float price, float tax, int toBuyQuantity, float discountedPrice)
{
    purchasedProductNames[purchasedProductsCount] = name;
    purchasedProductTypes[purchasedProductsCount] = type;
    purchasedProductPrices[purchasedProductsCount] = price;
    purchasedProductTaxes[purchasedProductsCount] = tax;
    purchasedProductQuantities[purchasedProductsCount] = toBuyQuantity;
    purchasedProductTotalPrices[purchasedProductsCount] = discountedPrice;

    purchasersUsernames[purchasedProductsCount] = currentSignedInUser;

    purchasedProductsCount++;
}
void viewAllPurchasedProductsMenu()
{
    cout << "Name\t\tType\t\tPrice\t\tTax\t\tBoughtQuantity\t\tFinalPrice" << endl;

    for (int i = 0; i < purchasedProductsCount; i++)
    {
        if (purchasersUsernames[i] == currentSignedInUser)
        {
            cout << purchasedProductNames[i] << "\t\t"
                 << purchasedProductTypes[i] << "\t\t"
                 << purchasedProductPrices[i] << "\t\t"
                 << purchasedProductTaxes[i] << "\t\t"
                 << purchasedProductQuantities[i] << "\t\t"
                 << purchasedProductTotalPrices[i] << endl;
        }
    }
}
bool isProductPurchased(string name)
{
    for (int i = 0; i < purchasedProductsCount; i++)
    {
        if (purchasedProductNames[i] == name)
        {
            return true;
        }
        return false;
    }
}