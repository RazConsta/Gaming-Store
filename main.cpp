#include <iostream>
#include <fstream>
#include <string.h>
#include "sort.h"
#include "s1.h"
#include "s2.h"
#include "s3.h"
#include "s33.h"
#include "s4.h"
#include "s5.h"
#include "s6.h"
#include "s7.h"
#include "s8.h"
#include "s9.h"
#include "s10.h"
#include "s11.h"
#include "s13.h"
#include "s14.h"
#include "s15.h"
#include "afisare.h"
#include "welcomeMessage.h"
using namespace std;

int main()
{
	// CPU = Central Processing Unit
	// GPU = Graphics Processing Unit
	// HDD = Hard Disk Drive
	// SSD = Solid State Drive

	int n = 1, op, asamblare = 0, efectiv = 0, ok = 0;
	char ans[3];
	product v[201];

	// Read produc catalog from file
	ifstream f("products.in");
	while (f >> v[n].nume >> v[n].tip >> v[n].producator >> v[n].manopera >> v[n].pret >> v[n].stocmagazin >> v[n].stocfurnizor)
		n++;
	n--;

	welcomeMessage();

	afisare();

	sort(v, n);

	do
	{
		cout << "Type the number of the operation you want to perform: ";
		cin >> op;
		cout << endl;
		if (op == 1)
			s1(v, n), cout << endl
						   << endl,
				afisare();
		if (op == 2)
			s2(v, n), cout << endl
						   << endl,
				afisare();
		if (op == 3)
			s3(v, n), cout << endl
						   << endl,
				afisare();
		if (op == 33)
			s33(v, n), cout << endl
							<< endl,
				afisare();
		if (op == 4)
			s4(v, n), cout << endl
						   << endl,
				afisare();
		if (op == 5)
			s5(v, n), cout << endl
						   << endl,
				afisare();
		if (op == 6)
			s6(v, n), cout << endl
						   << endl,
				afisare();
		if (op == 7)
			s7(v, n), cout << endl
						   << endl,
				afisare();
		if (op == 8)
			s8(v, n), cout << endl
						   << endl,
				afisare();
		if (op == 9)
			s9(v, n), cout << endl
						   << endl,
				afisare();
		if (op == 10)
			s10(v, n), cout << endl
							<< endl,
				afisare();
		if (op == 11)
			s11(v, n), cout << endl
							<< endl,
				afisare();

		if (op == 13)
			s13(v, n, asamblare, efectiv, ok), cout << endl
													<< endl,
				afisare();
		if (op == 14)
			s14(asamblare, efectiv, ok), cout << endl
											  << endl,
				afisare();
		if (op == 15)
			s15(v, n, asamblare, efectiv), cout << endl
												<< endl,
				afisare();

	} while (op != 0);

	cout << endl
		 << "We appreciate your business. See you soon!";

	return 0;
}
