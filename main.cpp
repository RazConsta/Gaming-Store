#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct produs {
	char nume[50], tip[50], producator[50];
	int manopera, pret, stocmagazin, stocfurnizor;
} v[201];

void sortare(produs v[201], int n) {

	produs aux;
	int i, j, k, l;
	for (i = 1; i < n; i++) {
		j = i;
		while (strcmp(v[j].tip, v[j + 1].tip) == 0)
			j++;
		for (k = i; k < j; k++)
			for (l = k + 1; l <= j; l++)
				if (v[k].pret < v[l].pret) {
					aux = v[k];
					v[k] = v[l];
					v[l] = aux;
				} else if (v[k].pret == v[l].pret)
					if (stricmp(v[k].nume, v[l].nume) > 0) {
						aux = v[k];
						v[k] = v[l];
						v[l] = aux;
					}

		i = j;
	}
}

void s1(produs v[201], int n) {
	sortare(v, n);
	cout << "Acestea sunt produsele din promotia noastra:" << endl;
	for (int i = 1; i <= n; i++) {
		if (stricmp(v[i - 1].tip, v[i].tip) != 0)
			cout << endl;
		cout << v[i].nume << ' ' << v[i].tip << ' ' << v[i].producator << ' '
				<< v[i].manopera << ' ' << v[i].pret << ' ' << v[i].stocmagazin
				<< ' ' << v[i].stocfurnizor << endl;
	}
}

void s2(produs v[201], int n) {
	char s[256];
	cout << "Tipul dorit=";
	cin >> s;
	cout << endl << "Urmatoarele produse corespund cerintelor dumneavoastra:"
			<< endl << endl;
	produs aux, a[201];
	int i, j, nr = 1;

	for (i = 1; i <= n; i++)
		if (strcmp(s, v[i].tip) == 0)
			a[nr] = v[i], nr++;
	nr--;

	for (i = 1; i < nr; i++)
		for (j = i + 1; j <= nr; j++)
			if (a[i].pret < a[j].pret) {
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			} else if (v[i].pret == v[j].pret)
				if (stricmp(v[i].nume, v[j].nume) > 0) {
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}

	for (i = 1; i <= nr; i++)
		cout << a[i].nume << ' ' << a[i].tip << ' ' << a[i].producator << ' '
				<< a[i].manopera << ' ' << a[i].pret << ' ' << a[i].stocmagazin
				<< ' ' << a[i].stocfurnizor << endl;

}

void s3(produs v[201], int n) {
	char s[256];
	cout << "Producatorul dorit=";
	cin >> s;
	cout << endl << "Urmatoarele produse corespund cerintelor dumneavoastra:"
			<< endl << endl;
	produs aux, a[201];
	int i, j, nr = 1;

	for (i = 1; i <= n; i++)
		if (strcmp(s, v[i].producator) == 0)
			a[nr] = v[i], nr++;
	nr--;

	for (i = 1; i < nr; i++)
		for (j = i + 1; j <= nr; j++)
			if (a[i].pret < a[j].pret) {
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			} else if (v[i].pret == v[j].pret)
				if (stricmp(v[i].nume, v[j].nume) > 0) {
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}

	for (i = 1; i <= nr; i++)
		cout << a[i].nume << ' ' << a[i].tip << ' ' << a[i].producator << ' '
				<< a[i].manopera << ' ' << a[i].pret << ' ' << a[i].stocmagazin
				<< ' ' << a[i].stocfurnizor << endl;
}

void s33(produs v[201], int n) {
	produs aux, a[201];
	char s[256];
	cout << "Tipul dorit=";
	cin >> s;
	int x, y;
	cout << "Buget minim=";
	cin >> x;
	cout << "Bugetul maxim=";
	cin >> y;
	cout << endl << "Urmatoarele produse corespund cerintelor dumneavoastra:"
			<< endl << endl;

	int i, j, nr = 1;
	for (i = 1; i <= n; i++)
		if (strcmp(s, v[i].tip) == 0 && x <= v[i].pret && v[i].pret <= y)
			a[nr] = v[i], nr++;
	nr--;

	for (i = 1; i < nr; i++)
		for (j = i + 1; j <= nr; j++)
			if (a[i].pret < a[j].pret) {
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			} else if (v[i].pret == v[j].pret)
				if (stricmp(v[i].nume, v[j].nume) >= 0) {
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}

	for (i = 1; i <= nr; i++)
		cout << a[i].nume << ' ' << a[i].tip << ' ' << a[i].producator << ' '
				<< a[i].manopera << ' ' << a[i].pret << ' ' << a[i].stocmagazin
				<< ' ' << a[i].stocfurnizor << endl;

}

