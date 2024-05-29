#include "s1.h"
#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void s1(product v[201], int n)
{
    sort(v, n);
    cout << "Acestea sunt produsele din promotia noastra:" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (stricmp(v[i - 1].tip, v[i].tip) != 0)
            cout << endl;
        cout << v[i].nume << ' ' << v[i].tip << ' ' << v[i].producator << ' '
             << v[i].manopera << ' ' << v[i].pret << ' ' << v[i].stocmagazin
             << ' ' << v[i].stocfurnizor << endl;
    }
}
