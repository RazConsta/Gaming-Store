#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void s7(product v[201], int n)
{

    char numeprodus[256];
    int stoc1, stoc2;
    cout << "Intrebare de securitate:de unde a aparut numele companiei? ";
    char raspuns[256];
    cin.get();
    cin.get(raspuns, 256);
    cout << endl;
    if (strcmp(raspuns, "RAZvan alEX") == 0)
    {
        cout << "Introduceti numele produsului ";
        cin >> numeprodus;
        cout << endl;
        cout << "Introduceti valorile noi ale stocului din magazin si "
                "stocului furnizor ";
        cin >> stoc1 >> stoc2;
        cout << endl
             << "Stocul a fost actualizat.";

        for (int i = 1; i <= n; i++)
            if (strcmp(v[i].nume, numeprodus) == 0)
            {
                v[i].stocmagazin = stoc1;
                v[i].stocfurnizor = stoc2;
            }
    }
    else
        cout << "Raspuns gresit.Echipa administrativa a fost alertata de "
                "aceasta bresa de securitate.";
}
