#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

int main () {
    int prodCode, quantity, price, tempPrice, totalPrice = 0, payment, change;
    string prodName;
    string purchasedItems[10];
    int itemQuantity[10], subTotal[10];
    int j = 0, k = 0;
    char again[100];

    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "       Welcome to the PokeMart!         " << endl;
    cout << "----------------------------------------" << endl;
    cout << "Code        Product        Price        " << endl;
    cout << "----------------------------------------" << endl;
    cout << "1001        Potion         10           " << endl;
    cout << "1002        Antidote       20           " << endl;
    cout << "1003        PokeBall       30           " << endl;
    cout << "1004        GreatBall      40           " << endl;
    cout << "1005        UltraBall      50           " << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;

    do {
        cout << "Enter product code: "; cin >> prodCode;

        switch (prodCode) {
            case 1001:
                prodName = "Potion";
                price = 10;
                break;
            case 1002:
                prodName = "Antidote";
                price = 20;
                break;
            case 1003:
                prodName = "PokeBall";
                price = 30;
                break;
            case 1004:
                prodName = "GreatBall";
                price = 40;
                break;
            case 1005:
                prodName = "UltraBall";
                price = 50;
                break;
            default:
                cout << endl << "Invalid input." << endl;
                return 0;
        }

        cout << endl << "Product : " << prodName << endl;
        cout <<         "Price   : " << price << endl;

        do {
            cout << endl << "How much " << prodName << "s? "; cin >> quantity;

            if (!cin) {
                cout << endl << "Input in numbers next time." << endl;
                return 0;
            }
            else if (quantity < 1)
                cout << endl << "You can't have... nothing... of something... you know?" << endl;
            else if (quantity > 100)
                cout << endl << "You can't buy that many. It's store policy." << endl;
        } while (quantity > 100 || quantity < 1);


        tempPrice = price * quantity;
        totalPrice += tempPrice;
        cout << endl << "The total price is: " << totalPrice << endl;

        purchasedItems[j] = prodName;
        itemQuantity[j] = quantity;
        subTotal[j] = tempPrice;
        j++;

        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "Order another product? (Y/N) ";
        cin.getline(again, 100);
        cin.getline(again, 100);

        while (again[0] != 'Y' && again[0] != 'N') {
            if (again[0] != 'Y' && again[0] != 'N')
                cout << endl << "Invalid answer" << endl;

            cout << "Order another product? (Y/N) ";
            cin.getline(again, 100);
        }

    }
    while (again[0] == 'Y');

    cout << "----------------------------------------" << endl;
    cout << "              Transaction:              " << endl;
    cout << "Product      Quantity       Subtotal    " << endl;

    for (k = 0; k < j; k++)
        cout << left << setw(13) << purchasedItems[k] << setw(15) << itemQuantity[k] << subTotal[k] << endl;

    cout << endl << "Total Price: " << totalPrice << endl;
    cout << "----------------------------------------" << endl;

    do {
        cout << "Insert payment: "; cin >> payment;

        change = payment - totalPrice;

        if (!cin) {
            cout << endl << "Invalid input." << endl;
            return 0;
        }
        else if (payment < 0)
            cout << endl << payment << "? " << "You want us to pay you?" << endl << endl;
        else if (payment < totalPrice)
            cout << endl << "Insufficient amount. Please try again." << endl << endl;
    } while (payment < totalPrice || !cin);

    cout << "----------------------------------------" << endl;
    cout << "              Receipt                   " << endl;
    cout << "Product      Quantity       Subtotal    " << endl;

    for (k = 0; k < j; k++)
        cout << left << setw(13) << purchasedItems[k] << setw(15) << itemQuantity[k] << subTotal[k] << endl;

    cout << "----------------------------------------" << endl;
    cout << "You paid      : " << payment              << endl;
    cout << "Total Price   : " << totalPrice           << endl;
    cout << "Your change is: " << change               << endl;
    cout << "----------------------------------------" << endl;

    cout << endl << "Thank you for your purchase!" << endl;

    return 0;
}
