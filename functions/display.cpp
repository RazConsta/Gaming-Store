#include "sort.h"
#include <cstring>
#include <iostream>

using namespace std;

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