void s4(produs v[201], int n) {
	char s[256];
	produs a[201], aux;
	cout << "Producatorul produsului cautat=";
	cin >> s;
	int valmin, valmax, nr = 1;
	cout << "Bugetul minim=";
	cin >> valmin;
	cout << "Bugetul maxim=";
	cin >> valmax;
	cout << endl << "Urmatoarele produse corespund cerintelor dumneavoastra:"
			<< endl << endl;

	for (int i = 1; i <= n; i++)
		if (valmin <= v[i].pret && valmax >= v[i].pret
				&& strcmp(s, v[i].producator) == 0)
			a[nr] = v[i], nr++;
	nr--;

	for (int i = 1; i < nr; i++)
		for (int j = i + 1; j <= nr; j++)
			if (a[i].pret < a[j].pret)
				aux = a[i], a[i] = a[j], a[j] = aux;
			else if (v[i].pret == v[j].pret)
				if (stricmp(v[i].nume, v[j].nume) >= 0) {
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}

	for (int i = 1; i <= nr; i++)
		cout << a[i].nume << ' ' << a[i].tip << ' ' << a[i].producator << ' '
				<< a[i].manopera << ' ' << a[i].pret << ' ' << a[i].stocmagazin
				<< ' ' << a[i].stocfurnizor << endl;
}

void s5(produs v[201], int n) {
	produs aux, a[201];
	for (int i = 1; i <= n; i++)
		a[i] = v[i];

	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i].pret < a[j].pret) {
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}

	cout << "Acestea sunt produsele din promotia noastra,sortate descrescator"
			" dupa pret" << endl << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i].nume << ' ' << a[i].tip << ' ' << a[i].producator << ' '
				<< a[i].manopera << ' ' << a[i].pret << ' ' << a[i].stocmagazin
				<< ' ' << a[i].stocfurnizor << endl;

}

void s6(produs v[201], int n) {
	produs aux, a[201], b[201];
	//a=copie structura initiala
	//b=structura temporara
	//prod=matrice cu nume producatori
	char prod[20][20], auxx[20];
	int i = 1, j = 1, k = 1, l = 1, m = 1, z = 1;
	for (i = 1; i <= n; i++)
		a[i] = v[i];

	for (i = 1; i <= n; i++) {
		char numep[20];
		int ok = 1;
		strcpy(numep, a[i].producator);
		for (j = 1; j <= 19; j++)
			if (stricmp(prod[j], numep) == 0)
				ok = 0;
		if (ok)
			strcpy(prod[k], numep), k++;
	}
	k--;
	for (i = 1; i < k; i++)
		for (j = i + 1; j <= k; j++)
			if (stricmp(prod[i], prod[j]) > 0) {
				strcpy(auxx, prod[i]);
				strcpy(prod[i], prod[j]);
				strcpy(prod[j], auxx);
			}

	cout << "Acestea sunt produsele din promotia noastra,sortate alfabetic "
			"dupa producator:" << endl << endl;

	for (i = 1; i <= k; i++) {
		int nr = 1;
		for (j = 1; j <= n; j++)
			if (stricmp(prod[i], a[j].producator) == 0)
				b[nr] = a[j], nr++;
		nr--;

		for (m = 1; m < nr; m++)
			for (z = m + 1; z <= nr; z++)
				if (b[m].pret < b[z].pret)
					aux = b[m], b[m] = b[z], b[z] = aux;
				else if (b[m].pret == b[z].pret)
					if (stricmp(b[m].nume, b[z].nume) >= 0) {
						aux = b[m];
						b[m] = b[z];
						b[z] = aux;
					}

		for (l = 1; l <= nr; l++)
			cout << b[l].nume << ' ' << b[l].tip << ' ' << b[l].producator
					<< ' ' << b[l].manopera << ' ' << b[l].pret << ' '
					<< b[l].stocmagazin << ' ' << b[l].stocfurnizor << endl;

		cout << endl;

	}
}

