#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

void display()
{
   cout << "Alegeti operatia dorita:" << endl;
   cout << "  1-Afisarea produselor sortate dupa tip si pret" << endl;
   cout << "  2-Afisarea produselor de un anumit tip,sortate dupa pret"
        << endl;
   cout << "  3-Afisarea produselor de la un anumit producator,sortate "
           "dupa pret"
        << endl;
   cout << "  33-Afisarea produselor de un anumit tip si buget" << endl;
   cout << "  4-Afisarea produselor dupa producator si buget" << endl;
   cout << "  5-Sortare dupa pret" << endl;
   cout << "  6-Sortare dupa producator" << endl;
   cout
       << "  7-Modificare stoc(!Accesati doar daca aveti drepturi de "
          "administrator!)"
       << endl;
   cout
       << "  8-Modificare pret(!Accesati doar daca aveti drepturi de "
          "administrator!)"
       << endl;
   cout << "  9-Afisare stoc pentru un anumit product" << endl;
   cout
       << "  10-Inserare produs! Accesati doar daca aveti drepturi de "
          "administrator!"
       << endl;
   cout
       << "  11-Stergere produs!Accesati doar daca aveti drepturi de "
          "administrator!"
       << endl;

   cout
       << "  13-Afisare cost asamblare(daca doriti) si cost total pentru "
          "un sistem introdus"
       << endl;
   cout
       << "  14-Dupa ce ati ales 13,in caz ca aveti un cupon de reducere,"
          "apasati 14 si sa introduceti codul promotional"
       << endl;
   cout << "  15-Lansare comanda" << endl;

   cout << "Pentru inchiderea programului tastati 0." << endl;
   cout
       << "Informatiile legate de produsele dorite se vor afisa sub forma "
          "urmatoare:"
       << endl
       << "Nume-Tip-Producator-Pret asamblare(exceptie sunt perifericele)"
          "-Pret product-Nr. bucati in stoc magazin-Nr. bucati in stoc"
          " furnizor"
       << endl
       << endl;
}
