// CSPC 2620
// File : BTernary.cc
// This file impliments functions for the BTernary class
// Date : 2021-02-21
// Author : Javier Seidel




#include <iostream>
#include <string>
#include <cmath>
#include "BTernary.h"

using namespace std;


//BTernary is our default constructor and creates a object when none are specified by the user
BTernary::BTernary()
{
  decimal_equivalent = 0;
}
//This is our other constructor for when parameters are passed in from the user. It will also check if the input is a ternary number or not, and if it is not it will set the decimal equivalent to 0
BTernary::BTernary(const string &a)
{
  if (isTernary(a))
  {
   decimal_equivalent = ternaryToDecimal(a);
  }
  else
  {  cout << "Error. Not a valid Ternary number";
    decimal_equivalent = 0;
  }
}
//Purpose = To check if the input is a ternary number
//Input = any input
//Output = true or false, depending on if the input was a ternary number or not
bool BTernary::isTernary(const string &s) const
{
    for (unsigned int i = 0; i < s.size(); i++)
        if (s[i] != '0' && s[i] != '1' && s[i] != '-')
            return false;

    return true;
}
//Purpose = To convert a decimal number(base 10) into a ternary number(base 3)
//Input = a base 10 number
//Output = a ternary number equivalent to that decimal input number
string BTernary::decimalToTernary(int d) const
{
  string s;
  int trit, temp;
  bool negative;

  temp = abs(static_cast<int>(d));

  negative = false;

  if (d < 0)
    {
      negative = true;
    }
    do
    {
      trit = temp % 3;
      if(trit == 0)
      {
        s = '0' + s;
        temp = temp/3;
      }
      else if(trit == 1)
      {
        if(negative)
        {
          s = "-1" + s;
        }
        else
        {
          s = '1' + s;
        }
        temp = temp/3;
      }
      else if(trit == 2)
      {
        if(negative)
        {
          s = '1' + s;
        }
        else
        {
          s = "-1" + s;
        }
        temp = (temp + 1)/3;
      }
    }
    while(temp > 0);

    return s;

}
//Purpose = To convert a ternary number(base 3) into a decimal number(base 10)
//Input = a ternary number
//Output = a decimal number equivalent to that ternary input number
int BTernary::ternaryToDecimal(const string &s) const
{
  int power, decimalValue;
  unsigned int position;

  int count = 0;
    for(unsigned int i = 0; i < s.size(); i++)
    {
      if (s[i] == '-')
          count++;
    }
  power = s.length()-count-1;

  position = 0;
  decimalValue = 0;
    while (position < s.length())
    {
      if (s[position] == '-')
      {
        decimalValue += -1 * pow(3,power);
        position += 2;
      }
      else if (s[position] == '0')
      {
        decimalValue += 0;
        position++;
      }
      else if (s[position] == '1')
      {
        decimalValue += pow(3,power);
        position++;
      }
      else if (s[position] == '2')
      {
        decimalValue += 2 * pow(3,power);
        position++;
      }
    power--;
    }
  return decimalValue;
}
//Purpose = To add two ternary numbers together
//Input = two ternary numbers
//Output = the two inputs added together
BTernary BTernary::plus(const BTernary &t) const
{
    string bt = decimalToTernary(decimal_equivalent + t.decimal_equivalent);
    return BTernary(bt);
}
//Purpose = To subtract two ternary numbers from eachother
//Input = two ternary numbers
//Output = the two inputs subtracted from eachother'
BTernary BTernary::minus(const BTernary &t) const
{
    string bt = decimalToTernary(decimal_equivalent - t.decimal_equivalent);
    return BTernary(bt);
}
//Purpose = To multiply two ternary numbers together
//Input = two ternary numbers
//Output = the two inputs multiplied together
BTernary BTernary::times(const BTernary &t) const
{
    string bt = decimalToTernary(decimal_equivalent * t.decimal_equivalent);
    return BTernary(bt);
}
//insert(ostream&) displays the number through which it is called onto the computer screen (or other output device).
void BTernary::insert(ostream &out)
{
  string bt = decimalToTernary(decimal_equivalent);
  out << bt;

  return;
}
//extract(ostream&) takes in the number through which it is inputed by the user
void BTernary::extract(istream &in)
{
    string bt = "";
    in >> bt;
    decimal_equivalent = ternaryToDecimal(bt);

    return;
}