void s7(produs v[201], int n) {

	char numeprodus[256];
	int stoc1, stoc2;
	cout << "Intrebare de securitate:de unde a aparut numele companiei? ";
	char raspuns[256];
	cin.get();
	cin.get(raspuns, 256);
	cout << endl;
	if (strcmp(raspuns, "RAZvan alEX") == 0) {
		cout << "Introduceti numele produsului ";
		cin >> numeprodus;
		cout << endl;
		cout << "Introduceti valorile noi ale stocului din magazin si "
				"stocului furnizor ";
		cin >> stoc1 >> stoc2;
		cout << endl << "Stocul a fost actualizat.";

		for (int i = 1; i <= n; i++)
			if (strcmp(v[i].nume, numeprodus) == 0) {
				v[i].stocmagazin = stoc1;
				v[i].stocfurnizor = stoc2;
			}
	} else
		cout << "Raspuns gresit.Echipa administrativa a fost alertata de "
				"aceasta bresa de securitate.";
}

void s8(produs v[201], int n) {
	char numeprodus[256];
	cout << "Intrebare de securitate:de unde a aparut numele companiei? ";
	char raspuns[256];
	cin.get();
	cin.get(raspuns, 256);
	cout << endl;
	if (strcmp(raspuns, "RAZvan alEX") == 0) {
		cout << "Introduceti numele produsului ";
		cin >> numeprodus;
		int pretnou;
		cout << endl << "Introduceti noul pret al produsului ";
		cin >> pretnou;

		for (int i = 1; i <= n; i++)
			if (strcmp(v[i].nume, numeprodus) == 0)
				v[i].pret = pretnou;

		cout << endl << "Pretul a fost actualizat.";
	} else
		cout << "Raspuns gresit.Echipa administrativa a fost alertata de "
				"aceasta bresa de securitate.";
}

void s9(produs v[201], int n) {
	char numeprodus[256];
	cout << "Nume produs= ";
	cin >> numeprodus;
	cout << endl;
	for (int i = 1; i <= n; i++) {
		if (strcmp(numeprodus, v[i].nume) == 0)
			cout << "Bucati in stoc magazin=" << v[i].stocmagazin
					<< " Bucati in stoc furnizor=" << v[i].stocfurnizor;
	}
}

void s10(produs v[201], int &n) {
	produs aux, a;
	cout << "Intrebare de securitate:de unde a aparut numele companiei? ";
	char raspuns[256];
	cin.get();
	cin.get(raspuns, 256);
	cout << endl;
	if (strcmp(raspuns, "RAZvan alEX") == 0) {
		cout << "Introduceti informatiile legate de noul produs sub forma "
					"urmatoare:Nume-Tip-Producator-Pret asamblare(exceptie "
					"sunt perifericele)-Pret produs-Nr. bucati in stoc "
					"magazin-Nr. bucati in stoc furnizor" << endl;
		cin >> aux.nume >> aux.tip >> aux.producator >> aux.manopera >> aux.pret
				>> aux.stocmagazin >> aux.stocfurnizor;

		n++;

		for (int i = 1; i < n; i++)
			if (((strcmp(v[i].tip, aux.tip) == 0)
					&& (strcmp(v[i + 1].tip, aux.tip) != 0))
					|| ((i == n - 1) && (strcmp(v[i].tip, aux.tip)))) {
				i++;

				for (int j = n; j > i; j--) {
					a = v[j];
					v[j] = v[j - 1];
					v[j - 1] = a;
				}
				v[i] = aux;
				break;
			}
		sortare(v, n);
		cout << "Produsul a fost introduc in oferta Razex Custom PCs";
	} else
		cout<< "Raspuns gresit.Echipei administrative a fost alertata de "
				"aceasta bresa de securitate.";
}

