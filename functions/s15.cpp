#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void s15(product v[201], int n, int &asamblare, int &efectiv)
{

    char numeprodus[256], ans[3];
    int verif = 1;
    asamblare = efectiv = 0;
    cout << "Pentru lansarea comenzii,introduceti produsele dorite.Dupa ce "
            "ati introdus toate produsele dorite,tastati <Terminat>"
         << endl;
    do
    {
        cin >> numeprodus;
        for (int i = 1; i <= n; i++)
            if (strcmp(numeprodus, v[i].nume) == 0)
            {
                asamblare = asamblare + v[i].manopera;
                efectiv = efectiv + v[i].pret;
                if (v[i].stocmagazin == 0)
                    v[i].stocfurnizor -= 1, verif = 2;
                else
                    v[i].stocmagazin -= 1;
            }

    } while (strcmp(numeprodus, "Terminat") != 0);

    char cod1[256], cod2[256];
    strcpy(cod1, "La multi ani!");
    strcpy(cod2, "2017");
    char cod[256];
    cin.get();
    cout << "Doriti si asamblarea componentelor? ";
    cin.get(ans, 3);
    cin.get();
    cout << "Daca aveti un cod promotional,va rugam sa il introduceti. ";
    cin.get(cod, 256);
    if (strcmp(cod, cod1) == 0)
    {
        cout << "Preturi dupa aplicarea cuponului de 10%:" << endl;
        if (strcmp(ans, "Da") == 0)
            if (asamblare)
                cout << "Cost asamblare=" << asamblare - asamblare / 10 << " ";

        cout << "Cost efectiv=" << efectiv - efectiv / 10;
        cout << endl;
        cout << "Alegeti o metoda de livrare a comenzii:" << endl
             << "  a - ridicare din showroom" << endl
             << "  b - livrare la domiciliu" << endl;
        char var[256];
        cin.get();
        cin.get(var, 256);
        if (strcmp(var, "b") == 0)
        {
            if (verif == 1)
            {
                cout << "Introduceti adresa de livrare: ";
                char adresa[256];
                cin.get();
                cin.get(adresa, 256);
                cout << "Va multumim pentru comanda.Livrarea se va efectua "
                        "in maxim 2 zile lucratoare.";
            }

            else if (verif == 2)
            {
                cout << "Introduceti adresa de livrare: ";
                char adresa[256];
                cin.get();
                cin.get(adresa, 256);
                cout << "Va multumim pentru comanda.Livrarea se va efectua "
                        "in maxim 5 zile lucratoare.";
            }
        }
        else if (strcmp(var, "a") == 0)
        {
            if (verif == 1)
                cout << "Va multumim pentru comanda.Produsele pot fi "
                        "ridicate din showroom."
                     << endl;
            else if (verif == 2)
            {
                char nrtel[256], email[256];
                cout << "Alegeti o metoda de contact pentru notificare in "
                        "momentul in care produsele ajung in stocul magazinului";
                cout << endl
                     << "  a - apel telfonic" << endl
                     << "  b - email"
                     << endl;
                char alegere[256];
                cin.get();
                cin.get(alegere, 256);
                if (strcmp(alegere, "a") == 0)
                {
                    cout << "Numar telefon= ";
                    cin.get();
                    cin.get(nrtel, 256);
                    cout << "Veti fi contactat cand produsul vine in stocul "
                            "magazinului.-maxim 5 zile lucratoare";
                }
                else if (strcmp(alegere, "b") == 0)
                {
                    cout << "email= ";
                    cin.get();
                    cin.get(email, 256);
                    cout << "Veti fi contactat cand produsul vine in stocul "
                            "magazinului.-maxim 5 zile lucratoare";
                }
            }
        }
    }

    else

        if (strcmp(cod, cod2) == 0)
    {
        cout << "Preturi dupa aplicarea cuponului de 5%:" << endl;
        if (strcmp(ans, "Da") == 0)
            if (asamblare)
                cout << "Cost asamblare=" << asamblare - asamblare / 20 << " ";

        cout << "Cost efectiv=" << efectiv - efectiv / 20;
        cout << endl;
        cout << "Alegeti o metoda de livrare a comenzii:" << endl
             << "  a - ridicare din showroom" << endl
             << "  b - livrare la domiciliu" << endl;
        char var[256];
        cin.get();
        cin.get(var, 256);
        if (strcmp(var, "b") == 0)
        {
            if (verif == 1)
            {
                cout << "Introduceti adresa de livrare: ";
                char adresa[256];
                cin.get();
                cin.get(adresa, 256);
                cout << "Va multumim pentru comanda.Livrarea se va efectua in "
                        "maxim 2 zile lucratoare.";
            }

            else if (verif == 2)
            {
                cout << "Introduceti adresa de livrare: ";
                char adresa[256];
                cin.get();
                cin.get(adresa, 256);
                cout << "Va multumim pentru comanda.Livrarea se va efectua "
                        "in maxim 5 zile lucratoare.";
            }
        }
        else if (strcmp(var, "a") == 0)
        {
            if (verif == 1)
                cout << "Va multumim pentru comanda.Produsele pot fi ridicate"
                        " din showroom."
                     << endl;
            else if (verif == 2)
            {
                char nrtel[256], email[256];
                cout << "Alegeti o metoda de contact pentru notificare in"
                        " momentul in care produsele ajung in stocul "
                        "magazinului";
                cout << endl
                     << "  a - apel telfonic" << endl
                     << "  b - email"
                     << endl;
                char alegere[256];
                cin.get();
                cin.get(alegere, 256);
                if (strcmp(alegere, "a") == 0)
                {
                    cout << "Numar telefon= ";
                    cin.get();
                    cin.get(nrtel, 256);
                    cout << "Veti fi contactat cand produsul vine in stocul "
                            "magazinului.-maxim 5 zile lucratoare";
                }
                else if (strcmp(alegere, "b") == 0)
                {
                    cout << "email= ";
                    cin.get();
                    cin.get(email, 256);
                    cout << "Veti fi contactat cand produsul vine in stocul "
                            "magazinului.-maxim 5 zile lucratoare";
                }
            }
        }
    }

    else
    {
        cout << "Cost asamblare= " << asamblare << endl;
        cout << "Cost efectiv= " << efectiv << endl;
        cout << "Va multumim pentru comanda .Produsele pot fi ridicate din "
                "showroom .";
    }
}
