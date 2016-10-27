/*
*
*
*/

#ifndef WIRE_H
#define WIRE_H

#include<iostream>
#include<string>

using namespace std;

/*
*
* this class is used to store wires, their name and their size for creation in verilog and name use in the modules
*
*/
class wire
{
public:
  wire ();
  wire (string name, int size, bool sign);
  string getName ();
  void setName (string name);
  void setSize(int size);
  int getSize();
  string verilogCreate ();
  bool getSign();
private:
  bool sign = false;
  string name;
  int size;
};

wire::wire()
{
  name = string();
  size = 0;
}

wire :: wire (string name, int size, bool sign)
{
  this -> name = string(name);
  this -> size = size;
  this -> sign = sign;
}

string
wire :: getName()
{
  return this->name;
}

void
wire :: setName(string name)
{
  this->name = name;
}

void
wire :: setSize(int size)
{
  this->size = size;
}

int
wire :: getSize()
{
  return this->size;
}

bool
wire :: getSign()
{
  return this -> sign;
}

#endif
