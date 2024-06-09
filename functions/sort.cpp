#include "sort.h"
#include <cstring>
#include <product.h>

void sort(product v[], int n)
{
    product aux;
    int i, j, k, l;
    for (i = 1; i < n; i++)
    {
        j = i;
        while (j < n && strcmp(v[j].type, v[j + 1].type) == 0)
            j++;
        for (k = i; k < j; k++)
            for (l = k + 1; l <= j; l++)
                if (v[k].price < v[l].price)
                {
                    aux = v[k];
                    v[k] = v[l];
                    v[l] = aux;
                }
                else if (v[k].price == v[l].price)
                    if (stricmp(v[k].name, v[l].name) > 0)
                    {
                        aux = v[k];
                        v[k] = v[l];
                        v[l] = aux;
                    }

        i = j;
    }
}
