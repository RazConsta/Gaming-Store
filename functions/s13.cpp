#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void s13(product v[201], int n, int &asamblare, int &efectiv, int &ok)
{
    char numeprodus[256];
    asamblare = efectiv = ok = 0;
    cout << "Pentru calcularea valorii totale a unei comenzi,introduceti "
            "produsele dorite.Dupa ce ati introdus toate produsele dorite,"
            "tastati <Terminat>"
         << endl;
    do
    {
        cin >> numeprodus;
        for (int i = 1; i <= n; i++)
            if (strcmp(numeprodus, v[i].nume) == 0)
                asamblare = asamblare + v[i].manopera, efectiv = efectiv + v[i].pret;
    } while (strcmp(numeprodus, "Terminat") != 0);

    if (asamblare)
    {
        cout << "Doriti si montarea componentelor?" << endl;
        char ans[3];
        cin.get();
        cin.get(ans, 3);
        if (strcmp(ans, "Da") == 0)
        {
            cout << "Cost asamblare=" << asamblare << " ";
            ok = 1;
        }
    }
    cout << "Cost efectiv=" << efectiv;
}
