#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void s10(product v[201], int &n)
{
    product aux, a;
    cout << "Intrebare de securitate:de unde a aparut numele companiei? ";
    char raspuns[256];
    cin.get();
    cin.get(raspuns, 256);
    cout << endl;
    if (strcmp(raspuns, "RAZvan alEX") == 0)
    {
        cout << "Introduceti informatiile legate de noul product sub forma "
                "urmatoare:Nume-Tip-Producator-Pret asamblare(exceptie "
                "sunt perifericele)-Pret product-Nr. bucati in stoc "
                "magazin-Nr. bucati in stoc furnizor"
             << endl;
        cin >> aux.nume >> aux.tip >> aux.producator >> aux.manopera >> aux.pret >> aux.stocmagazin >> aux.stocfurnizor;

        n++;

        for (int i = 1; i < n; i++)
            if (((strcmp(v[i].tip, aux.tip) == 0) && (strcmp(v[i + 1].tip, aux.tip) != 0)) || ((i == n - 1) && (strcmp(v[i].tip, aux.tip))))
            {
                i++;

                for (int j = n; j > i; j--)
                {
                    a = v[j];
                    v[j] = v[j - 1];
                    v[j - 1] = a;
                }
                v[i] = aux;
                break;
            }
        sort(v, n);
        cout << "Produsul a fost introduc in oferta Razex Custom PCs";
    }
    else
        cout << "Raspuns gresit.Echipei administrative a fost alertata de "
                "aceasta bresa de securitate.";
}
