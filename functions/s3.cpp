#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void s3(product v[201], int n)
{
    char s[256];
    cout << "Producatorul dorit=";
    cin >> s;
    cout << endl
         << "Urmatoarele produse corespund cerintelor dumneavoastra:"
         << endl
         << endl;
    product aux, a[201];
    int i, j, nr = 1;

    for (i = 1; i <= n; i++)
        if (strcmp(s, v[i].producator) == 0)
            a[nr] = v[i], nr++;
    nr--;

    for (i = 1; i < nr; i++)
        for (j = i + 1; j <= nr; j++)
            if (a[i].pret < a[j].pret)
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
            else if (v[i].pret == v[j].pret)
                if (stricmp(v[i].nume, v[j].nume) > 0)
                {
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }

    for (i = 1; i <= nr; i++)
        cout << a[i].nume << ' ' << a[i].tip << ' ' << a[i].producator << ' '
             << a[i].manopera << ' ' << a[i].pret << ' ' << a[i].stocmagazin
             << ' ' << a[i].stocfurnizor << endl;
}