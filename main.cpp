#include <iostream>
#include <fstream>
#include <string.h>
#include "headers/sort.h"
#include "headers/s1.h"
#include "headers/s2.h"
#include "headers/s3.h"
#include "headers/s33.h"
#include "headers/s4.h"
#include "headers/s5.h"
#include "headers/s6.h"
#include "headers/s7.h"
#include "headers/s8.h"
#include "headers/s9.h"
#include "headers/s10.h"
#include "headers/s11.h"
#include "headers/s13.h"
#include "headers/s14.h"
#include "headers/s15.h"
#include "headers/display.h"
#include "headers/welcomeMessage.h"
using namespace std;

int main()
{
	// CPU = Central Processing Unit
	// GPU = Graphics Processing Unit
	// HDD = Hard Disk Drive
	// SSD = Solid State Drive

	int n = 1, op, assembly = 0, actual = 0, ok = 0;
	char ans[3];
	product v[201];

	// Read product catalog from file
	ifstream f("products.in");
	while (f >> v[n].name >> v[n].type >> v[n].manufacturer >> v[n].labor >> v[n].price >> v[n].storeStock >> v[n].supplierStock)
		n++;
	n--;

	welcomeMessage();

	display();

	sort(v, n);

	do
	{
		cout << "Type the number of the operation you want to perform: ";
		cin >> op;
		cout << endl;
		if (op == 1)
			s1(v, n), cout << endl
						   << endl,
				display();
		if (op == 2)
			s2(v, n), cout << endl
						   << endl,
				display();
		if (op == 3)
			s3(v, n), cout << endl
						   << endl,
				display();
		if (op == 33)
			s33(v, n), cout << endl
							<< endl,
				display();
		if (op == 4)
			s4(v, n), cout << endl
						   << endl,
				display();
		if (op == 5)
			s5(v, n), cout << endl
						   << endl,
				display();
		if (op == 6)
			s6(v, n), cout << endl
						   << endl,
				display();
		if (op == 7)
			s7(v, n), cout << endl
						   << endl,
				display();
		if (op == 8)
			s8(v, n), cout << endl
						   << endl,
				display();
		if (op == 9)
			s9(v, n), cout << endl
						   << endl,
				display();
		if (op == 10)
			s10(v, n), cout << endl
							<< endl,
				display();
		if (op == 11)
			s11(v, n), cout << endl
							<< endl,
				display();

		if (op == 13)
			s13(v, n, assembly, actual, ok), cout << endl
												  << endl,
				display();
		if (op == 14)
			s14(assembly, actual, ok), cout << endl
											<< endl,
				display();
		if (op == 15)
			s15(v, n, assembly, actual), cout << endl
											  << endl,
				display();

	} while (op != 0);

	cout << endl
		 << "We appreciate your business. See you soon!";

	return 0;
}
