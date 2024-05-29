#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void s9(product v[201], int n)
{
    char numeprodus[256];
    cout << "Nume product= ";
    cin >> numeprodus;
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        if (strcmp(numeprodus, v[i].nume) == 0)
            cout << "Bucati in stoc magazin=" << v[i].stocmagazin
                 << " Bucati in stoc furnizor=" << v[i].stocfurnizor;
    }
}
