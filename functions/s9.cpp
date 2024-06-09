#include "sort.h"
#include <cstring>
#include <iostream>
#include <product.h>

using namespace std;

void s9(product v[201], int n)
{
    char productName[256];
    cout << "Product name= ";
    cin >> productName;
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        if (strcmp(productName, v[i].name) == 0)
            cout << "Units in store stock=" << v[i].storeStock
                 << " Units in supplier stock=" << v[i].supplierStock;
    }
}
