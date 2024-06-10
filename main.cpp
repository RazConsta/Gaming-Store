#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct product
{
	char name[50], type[50], manufacturer[50];
	int labor, price, storeStock, supplierStock;
};

void welcomeMessage()
{
	cout << "Razex Custom PCs" << endl
		 << endl;
	cout << "*Welcome to Razex Custom PCs, the #1 computer parts website according to the official estimates of ecommerce.com for the year 2016."
		 << endl;
	cout << "*Here you will find the largest variety of IT products at very advantageous prices."
		 << endl;
	cout << "Address: Bulevardul Pipera 1, Bucharest" << endl
		 << "Orders - Phone Number: 0755 285 969" << endl
		 << "Service - Phone Number: 0732 493 605" << endl;
	cout << "Working hours:" << endl
		 << "M-F 9-20" << endl
		 << "Sat 10-18" << endl
		 << "Sun 12-14" << endl
		 << endl;
}

void display()
{
	cout << "Choose the desired operation:" << endl;
	cout << "  1-Display products sorted by type and price" << endl;
	cout << "  2-Display products of a certain type, sorted by price" << endl;
	cout << "  3-Display products from a certain manufacturer, sorted by price" << endl;
	cout << "  33-Display products of a certain type and within a budget" << endl;
	cout << "  4-Display products by manufacturer and budget" << endl;
	cout << "  5-Sort by price" << endl;
	cout << "  6-Sort by manufacturer" << endl;
	cout << "  7-Modify stock (Access only if you have administrator rights!)" << endl;
	cout << "  8-Modify price (Access only if you have administrator rights!)" << endl;
	cout << "  9-Display stock for a certain product" << endl;
	cout << "  10-Insert product (Access only if you have administrator rights!)" << endl;
	cout << "  11-Delete product (Access only if you have administrator rights!)" << endl;

	cout << "  13-Display assembly cost (if desired) and total cost for a given system" << endl;
	cout << "  14-If you have chosen 13, if you have a discount coupon, press 14 and enter the promotional code" << endl;
	cout << "  15-Place an order" << endl;

	cout << "To close the program, type 0." << endl;
	cout << "Information related to the desired products will be displayed in the following format:" << endl
		 << "Name-Type-Manufacturer-Assembly cost (except for peripherals)-Product price-Number of units in store stock-Number of units in supplier stock"
		 << endl
		 << endl;
}

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

