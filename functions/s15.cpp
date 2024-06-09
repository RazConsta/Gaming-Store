#include "sort.h"
#include <cstring>
#include <iostream>
#include <product.h>

using namespace std;

void s15(product v[201], int n, int &assemblyCost, int &actualCost)
{
    char productName[256], ans[3];
    int verif = 1;
    assemblyCost = actualCost = 0;
    cout << "To place an order, enter the desired products. After entering all the desired products, type <Finished>"
         << endl;
    do
    {
        cin >> productName;
        for (int i = 1; i <= n; i++)
            if (strcmp(productName, v[i].name) == 0)
            {
                assemblyCost += v[i].labor;
                actualCost += v[i].price;
                if (v[i].storeStock == 0)
                {
                    v[i].supplierStock -= 1;
                    verif = 2;
                }
                else
                {
                    v[i].storeStock -= 1;
                }
            }
    } while (strcmp(productName, "Finished") != 0);

    char code1[256], code2[256];
    strcpy(code1, "Happy Birthday!");
    strcpy(code2, "2017");
    char code[256];
    cin.get();
    cout << "Do you also want the components to be assembled? ";
    cin.get(ans, 3);
    cin.get();
    cout << "If you have a promotional code, please enter it. ";
    cin.get(code, 256);
    if (strcmp(code, code1) == 0)
    {
        cout << "Prices after applying the 10% coupon:" << endl;
        if (strcmp(ans, "Yes") == 0)
            if (assemblyCost)
                cout << "Assembly cost=" << assemblyCost - assemblyCost / 10 << " ";

        cout << "Actual cost=" << actualCost - actualCost / 10;
        cout << endl;
        cout << "Choose a delivery method:" << endl
             << "  a - pickup from showroom" << endl
             << "  b - home delivery" << endl;
        char var[256];
        cin.get();
        cin.get(var, 256);
        if (strcmp(var, "b") == 0)
        {
            if (verif == 1)
            {
                cout << "Enter the delivery address: ";
                char address[256];
                cin.get();
                cin.get(address, 256);
                cout << "Thank you for your order. Delivery will be made within a maximum of 2 working days.";
            }
            else if (verif == 2)
            {
                cout << "Enter the delivery address: ";
                char address[256];
                cin.get();
                cin.get(address, 256);
                cout << "Thank you for your order. Delivery will be made within a maximum of 5 working days.";
            }
        }
        else if (strcmp(var, "a") == 0)
        {
            if (verif == 1)
                cout << "Thank you for your order. The products can be picked up from the showroom."
                     << endl;
            else if (verif == 2)
            {
                char phoneNumber[256], email[256];
                cout << "Choose a contact method for notification when the products arrive in the store's stock";
                cout << endl
                     << "  a - phone call" << endl
                     << "  b - email"
                     << endl;
                char choice[256];
                cin.get();
                cin.get(choice, 256);
                if (strcmp(choice, "a") == 0)
                {
                    cout << "Phone number= ";
                    cin.get();
                    cin.get(phoneNumber, 256);
                    cout << "You will be contacted when the product arrives in the store's stock - maximum 5 working days.";
                }
                else if (strcmp(choice, "b") == 0)
                {
                    cout << "Email= ";
                    cin.get();
                    cin.get(email, 256);
                    cout << "You will be contacted when the product arrives in the store's stock - maximum 5 working days.";
                }
            }
        }
    }
    else if (strcmp(code, code2) == 0)
    {
        cout << "Prices after applying the 5% coupon:" << endl;
        if (strcmp(ans, "Yes") == 0)
            if (assemblyCost)
                cout << "Assembly cost=" << assemblyCost - assemblyCost / 20 << " ";

        cout << "Actual cost=" << actualCost - actualCost / 20;
        cout << endl;
        cout << "Choose a delivery method:" << endl
             << "  a - pickup from showroom" << endl
             << "  b - home delivery" << endl;
        char var[256];
        cin.get();
        cin.get(var, 256);
        if (strcmp(var, "b") == 0)
        {
            if (verif == 1)
            {
                cout << "Enter the delivery address: ";
                char address[256];
                cin.get();
                cin.get(address, 256);
                cout << "Thank you for your order. Delivery will be made within a maximum of 2 working days.";
            }
            else if (verif == 2)
            {
                cout << "Enter the delivery address: ";
                char address[256];
                cin.get();
                cin.get(address, 256);
                cout << "Thank you for your order. Delivery will be made within a maximum of 5 working days.";
            }
        }
        else if (strcmp(var, "a") == 0)
        {
            if (verif == 1)
                cout << "Thank you for your order. The products can be picked up from the showroom."
                     << endl;
            else if (verif == 2)
            {
                char phoneNumber[256], email[256];
                cout << "Choose a contact method for notification when the products arrive in the store's stock";
                cout << endl
                     << "  a - phone call" << endl
                     << "  b - email"
                     << endl;
                char choice[256];
                cin.get();
                cin.get(choice, 256);
                if (strcmp(choice, "a") == 0)
                {
                    cout << "Phone number= ";
                    cin.get();
                    cin.get(phoneNumber, 256);
                    cout << "You will be contacted when the product arrives in the store's stock - maximum 5 working days.";
                }
                else if (strcmp(choice, "b") == 0)
                {
                    cout << "Email= ";
                    cin.get();
                    cin.get(email, 256);
                    cout << "You will be contacted when the product arrives in the store's stock - maximum 5 working days.";
                }
            }
        }
    }
    else
    {
        cout << "Assembly cost= " << assemblyCost << endl;
        cout << "Actual cost= " << actualCost << endl;
        cout << "Thank you for your order. The products can be picked up from the showroom.";
    }
}
