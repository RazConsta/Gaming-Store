#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void s14(int asamblare, int efectiv, int ok)
{
    char cod1[256], cod2[256];
    strcpy(cod1, "La multi ani!");
    strcpy(cod2, "2017");
    char cod[256];
    cin.get();
    cout << "Cod promotional= ";
    cin.get(cod, 256);
    if (strcmp(cod, cod1) == 0)
    {
        cout << "Preturi dupa aplicarea cuponului de 10%:" << endl;
        if (ok)
            if (asamblare)
                cout << "Cost asamblare=" << asamblare - asamblare / 10 << " ";

        cout << "Cost efectiv=" << efectiv - efectiv / 10;
    }
    else

        if (strcmp(cod, cod2) == 0)
    {
        cout << "Preturi dupa aplicarea cuponului de 5%:" << endl;
        if (ok)
            if (asamblare)
                cout << "Cost asamblare=" << asamblare - asamblare / 20 << " ";

        cout << "Cost efectiv=" << efectiv - efectiv / 20;
    }
    else
        cout << "Codul introdus nu este corect.";
}
