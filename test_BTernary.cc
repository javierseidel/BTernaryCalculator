// CSPC 2620
// File : test_BTernary.cc
// This file tests our BTernary class
// Date : 2021-02-21
// Author : Javier Seidel

#include <iostream>
#include <string>
#include "BTernary.h"

using namespace std;

int main()
{

BTernary a, b, c, d, e;

cout << "Enter a Ternary number: ";
a.extract(cin);
cout << "Enter a Ternary number: ";
b.extract(cin);
cout << endl;

c = a.plus(b);
cout << "The sum of ";
a.insert(cout);
cout << " and " ;
b.insert(cout);
cout << " is ";
c.insert(cout);
cout << endl;

d = a.minus(b);
cout << "The difference of ";
a.insert(cout);
cout << " and " ;
b.insert(cout);
cout << " is ";
d.insert(cout);
cout << endl;

e = a.times(b);
cout << "The product of ";
a.insert(cout);
cout << " and " ;
b.insert(cout);
cout << " is ";
e.insert(cout);
cout << endl;

  return 0;
}