void s11(produs v[201], int &n) {
	char numeprodus[256];
	cout << "Intrebare de securitate:de unde a aparut numele companiei? ";
	char raspuns[256];
	cin.get();
	cin.get(raspuns, 256);
	cout << endl;
	if (strcmp(raspuns, "RAZvan alEX") == 0) {
		cout << "Produsul care urmeaza a fi sters= ";
		cin >> numeprodus;
		int poz = 0, i;

		for (i = 1; i <= n; i++)
			if (strcmp(numeprodus, v[i].nume) == 0)
				poz = i;

		for (i = poz; i < n; i++)
			v[i] = v[i + 1];
		n--;

		cout << endl << "Produsul a fost sters";
	} else
		cout << "Raspunsul este gresit.Echipa administrativa a fost "
			    "alertata de aceasta bresa de securitate.";
}

void s13(produs v[201], int n, int &asamblare, int &efectiv, int &ok) {
	char numeprodus[256];
	asamblare = efectiv = ok = 0;
	cout << "Pentru calcularea valorii totale a unei comenzi,introduceti "
				"produsele dorite.Dupa ce ati introdus toate produsele dorite,"
				"tastati <Terminat>" << endl;
	do {
		cin >> numeprodus;
		for (int i = 1; i <= n; i++)
			if (strcmp(numeprodus, v[i].nume) == 0)
				asamblare = asamblare + v[i].manopera, efectiv = efectiv
						+ v[i].pret;
	} while (strcmp(numeprodus, "Terminat") != 0);

	if (asamblare) {
		cout << "Doriti si montarea componentelor?" << endl;
		char ans[3];
		cin.get();
		cin.get(ans, 3);
		if (strcmp(ans, "Da") == 0) {
			cout << "Cost asamblare=" << asamblare << " ";
			ok = 1;
		}
	}
	cout << "Cost efectiv=" << efectiv;

}

void s14(int asamblare, int efectiv, int ok) {
	char cod1[256], cod2[256];
	strcpy(cod1, "La multi ani!");
	strcpy(cod2, "2017");
	char cod[256];
	cin.get();
	cout << "Cod promotional= ";
	cin.get(cod, 256);
	if (strcmp(cod, cod1) == 0) {
		cout << "Preturi dupa aplicarea cuponului de 10%:" << endl;
		if (ok)
			if (asamblare)
				cout << "Cost asamblare=" << asamblare - asamblare / 10 << " ";

		cout << "Cost efectiv=" << efectiv - efectiv / 10;
	} else

	if (strcmp(cod, cod2) == 0) {
		cout << "Preturi dupa aplicarea cuponului de 5%:" << endl;
		if (ok)
			if (asamblare)
				cout << "Cost asamblare=" << asamblare - asamblare / 20 << " ";

		cout << "Cost efectiv=" << efectiv - efectiv / 20;

	} else
		cout << "Codul introdus nu este corect.";

}

