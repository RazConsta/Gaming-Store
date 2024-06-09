#include <cstring>
#include <iostream>
#include <product.h>
#include "headers/sort.h"

using namespace std;

void s10(product v[201], int &n)
{
    product aux, a;
    cout << "Security question: where did the company name come from? ";
    char answer[256];
    cin.get();
    cin.get(answer, 256);
    cout << endl;
    if (strcmp(answer, "RAZvan alEX") == 0)
    {
        cout << "Enter the information about the new product in the following format: "
                "Name-Type-Manufacturer-Assembly cost (except for peripherals)-Product price-Number of units in store stock-Number of units in supplier stock"
             << endl;
        cin >> aux.name >> aux.type >> aux.manufacturer >> aux.labor >> aux.price >> aux.storeStock >> aux.supplierStock;

        n++;

        for (int i = 1; i < n; i++)
            if (((strcmp(v[i].type, aux.type) == 0) && (strcmp(v[i + 1].type, aux.type) != 0)) || ((i == n - 1) && (strcmp(v[i].type, aux.type))))
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
        cout << "The product has been added to the Razex Custom PCs offer";
    }
    else
        cout << "Wrong answer. The administrative team has been alerted of this security breach.";
}
