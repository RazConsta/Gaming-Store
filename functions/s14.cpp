#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void s14(int assemblyCost, int actualCost, int ok)
{
    char code1[256], code2[256];
    strcpy(code1, "Happy Birthday!");
    strcpy(code2, "2017");
    char code[256];
    cin.get();
    cout << "Promotional code= ";
    cin.get(code, 256);
    if (strcmp(code, code1) == 0)
    {
        cout << "Prices after applying the 10% coupon:" << endl;
        if (ok)
            if (assemblyCost)
                cout << "Assembly cost=" << assemblyCost - assemblyCost / 10 << " ";

        cout << "Actual cost=" << actualCost - actualCost / 10;
    }
    else if (strcmp(code, code2) == 0)
    {
        cout << "Prices after applying the 5% coupon:" << endl;
        if (ok)
            if (assemblyCost)
                cout << "Assembly cost=" << assemblyCost - assemblyCost / 20 << " ";

        cout << "Actual cost=" << actualCost - actualCost / 20;
    }
    else
        cout << "The entered code is not correct.";
}