void s1(product v[], int n)
{
	sort(v, n);
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

void s2(product v[], int n)
{
	char s[256];
	cout << "Desired type=";
	cin >> s;
	cout << endl
		 << "The following products meet your requirements:"
		 << endl
		 << endl;
	product aux, a[201];
	int i, j, nr = 1;

	for (i = 1; i <= n; i++)
		if (strcmp(s, v[i].type) == 0)
			a[nr] = v[i], nr++;
	nr--;

	for (i = 1; i < nr; i++)
		for (j = i + 1; j <= nr; j++)
			if (a[i].price < a[j].price)
			{
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
			else if (v[i].price == v[j].price)
				if (stricmp(v[i].name, v[j].name) > 0)
				{
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}

	for (i = 1; i <= nr; i++)
		cout << a[i].name << ' ' << a[i].type << ' ' << a[i].manufacturer << ' '
			 << a[i].labor << ' ' << a[i].price << ' ' << a[i].storeStock
			 << ' ' << a[i].supplierStock << endl;
}

void s3(product v[], int n)
{
	char s[256];
	cout << "Desired manufacturer=";
	cin >> s;
	cout << endl
		 << "The following products meet your requirements:"
		 << endl
		 << endl;
	product aux, a[201];
	int i, j, nr = 1;

	for (i = 1; i <= n; i++)
		if (strcmp(s, v[i].manufacturer) == 0)
			a[nr] = v[i], nr++;
	nr--;

	for (i = 1; i < nr; i++)
		for (j = i + 1; j <= nr; j++)
			if (a[i].price < a[j].price)
			{
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
			else if (v[i].price == v[j].price)
				if (stricmp(v[i].name, v[j].name) > 0)
				{
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}

	for (i = 1; i <= nr; i++)
		cout << a[i].name << ' ' << a[i].type << ' ' << a[i].manufacturer << ' '
			 << a[i].labor << ' ' << a[i].price << ' ' << a[i].storeStock
			 << ' ' << a[i].supplierStock << endl;
}

void s33(product v[], int n)
{
	product aux, a[201];
	char s[256];
	cout << "Desired type=";
	cin >> s;
	int minBudget, maxBudget;
	cout << "Minimum budget=";
	cin >> minBudget;
	cout << "Maximum budget=";
	cin >> maxBudget;
	cout << endl
		 << "The following products meet your requirements:"
		 << endl
		 << endl;

	int i, j, nr = 1;
	for (i = 1; i <= n; i++)
		if (strcmp(s, v[i].type) == 0 && minBudget <= v[i].price && v[i].price <= maxBudget)
			a[nr] = v[i], nr++;
	nr--;

	for (i = 1; i < nr; i++)
		for (j = i + 1; j <= nr; j++)
			if (a[i].price < a[j].price)
			{
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
			else if (v[i].price == v[j].price)
				if (stricmp(v[i].name, v[j].name) >= 0)
				{
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}

	for (i = 1; i <= nr; i++)
		cout << a[i].name << ' ' << a[i].type << ' ' << a[i].manufacturer << ' '
			 << a[i].labor << ' ' << a[i].price << ' ' << a[i].storeStock
			 << ' ' << a[i].supplierStock << endl;
}

void s4(product v[], int n)
{
	char s[256];
	product a[201], aux;
	cout << "Product manufacturer=";
	cin >> s;
	int minBudget, maxBudget, nr = 1;
	cout << "Minimum budget=";
	cin >> minBudget;
	cout << "Maximum budget=";
	cin >> maxBudget;
	cout << endl
		 << "The following products meet your requirements:"
		 << endl
		 << endl;

	for (int i = 1; i <= n; i++)
		if (minBudget <= v[i].price && maxBudget >= v[i].price && strcmp(s, v[i].manufacturer) == 0)
			a[nr] = v[i], nr++;
	nr--;

	for (int i = 1; i < nr; i++)
		for (int j = i + 1; j <= nr; j++)
			if (a[i].price < a[j].price)
				aux = a[i], a[i] = a[j], a[j] = aux;
			else if (v[i].price == v[j].price)
				if (stricmp(v[i].name, v[j].name) >= 0)
				{
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}

	for (int i = 1; i <= nr; i++)
		cout << a[i].name << ' ' << a[i].type << ' ' << a[i].manufacturer << ' '
			 << a[i].labor << ' ' << a[i].price << ' ' << a[i].storeStock
			 << ' ' << a[i].supplierStock << endl;
}

void s5(product v[], int n)
{
	product aux, a[201];
	for (int i = 1; i <= n; i++)
		a[i] = v[i];

	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i].price < a[j].price)
			{
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}

	cout << "These are the products in our promotion, sorted in descending order by price"
		 << endl
		 << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i].name << ' ' << a[i].type << ' ' << a[i].manufacturer << ' '
			 << a[i].labor << ' ' << a[i].price << ' ' << a[i].storeStock
			 << ' ' << a[i].supplierStock << endl;
}

void s6(product v[], int n)
{
	product aux, a[201], b[201];
	// a=copy of the initial structure
	// b=temporary structure
	// prod=array with manufacturer names
	char prod[20][20], auxx[20];
	int i = 1, j = 1, k = 1, l = 1, m = 1, z = 1;
	for (i = 1; i <= n; i++)
		a[i] = v[i];

	for (i = 1; i <= n; i++)
	{
		char manufacturerName[20];
		int ok = 1;
		strcpy(manufacturerName, a[i].manufacturer);
		for (j = 1; j <= 19; j++)
			if (stricmp(prod[j], manufacturerName) == 0)
				ok = 0;
		if (ok)
			strcpy(prod[k], manufacturerName), k++;
	}
	k--;
	for (i = 1; i < k; i++)
		for (j = i + 1; j <= k; j++)
			if (stricmp(prod[i], prod[j]) > 0)
			{
				strcpy(auxx, prod[i]);
				strcpy(prod[i], prod[j]);
				strcpy(prod[j], auxx);
			}

	cout << "These are the products in our promotion, sorted alphabetically by manufacturer:"
		 << endl
		 << endl;

	for (i = 1; i <= k; i++)
	{
		int nr = 1;
		for (j = 1; j <= n; j++)
			if (stricmp(prod[i], a[j].manufacturer) == 0)
				b[nr] = a[j], nr++;
		nr--;

		for (m = 1; m < nr; m++)
			for (z = m + 1; z <= nr; z++)
				if (b[m].price < b[z].price)
					aux = b[m], b[m] = b[z], b[z] = aux;
				else if (b[m].price == b[z].price)
					if (stricmp(b[m].name, b[z].name) >= 0)
					{
						aux = b[m];
						b[m] = b[z];
						b[z] = aux;
					}

		for (l = 1; l <= nr; l++)
			cout << b[l].name << ' ' << b[l].type << ' ' << b[l].manufacturer
				 << ' ' << b[l].labor << ' ' << b[l].price << ' '
				 << b[l].storeStock << ' ' << b[l].supplierStock << endl;

		cout << endl;
	}
}

void s7(product v[], int n)
{
	char productName[256];
	int storeStock, supplierStock;
	cout << "Security question: where did the company name come from? ";
	char answer[256];
	cin.get();
	cin.get(answer, 256);
	cout << endl;
	if (strcmp(answer, "RAZvan alEX") == 0)
	{
		cout << "Enter the product name ";
		cin >> productName;
		cout << endl;
		cout << "Enter the new values for the store stock and supplier stock ";
		cin >> storeStock >> supplierStock;
		cout << endl
			 << "Stock has been updated.";

		for (int i = 1; i <= n; i++)
			if (strcmp(v[i].name, productName) == 0)
			{
				v[i].storeStock = storeStock;
				v[i].supplierStock = supplierStock;
			}
	}
	else
		cout << "Wrong answer. The administrative team has been alerted of this security breach.";
}

void s8(product v[], int n)
{
	char productName[256];
	cout << "Security question: where did the company name come from? ";
	char answer[256];
	cin.get();
	cin.get(answer, 256);
	cout << endl;
	if (strcmp(answer, "RAZvan alEX") == 0)
	{
		cout << "Enter the product name ";
		cin >> productName;
		int newPrice;
		cout << endl
			 << "Enter the new price of the product ";
		cin >> newPrice;

		for (int i = 1; i <= n; i++)
			if (strcmp(v[i].name, productName) == 0)
				v[i].price = newPrice;

		cout << endl
			 << "The price has been updated.";
	}
	else
		cout << "Wrong answer. The administrative team has been alerted of this security breach.";
}

void s9(product v[], int n)
{
	char productName[256];
	cout << "Product name= ";
	cin >> productName;
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		if (strcmp(productName, v[i].name) == 0)
			cout << "Units in store stock=" << v[i].storeStock
				 << " Units in supplier stock=" << v[i].supplierStock;
	}
}

