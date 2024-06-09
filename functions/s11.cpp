#include "sort.h"
#include <cstring>
#include <iostream>
#include <product.h>

using namespace std;

void s11(product v[201], int &n)
{
    char productName[256];
    cout << "Security question: where did the company name come from? ";
    char answer[256];
    cin.get();
    cin.get(answer, 256);
    cout << endl;
    if (strcmp(answer, "RAZvan alEX") == 0)
    {
        cout << "Product to be deleted= ";
        cin >> productName;
        int position = 0, i;

        for (i = 1; i <= n; i++)
            if (strcmp(productName, v[i].name) == 0)
                position = i;

        for (i = position; i < n; i++)
            v[i] = v[i + 1];
        n--;

        cout << endl
             << "The product has been deleted";
    }
    else
        cout << "Wrong answer. The administrative team has been alerted of this security breach.";
}
