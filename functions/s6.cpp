#include "sort.h"
#include <cstring>
#include <iostream>
#include <product.h>

using namespace std;

void s6(product v[201], int n)
{
    product aux, a[201], b[201];
    // a=copy of the initial structure
    // b=temporary structure
    // prod=array with manufacturer names
    char prod[20][20], auxx[20];
    int i = 1, j = 1, k = 1, l = 1, m = 1, z = 1;
    for (i = 1; i <= n; i++)
        a[i] = v[i];

    for (i = 1; i <= n; i++)
    {
        char manufacturerName[20];
        int ok = 1;
        strcpy(manufacturerName, a[i].manufacturer);
        for (j = 1; j <= 19; j++)
            if (stricmp(prod[j], manufacturerName) == 0)
                ok = 0;
        if (ok)
            strcpy(prod[k], manufacturerName), k++;
    }
    k--;
    for (i = 1; i < k; i++)
        for (j = i + 1; j <= k; j++)
            if (stricmp(prod[i], prod[j]) > 0)
            {
                strcpy(auxx, prod[i]);
                strcpy(prod[i], prod[j]);
                strcpy(prod[j], auxx);
            }

    cout << "These are the products in our promotion, sorted alphabetically by manufacturer:"
         << endl
         << endl;

    for (i = 1; i <= k; i++)
    {
        int nr = 1;
        for (j = 1; j <= n; j++)
            if (stricmp(prod[i], a[j].manufacturer) == 0)
                b[nr] = a[j], nr++;
        nr--;

        for (m = 1; m < nr; m++)
            for (z = m + 1; z <= nr; z++)
                if (b[m].price < b[z].price)
                    aux = b[m], b[m] = b[z], b[z] = aux;
                else if (b[m].price == b[z].price)
                    if (stricmp(b[m].name, b[z].name) >= 0)
                    {
                        aux = b[m];
                        b[m] = b[z];
                        b[z] = aux;
                    }

        for (l = 1; l <= nr; l++)
            cout << b[l].name << ' ' << b[l].type << ' ' << b[l].manufacturer
                 << ' ' << b[l].labor << ' ' << b[l].price << ' '
                 << b[l].storeStock << ' ' << b[l].supplierStock << endl;

        cout << endl;
    }
}
