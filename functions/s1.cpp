#include "s1.h"
#include <cstring>
#include <iostream>
#include <product.h>
#include "sort.h"

using namespace std;

void s1(product v[201], int n)
{
    sort(v, n); // Call the sort function with the correct arguments
    cout << "These are the products in our promotion:" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (stricmp(v[i - 1].type, v[i].type) != 0)
            cout << endl;
        cout << v[i].name << ' ' << v[i].type << ' ' << v[i].manufacturer << ' '
             << v[i].labor << ' ' << v[i].price << ' ' << v[i].storeStock
             << ' ' << v[i].supplierStock << endl;
    }
}
