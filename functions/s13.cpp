#include "sort.h"
#include <cstring>
#include <iostream>
#include <product.h>

using namespace std;

void s13(product v[201], int n, int &assemblyCost, int &actualCost, int &ok)
{
    char productName[256];
    assemblyCost = actualCost = ok = 0;
    cout << "To calculate the total value of an order, enter the desired products. After entering all the desired products, type <Finished>"
         << endl;
    do
    {
        cin >> productName;
        for (int i = 1; i <= n; i++)
            if (strcmp(productName, v[i].name) == 0)
                assemblyCost = assemblyCost + v[i].labor, actualCost = actualCost + v[i].price;
    } while (strcmp(productName, "Finished") != 0);

    if (assemblyCost)
    {
        cout << "Do you also want the components to be assembled?" << endl;
        char ans[3];
        cin.get();
        cin.get(ans, 3);
        if (strcmp(ans, "Yes") == 0)
        {
            cout << "Assembly cost=" << assemblyCost << " ";
            ok = 1;
        }
    }
    cout << "Actual cost=" << actualCost;
}
