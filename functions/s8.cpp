#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void s8(product v[201], int n)
{
    char numeprodus[256];
    cout << "Intrebare de securitate:de unde a aparut numele companiei? ";
    char raspuns[256];
    cin.get();
    cin.get(raspuns, 256);
    cout << endl;
    if (strcmp(raspuns, "RAZvan alEX") == 0)
    {
        cout << "Introduceti numele produsului ";
        cin >> numeprodus;
        int pretnou;
        cout << endl
             << "Introduceti noul pret al produsului ";
        cin >> pretnou;

        for (int i = 1; i <= n; i++)
            if (strcmp(v[i].nume, numeprodus) == 0)
                v[i].pret = pretnou;

        cout << endl
             << "Pretul a fost actualizat.";
    }
    else
        cout << "Raspuns gresit.Echipa administrativa a fost alertata de "
                "aceasta bresa de securitate.";
}
