#include "sort.h"
#include <cstring>

void sort(product v[], int n)
{
    product aux;
    int i, j, k, l;
    for (i = 1; i < n; i++)
    {
        j = i;
        while (strcmp(v[j].tip, v[j + 1].tip) == 0)
            j++;
        for (k = i; k < j; k++)
            for (l = k + 1; l <= j; l++)
                if (v[k].pret < v[l].pret)
                {
                    aux = v[k];
                    v[k] = v[l];
                    v[l] = aux;
                }
                else if (v[k].pret == v[l].pret)
                    if (stricmp(v[k].nume, v[l].nume) > 0)
                    {
                        aux = v[k];
                        v[k] = v[l];
                        v[l] = aux;
                    }

        i = j;
    }
}
