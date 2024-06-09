#include "sort.h"
#include <cstring>
#include <iostream>
#include <product.h>

using namespace std;

void s4(product v[201], int n)
{
    char s[256];
    product a[201], aux;
    cout << "Product manufacturer=";
    cin >> s;
    int minBudget, maxBudget, nr = 1;
    cout << "Minimum budget=";
    cin >> minBudget;
    cout << "Maximum budget=";
    cin >> maxBudget;
    cout << endl
         << "The following products meet your requirements:"
         << endl
         << endl;

    for (int i = 1; i <= n; i++)
        if (minBudget <= v[i].price && maxBudget >= v[i].price && strcmp(s, v[i].manufacturer) == 0)
            a[nr] = v[i], nr++;
    nr--;

    for (int i = 1; i < nr; i++)
        for (int j = i + 1; j <= nr; j++)
            if (a[i].price < a[j].price)
                aux = a[i], a[i] = a[j], a[j] = aux;
            else if (v[i].price == v[j].price)
                if (stricmp(v[i].name, v[j].name) >= 0)
                {
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }

    for (int i = 1; i <= nr; i++)
        cout << a[i].name << ' ' << a[i].type << ' ' << a[i].manufacturer << ' '
             << a[i].labor << ' ' << a[i].price << ' ' << a[i].storeStock
             << ' ' << a[i].supplierStock << endl;
}