void s10(product v[], int &n)
{
	product aux, a;
	cout << "Security question: where did the company name come from? ";
	char answer[256];
	cin.get();
	cin.get(answer, 256);
	cout << endl;
	if (strcmp(answer, "RAZvan alEX") == 0)
	{
		cout << "Enter the information about the new product in the following format: "
				"Name-Type-Manufacturer-Assembly cost (except for peripherals)-Product price-Number of units in store stock-Number of units in supplier stock"
			 << endl;
		cin >> aux.name >> aux.type >> aux.manufacturer >> aux.labor >> aux.price >> aux.storeStock >> aux.supplierStock;

		n++;

		for (int i = 1; i < n; i++)
			if (((strcmp(v[i].type, aux.type) == 0) && (strcmp(v[i + 1].type, aux.type) != 0)) || ((i == n - 1) && (strcmp(v[i].type, aux.type))))
			{
				i++;

				for (int j = n; j > i; j--)
				{
					a = v[j];
					v[j] = v[j - 1];
					v[j - 1] = a;
				}
				v[i] = aux;
				break;
			}
		sort(v, n);
		cout << "The product has been added to the Razex Custom PCs offer";
	}
	else
		cout << "Wrong answer. The administrative team has been alerted of this security breach.";
}

void s11(product v[], int &n)
{
	char productName[256];
	cout << "Security question: where did the company name come from? ";
	char answer[256];
	cin.get();
	cin.get(answer, 256);
	cout << endl;
	if (strcmp(answer, "RAZvan alEX") == 0)
	{
		cout << "Product to be deleted= ";
		cin >> productName;
		int position = 0, i;

		for (i = 1; i <= n; i++)
			if (strcmp(productName, v[i].name) == 0)
				position = i;

		for (i = position; i < n; i++)
			v[i] = v[i + 1];
		n--;

		cout << endl
			 << "The product has been deleted";
	}
	else
		cout << "Wrong answer. The administrative team has been alerted of this security breach.";
}

void s13(product v[], int n, int &assemblyCost, int &actualCost, int &ok)
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

