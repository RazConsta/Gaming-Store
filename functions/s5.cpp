#include "sort.h"
#include <cstring>
#include <iostream>
#include <product.h>

using namespace std;

void s5(product v[201], int n)
{
    product aux, a[201];
    for (int i = 1; i <= n; i++)
        a[i] = v[i];

    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i].price < a[j].price)
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }

    cout << "These are the products in our promotion, sorted in descending order by price"
         << endl
         << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i].name << ' ' << a[i].type << ' ' << a[i].manufacturer << ' '
             << a[i].labor << ' ' << a[i].price << ' ' << a[i].storeStock
             << ' ' << a[i].supplierStock << endl;
}
