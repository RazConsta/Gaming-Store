#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void s6(product v[201], int n)
{
    product aux, a[201], b[201];
    // a=copie structura initiala
    // b=structura temporara
    // prod=matrice cu nume producatori
    char prod[20][20], auxx[20];
    int i = 1, j = 1, k = 1, l = 1, m = 1, z = 1;
    for (i = 1; i <= n; i++)
        a[i] = v[i];

    for (i = 1; i <= n; i++)
    {
        char numep[20];
        int ok = 1;
        strcpy(numep, a[i].producator);
        for (j = 1; j <= 19; j++)
            if (stricmp(prod[j], numep) == 0)
                ok = 0;
        if (ok)
            strcpy(prod[k], numep), k++;
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

    cout << "Acestea sunt produsele din promotia noastra,sortate alfabetic "
            "dupa producator:"
         << endl
         << endl;

    for (i = 1; i <= k; i++)
    {
        int nr = 1;
        for (j = 1; j <= n; j++)
            if (stricmp(prod[i], a[j].producator) == 0)
                b[nr] = a[j], nr++;
        nr--;

        for (m = 1; m < nr; m++)
            for (z = m + 1; z <= nr; z++)
                if (b[m].pret < b[z].pret)
                    aux = b[m], b[m] = b[z], b[z] = aux;
                else if (b[m].pret == b[z].pret)
                    if (stricmp(b[m].nume, b[z].nume) >= 0)
                    {
                        aux = b[m];
                        b[m] = b[z];
                        b[z] = aux;
                    }

        for (l = 1; l <= nr; l++)
            cout << b[l].nume << ' ' << b[l].tip << ' ' << b[l].producator
                 << ' ' << b[l].manopera << ' ' << b[l].pret << ' '
                 << b[l].stocmagazin << ' ' << b[l].stocfurnizor << endl;

        cout << endl;
    }
}