void s15(product v[], int n, int &assemblyCost, int &actualCost)
{
	char productName[256], ans[3];
	int verif = 1;
	assemblyCost = actualCost = 0;
	cout << "To place an order, enter the desired products. After entering all the desired products, type <Finished>"
		 << endl;
	do
	{
		cin >> productName;
		for (int i = 1; i <= n; i++)
			if (strcmp(productName, v[i].name) == 0)
			{
				assemblyCost += v[i].labor;
				actualCost += v[i].price;
				if (v[i].storeStock == 0)
				{
					v[i].supplierStock -= 1;
					verif = 2;
				}
				else
				{
					v[i].storeStock -= 1;
				}
			}
	} while (strcmp(productName, "Finished") != 0);

	char code1[256], code2[256];
	strcpy(code1, "Happy Birthday!");
	strcpy(code2, "2017");
	char code[256];
	cin.get();
	cout << "Do you also want the components to be assembled? ";
	cin.get(ans, 3);
	cin.get();
	cout << "If you have a promotional code, please enter it. ";
	cin.get(code, 256);
	if (strcmp(code, code1) == 0)
	{
		cout << "Prices after applying the 10% coupon:" << endl;
		if (strcmp(ans, "Yes") == 0)
			if (assemblyCost)
				cout << "Assembly cost=" << assemblyCost - assemblyCost / 10 << " ";

		cout << "Actual cost=" << actualCost - actualCost / 10;
		cout << endl;
		cout << "Choose a delivery method:" << endl
			 << "  a - pickup from showroom" << endl
			 << "  b - home delivery" << endl;
		char var[256];
		cin.get();
		cin.get(var, 256);
		if (strcmp(var, "b") == 0)
		{
			if (verif == 1)
			{
				cout << "Enter the delivery address: ";
				char address[256];
				cin.get();
				cin.get(address, 256);
				cout << "Thank you for your order. Delivery will be made within a maximum of 2 working days.";
			}
			else if (verif == 2)
			{
				cout << "Enter the delivery address: ";
				char address[256];
				cin.get();
				cin.get(address, 256);
				cout << "Thank you for your order. Delivery will be made within a maximum of 5 working days.";
			}
		}
		else if (strcmp(var, "a") == 0)
		{
			if (verif == 1)
				cout << "Thank you for your order. The products can be picked up from the showroom."
					 << endl;
			else if (verif == 2)
			{
				char phoneNumber[256], email[256];
				cout << "Choose a contact method for notification when the products arrive in the store's stock";
				cout << endl
					 << "  a - phone call" << endl
					 << "  b - email"
					 << endl;
				char choice[256];
				cin.get();
				cin.get(choice, 256);
				if (strcmp(choice, "a") == 0)
				{
					cout << "Phone number= ";
					cin.get();
					cin.get(phoneNumber, 256);
					cout << "You will be contacted when the product arrives in the store's stock - maximum 5 working days.";
				}
				else if (strcmp(choice, "b") == 0)
				{
					cout << "Email= ";
					cin.get();
					cin.get(email, 256);
					cout << "You will be contacted when the product arrives in the store's stock - maximum 5 working days.";
				}
			}
		}
	}
	else if (strcmp(code, code2) == 0)
	{
		cout << "Prices after applying the 5% coupon:" << endl;
		if (strcmp(ans, "Yes") == 0)
			if (assemblyCost)
				cout << "Assembly cost=" << assemblyCost - assemblyCost / 20 << " ";

		cout << "Actual cost=" << actualCost - actualCost / 20;
		cout << endl;
		cout << "Choose a delivery method:" << endl
			 << "  a - pickup from showroom" << endl
			 << "  b - home delivery" << endl;
		char var[256];
		cin.get();
		cin.get(var, 256);
		if (strcmp(var, "b") == 0)
		{
			if (verif == 1)
			{
				cout << "Enter the delivery address: ";
				char address[256];
				cin.get();
				cin.get(address, 256);
				cout << "Thank you for your order. Delivery will be made within a maximum of 2 working days.";
			}
			else if (verif == 2)
			{
				cout << "Enter the delivery address: ";
				char address[256];
				cin.get();
				cin.get(address, 256);
				cout << "Thank you for your order. Delivery will be made within a maximum of 5 working days.";
			}
		}
		else if (strcmp(var, "a") == 0)
		{
			if (verif == 1)
				cout << "Thank you for your order. The products can be picked up from the showroom."
					 << endl;
			else if (verif == 2)
			{
				char phoneNumber[256], email[256];
				cout << "Choose a contact method for notification when the products arrive in the store's stock";
				cout << endl
					 << "  a - phone call" << endl
					 << "  b - email"
					 << endl;
				char choice[256];
				cin.get();
				cin.get(choice, 256);
				if (strcmp(choice, "a") == 0)
				{
					cout << "Phone number= ";
					cin.get();
					cin.get(phoneNumber, 256);
					cout << "You will be contacted when the product arrives in the store's stock - maximum 5 working days.";
				}
				else if (strcmp(choice, "b") == 0)
				{
					cout << "Email= ";
					cin.get();
					cin.get(email, 256);
					cout << "You will be contacted when the product arrives in the store's stock - maximum 5 working days.";
				}
			}
		}
	}
	else
	{
		cout << "Assembly cost= " << assemblyCost << endl;
		cout << "Actual cost= " << actualCost << endl;
		cout << "Thank you for your order. The products can be picked up from the showroom.";
	}
}

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
