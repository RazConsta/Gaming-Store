#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void s11(product v[201], int &n)
{
    char numeprodus[256];
    cout << "Intrebare de securitate:de unde a aparut numele companiei? ";
    char raspuns[256];
    cin.get();
    cin.get(raspuns, 256);
    cout << endl;
    if (strcmp(raspuns, "RAZvan alEX") == 0)
    {
        cout << "Produsul care urmeaza a fi sters= ";
        cin >> numeprodus;
        int poz = 0, i;

        for (i = 1; i <= n; i++)
            if (strcmp(numeprodus, v[i].nume) == 0)
                poz = i;

        for (i = poz; i < n; i++)
            v[i] = v[i + 1];
        n--;

        cout << endl
             << "Produsul a fost sters";
    }
    else
        cout << "Raspunsul este gresit.Echipa administrativa a fost "
                "alertata de aceasta bresa de securitate.";
}
