#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void s5(product v[201], int n)
{
    product aux, a[201];
    for (int i = 1; i <= n; i++)
        a[i] = v[i];

    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i].pret < a[j].pret)
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }

    cout << "Acestea sunt produsele din promotia noastra,sortate descrescator"
            " dupa pret"
         << endl
         << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i].nume << ' ' << a[i].tip << ' ' << a[i].producator << ' '
             << a[i].manopera << ' ' << a[i].pret << ' ' << a[i].stocmagazin
             << ' ' << a[i].stocfurnizor << endl;
}