void s15(produs v[201], int n, int &asamblare, int &efectiv) {

	char numeprodus[256], ans[3];
	int verif = 1;
	asamblare = efectiv = 0;
	cout << "Pentru lansarea comenzii,introduceti produsele dorite.Dupa ce "
			"ati introdus toate produsele dorite,tastati <Terminat>" << endl;
	do {
		cin >> numeprodus;
		for (int i = 1; i <= n; i++)
			if (strcmp(numeprodus, v[i].nume) == 0) {
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
	if (strcmp(cod, cod1) == 0) {
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
		if (strcmp(var, "b") == 0) {
			if (verif == 1) {
				cout << "Introduceti adresa de livrare: ";
				char adresa[256];
				cin.get();
				cin.get(adresa, 256);
				cout << "Va multumim pentru comanda.Livrarea se va efectua "
						"in maxim 2 zile lucratoare.";
			}

			else if (verif == 2) {
				cout << "Introduceti adresa de livrare: ";
				char adresa[256];
				cin.get();
				cin.get(adresa, 256);
				cout << "Va multumim pentru comanda.Livrarea se va efectua "
						"in maxim 5 zile lucratoare.";
			}
		} else if (strcmp(var, "a") == 0) {
			if (verif == 1)
				cout << "Va multumim pentru comanda.Produsele pot fi "
						"ridicate din showroom." << endl;
			else if (verif == 2) {
				char nrtel[256], email[256];
				cout << "Alegeti o metoda de contact pentru notificare in "
						"momentul in care produsele ajung in stocul magazinului";
				cout << endl << "  a - apel telfonic" << endl << "  b - email"
						<< endl;
				char alegere[256];
				cin.get();
				cin.get(alegere, 256);
				if (strcmp(alegere, "a") == 0) {
					cout << "Numar telefon= ";
					cin.get();
					cin.get(nrtel, 256);
					cout << "Veti fi contactat cand produsul vine in stocul "
							"magazinului.-maxim 5 zile lucratoare";
				} else if (strcmp(alegere, "b") == 0) {
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

	if (strcmp(cod, cod2) == 0) {
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
		if (strcmp(var, "b") == 0) {
			if (verif == 1) {
				cout << "Introduceti adresa de livrare: ";
				char adresa[256];
				cin.get();
				cin.get(adresa, 256);
				cout << "Va multumim pentru comanda.Livrarea se va efectua in "
						"maxim 2 zile lucratoare.";
			}

			else if (verif == 2) {
				cout << "Introduceti adresa de livrare: ";
				char adresa[256];
				cin.get();
				cin.get(adresa, 256);
				cout << "Va multumim pentru comanda.Livrarea se va efectua "
						"in maxim 5 zile lucratoare.";
			}
		} else if (strcmp(var, "a") == 0) {
			if (verif == 1)
				cout << "Va multumim pentru comanda.Produsele pot fi ridicate"
						" din showroom." << endl;
			else if (verif == 2) {
				char nrtel[256], email[256];
				cout << "Alegeti o metoda de contact pentru notificare in"
						" momentul in care produsele ajung in stocul "
						"magazinului";
				cout << endl << "  a - apel telfonic" << endl << "  b - email"
						<< endl;
				char alegere[256];
				cin.get();
				cin.get(alegere, 256);
				if (strcmp(alegere, "a") == 0) {
					cout << "Numar telefon= ";
					cin.get();
					cin.get(nrtel, 256);
					cout << "Veti fi contactat cand produsul vine in stocul "
							"magazinului.-maxim 5 zile lucratoare";
				} else if (strcmp(alegere, "b") == 0) {
					cout << "email= ";
					cin.get();
					cin.get(email, 256);
					cout << "Veti fi contactat cand produsul vine in stocul "
							"magazinului.-maxim 5 zile lucratoare";
				}
			}
		}
	}

	else {
		cout << "Cost asamblare= " << asamblare << endl;
		cout << "Cost efectiv= " << efectiv << endl;
		cout << "Va multumim pentru comanda .Produsele pot fi ridicate din "
				"showroom .";
	}
}

void afisare() {
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
	cout << "  9-Afisare stoc pentru un anumit produs" << endl;
	cout
			<< "  10-Inserare produs !Accesati doar daca aveti drepturi de "
					"administrator!"
			<< endl;
	cout
			<< "  11-Stergere produs !Accesati doar daca aveti drepturi de "
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
					"-Pret produs-Nr. bucati in stoc magazin-Nr. bucati in stoc"
					" furnizor"
			<< endl << endl;
}

int main() {
	//CPU=procesor
	//GPU=placa video
	//HDD=hard disk
	//SSD=hard disk mai rapid

	//Alex:sortare,1,2,3,33,5,7,8,9,11;
	//Razvan:4,6,10,13,14,15

	int n = 1, op, asamblare = 0, efectiv = 0, ok = 0;
	char ans[3];

	ifstream f("produse.in");
	while (f >> v[n].nume >> v[n].tip >> v[n].producator >> v[n].manopera
			>> v[n].pret >> v[n].stocmagazin >> v[n].stocfurnizor)
		n++;
	n--;

	cout << "                                                   "
			<< "Razex Custom PCs" << endl << endl;
	cout
			<< "*Bine ati venit la Razex Custom PCs,site-ul numarului 1 in "
					"Romania dupa estimarile oficiale ecommerce.com pentru "
					"anul 2016."
			<< endl;
	cout
			<< "*Aici veti gasi cea mai mare varietate de produse IT la "
					"preturi foarte avantajoase."
			<< endl;
	cout << "Adresa:Bulevardul Pipera 1,Bucuresti" << endl
			<< "Numar telefon comenzi:0755 285 969" << endl
			<< "Numar telefon service:0732 493 605" << endl;
	cout << "Program:" << endl << "L-V 9-20" << endl << "S 10-18" << endl
			<< "D 12-14" << endl << endl;
	cout << "Alegeti operatia dorita:" << endl;

	cout << "  1-Afisarea produselor sortate dupa tip si pret" << endl;
	cout << "  2-Afisarea produselor de un anumit tip,sortate dupa pret"
			<< endl;
	cout
			<< "  3-Afisarea produselor de la un anumit producator,sortate"
					" dupa pret"
			<< endl;
	cout << "  33-Afisarea produselor de un anumit tip si buget" << endl;
	cout << "  4-Afisarea produselor dupa producator si buget" << endl;
	cout << "  5-Sortare dupa pret" << endl;
	cout << "  6-Sortare dupa producator" << endl;
	cout
			<< "  7-Modificare stoc !Accesati doar daca aveti drepturi de "
					"administrator!"
			<< endl;
	cout
			<< "  8-Modificare pret !Accesati doar daca aveti drepturi de"
					" administrator!"
			<< endl;
	cout << "  9-Afisare stoc pentru un anumit produs" << endl;
	cout
			<< "  10-Inserare produs !Accesati doar daca aveti drepturi de "
					"administrator!"
			<< endl;
	cout
			<< "  11-Stergere produs !Accesati doar daca aveti drepturi de "
					"administrator!"
			<< endl;
	cout
			<< "  13-Afisare cost asamblare(daca doriti) si cost total "
					"pentru un sistem introdus"
			<< endl;
	cout
			<< "  14-Dupa ce ati ales 13,in caz ca aveti un cupon de "
					"reducere,apasati 14 si sa introduceti codul promotional"
			<< endl;
	cout << "  15-Lansare comanda" << endl;

	cout << "Pentru inchiderea programului tastati 0." << endl;
	cout
			<< "Informatiile legate de produsele dorite se vor afisa sub "
					"forma urmatoare:"
			<< endl
			<< "Nume-Tip-Producator-Pret asamblare(exceptie sunt perifericele)"
					"-Pret produs-Nr. bucati in stoc magazin-Nr. bucati in "
					"stoc furnizor"
			<< endl << endl;

	sortare(v, n);

	do {
		cout << "Introduceti operatia dorita ";
		cin >> op;
		cout << endl;
		if (op == 1)
			s1(v, n), cout << endl << endl, afisare();
		if (op == 2)
			s2(v, n), cout << endl << endl, afisare();
		if (op == 3)
			s3(v, n), cout << endl << endl, afisare();
		if (op == 33)
			s33(v, n), cout << endl << endl, afisare();
		if (op == 4)
			s4(v, n), cout << endl << endl, afisare();
		if (op == 5)
			s5(v, n), cout << endl << endl, afisare();
		if (op == 6)
			s6(v, n), cout << endl << endl, afisare();
		if (op == 7)
			s7(v, n), cout << endl << endl, afisare();
		if (op == 8)
			s8(v, n), cout << endl << endl, afisare();
		if (op == 9)
			s9(v, n), cout << endl << endl, afisare();
		if (op == 10)
			s10(v, n), cout << endl << endl, afisare();
		if (op == 11)
			s11(v, n), cout << endl << endl, afisare();

		if (op == 13)
			s13(v, n, asamblare, efectiv, ok), cout << endl << endl, afisare();
		if (op == 14)
			s14(asamblare, efectiv, ok), cout << endl << endl, afisare();
		if (op == 15)
			s15(v, n, asamblare, efectiv), cout << endl << endl, afisare();

	} while (op != 0);

	cout << endl << "Va multumim pentru vizita.Va mai asteptam!";

	return 0;
}
