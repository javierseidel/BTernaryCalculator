// CSPC 2620
// File : BTernary.h
// This file is the header file for the BTernary class
// Date : 2021-02-21
// Author : Javier Seidel

#ifndef BTERNARY_H
#define BTERNARY_H


#include <iostream>
#include <string>

using namespace std;

class BTernary
{
private:
  // I make these variables/functions private so that a user cannot manipulate them in any way. If these variables/functions change then the calculator will not work as intended.
  int decimal_equivalent;
  //Purpose = To check if the input is a ternary number
  //Input = any input
  //Output = true or false, depending on if the input was a ternary number or not
  bool isTernary(const string &) const;
  //Purpose = To convert a decimal number(base 10) into a ternary number(base 3)
  //Input = a base 10 number
  //Output = a ternary number equivalent to that decimal input number
  string decimalToTernary(int) const;
  //Purpose = To convert a ternary number(base 3) into a decimal number(base 10)
  //Input = a ternary number
  //Output = a decimal number equivalent to that ternary input number
  int ternaryToDecimal(const string&) const;
public:
  // These functions are public so that the user and the public can use them in order to calculate BTernary numbers

  //BTernary is our default constructor and creates a object when none are specified by the user
  BTernary();
  //This is our other constructor for when parameters are passed in from the user. It will also check if the input is a ternary number or not, and if it is not it will set the decimal equivalent to 0
  BTernary(const string&);
  //Purpose = To add two ternary numbers together
  //Input = two ternary numbers
  //Output = the two inputs added together
  BTernary plus(const BTernary&) const;
  //Purpose = To subtract two ternary numbers from eachother
  //Input = two ternary numbers
  //Output = the two inputs subtracted from eachother'
  BTernary minus(const BTernary&)const;
  //Purpose = To multiply two ternary numbers together
  //Input = two ternary numbers
  //Output = the two inputs multiplied together
  BTernary times(const BTernary&) const;
  //insert(ostream&) displays the number through which it is called onto the computer screen (or other output device).
  void insert(ostream&);
  //extract(ostream&) takes in the number through which it is inputed by the user
  void extract(istream &);
};

#endif
