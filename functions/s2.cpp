#include "sort.h"
#include <cstring>
#include <iostream>
#include <product.h>

using namespace std;

void s2(product v[201], int n)
{
    char s[256];
    cout << "Desired type=";
    cin >> s;
    cout << endl
         << "The following products meet your requirements:"
         << endl
         << endl;
    product aux, a[201];
    int i, j, nr = 1;

    for (i = 1; i <= n; i++)
        if (strcmp(s, v[i].type) == 0)
            a[nr] = v[i], nr++;
    nr--;

    for (i = 1; i < nr; i++)
        for (j = i + 1; j <= nr; j++)
            if (a[i].price < a[j].price)
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
            else if (v[i].price == v[j].price)
                if (stricmp(v[i].name, v[j].name) > 0)
                {
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }

    for (i = 1; i <= nr; i++)
        cout << a[i].name << ' ' << a[i].type << ' ' << a[i].manufacturer << ' '
             << a[i].labor << ' ' << a[i].price << ' ' << a[i].storeStock
             << ' ' << a[i].supplierStock << endl;
}
