#include "sort.h"
#include <cstring>
#include <iostream>
#include <product.h>

using namespace std;

void s8(product v[201], int n)
{
    char productName[256];
    cout << "Security question: where did the company name come from? ";
    char answer[256];
    cin.get();
    cin.get(answer, 256);
    cout << endl;
    if (strcmp(answer, "RAZvan alEX") == 0)
    {
        cout << "Enter the product name ";
        cin >> productName;
        int newPrice;
        cout << endl
             << "Enter the new price of the product ";
        cin >> newPrice;

        for (int i = 1; i <= n; i++)
            if (strcmp(v[i].name, productName) == 0)
                v[i].price = newPrice;

        cout << endl
             << "The price has been updated.";
    }
    else
        cout << "Wrong answer. The administrative team has been alerted of this security breach.";
}
