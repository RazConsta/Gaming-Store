#include "sort.h"
#include <cstring>
#include <iostream>
#include <product.h>

using namespace std;

void s7(product v[201], int n)
{
    char productName[256];
    int storeStock, supplierStock;
    cout << "Security question: where did the company name come from? ";
    char answer[256];
    cin.get();
    cin.get(answer, 256);
    cout << endl;
    if (strcmp(answer, "RAZvan alEX") == 0)
    {
        cout << "Enter the product name ";
        cin >> productName;
        cout << endl;
        cout << "Enter the new values for the store stock and supplier stock ";
        cin >> storeStock >> supplierStock;
        cout << endl
             << "Stock has been updated.";

        for (int i = 1; i <= n; i++)
            if (strcmp(v[i].name, productName) == 0)
            {
                v[i].storeStock = storeStock;
                v[i].supplierStock = supplierStock;
            }
    }
    else
        cout << "Wrong answer. The administrative team has been alerted of this security breach.";
}
