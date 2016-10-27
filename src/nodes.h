/*
*
*
*/
#ifndef NODES_H
#define NODES_H

#include<iostream>
#include<vector>

#include "wire.h"

using namespace std;

//-------------------------------------------------------------------
/*
* this is a class used to create a base for all modules 
* this way they can be listed in main in one list for output
*/
class node
{
public:
  node ();
  virtual string print()
  {
	return "";
  };
  void addInput(wire newWire);
  void addOutput(wire newWire);
  void printWires();
  int getInputNum();
  int getOutputNum();
    string getName();
protected:
  vector<wire> inputs;
  vector<wire> outputs;
  int sizeOfWires;
  int numOfInputs;
  int numOfOutputs;
  bool sign = false;
    string name;
};

node :: node ()
{
  numOfInputs = 0;
  numOfOutputs = 0;
  sizeOfWires = 0;
}

void
node :: addInput(wire newWire)
{
  if(inputs.size() == numOfInputs)
  {
    return;
  }

  this->inputs.push_back(newWire);

  vector<wire>::iterator it;
  for( it = this->inputs.begin();it != this->inputs.end(); ++it)
  {
    if (it->getSize() > sizeOfWires) sizeOfWires = it->getSize();
  }
}

void
node :: addOutput(wire newWire)
{
  if(outputs.size() == numOfOutputs)
  {
    return;
  }

  this->outputs.push_back(newWire);

  vector<wire>::iterator it;
  for( it = this->outputs.begin();it != this->outputs.end(); ++it)
  {
    if (it->getSize() > sizeOfWires) sizeOfWires = it->getSize();
  }
}

void
node :: printWires()
{
  vector<wire>::iterator it;
  cout << "Inputs: ";
  for( it =this->inputs.begin();it!=this->inputs.end(); ++ it)
  {  
    cout << it->getName() + "\t"; 
  }
  cout << "\nOutputs: ";
  for( it =this->outputs.begin();it!=this->outputs.end(); ++ it)
  {  
    cout << it->getName() + "\t"; 
  }
  cout << "\n";
}

string
node :: getName()
{
    return this->name;
}

//-------------------------------------------------------------------
class Adder : public node
{
public:
  Adder ();
  Adder (string name, bool sign);
  string print();
private:
};

Adder :: Adder ()
{
  this->numOfInputs = 2;
  this->numOfOutputs = 1;
}

Adder :: Adder (string name, bool sign)
{
	this->numOfInputs = 2;
	this->numOfOutputs = 1;
	this->sign = sign;
    this->name = name;
}

string
Adder :: print()
{
  string output = "";
  
  if( this->sign) output = "S";

  output = "ADD #(" + this->sizeOfWires + ") " + this->name + " (" + this->inputs[0].getName() + ", " + this->inputs[1].getName() + ", " + this->outputs[0].getName() + ");\n";

  return output;
}

//-------------------------------------------------------------------
class Subtractor : public node
{
public:
  Subtractor ();
  Subtractor (string name, bool sign);
  string print();
private:
};

Subtractor :: Subtractor ()
{
  this->numOfInputs = 2;
  this->numOfOutputs = 1;
}

Subtractor :: Subtractor (string name, bool sign)
{
	this->numOfInputs = 2;
	this->numOfOutputs = 1;
	this->sign = sign;
    this->name = name;
}

string
Subtractor :: print()
{
  string output = "";

  if( this->sign) output = "S";

  output = "SUB #(" + this->sizeOfWires + ") " + this->name + " (" + this->inputs[0].getName() + ", " + this->inputs[1].getName() + ", " + this->outputs[0].getName() + ");\n";

  return output;
}

//-------------------------------------------------------------------
class Multiplier : public node
{
public:
  Multiplier ();
  Multiplier (string name, bool sign);
  string print();
private:
};

Multiplier :: Multiplier ()
{
  this->numOfInputs = 2;
  this->numOfOutputs = 1;
}

Multiplier :: Multiplier (string name, bool sign )
{
	this->numOfInputs = 2;
	this->numOfOutputs = 1;
	this->sign = sign;
    this->name = name;
}

string
Multiplier :: print()
{
  string output = "";

  if( this->sign) output = "S";

  output += "MUL #(" + this->sizeOfWires + ") " + this->name + " (" + this->inputs[0].getName() + ", " + this->inputs[1].getName() + ", " + this->outputs[0].getName() + ");\n";

  return output;
}

//--------------------------------------------------------------------------------------------------------------

class Register: public node
{
public:
    Register ();
    Register (string name, bool sign);
    string print();
private:
};

Register :: Register ()
{
    this->numOfInputs = 3;
    this->numOfOutputs = 1;
    
}

Register :: Register (string name, bool sign)
{
    this->numOfInputs = 3;
    this->numOfOutputs = 1;
    this->sign = sign;
    this->name = name;
}

string
Register :: print()
{
    string output = "";
    
    if( this->sign) output = "S";
    
    output = "REG #(" + this->sizeOfWires + ") " + this->name + " (" + this->inputs[0].getName() + ", " + ".Clk(Clk)" + ", " + ".Rst(Rst)" + ", " + this->inputs[0].getName() + ");\n";
    
    return output;
}

//--------------------------------------------------------------------------------------------------------------

class Comparator : public node
{
public:
    Comparator ();
    Comparator (string name, bool sign);
    string print();
private:
};

Comparator :: Comparator ()
{
    this->numOfInputs = 2;
    this->numOfOutputs = 3;
}

Comparator :: Comparator (string name, bool sign)
{
    this->numOfInputs = 2;
    this->numOfOutputs = 3;
    this->sign = sign;
    this->name = name;
}

string
Comparator :: print()
{
    string output = "";
    
    if( this->sign) output = "S";
    
    output = "COMP #(" + this->sizeOfWires + ") " + this->name + " (" + this->inputs[0].getName() + ", " + this->inputs[1].getName() + ", " + this->outputs[0].getName() + ", " + this->outputs[1].getName() + ", " + this->outputs[2].getName() + ");\n";
    
    return output;
}

//--------------------------------------------------------------------------------------------------------------

class ShiftLeft : public node
{
public:
    ShiftLeft ();
    ShiftLeft (string name, bool sign);
    string print();
private:
};

ShiftLeft :: ShiftLeft ()
{
    this->numOfInputs = 3;
    this->numOfOutputs = 1;
}

ShiftLeft :: ShiftLeft (string name, bool sign)
{
    this->numOfInputs = 3;
    this->numOfOutputs = 1;
    this->sign = sign;
    this->name = name;
}

string
ShiftLeft :: print()
{
    string output = "";
    
    if( this->sign) output = "S";
    
    output = "SHL #(" + this->sizeOfWires + ") " + this->name + " (" + this->inputs[0].getName() + ", " + this->inputs[1].getName() + ", " + this->outputs[0].getName() + ");\n";
    
    return output;
}

//--------------------------------------------------------------------------------------------------------------

class ShiftRight : public node
{
public:
    ShiftRight ();
    ShiftRight (string name, bool sign);
    string print();
private:
};

ShiftRight :: ShiftRight ()
{
    this->numOfInputs = 3;
    this->numOfOutputs = 1;
}

ShiftRight :: ShiftRight (string name, bool sign)
{
    this->numOfInputs = 3;
    this->numOfOutputs = 1;
    this->sign = sign;
    this->name = name;
}

string
ShiftRight :: print()
{
    string output = "";
    
    if( this->sign) output = "S";
    
    output = "SHR #(" + this->sizeOfWires + ") " + this->name + " (" + this->inputs[0].getName() + ", " + this->inputs[1].getName() + ", " + this->outputs[0].getName() + ");\n";
    
    return output;
}

//--------------------------------------------------------------------------------------------------------------

class MUX2x1 : public node
{
public:
    MUX2x1 ();
    MUX2x1 (string name, bool sign);
    string print();
private:
};

MUX2x1 :: MUX2x1 ()
{
    this->numOfInputs = 3;
    this->numOfOutputs = 1;
}

MUX2x1 :: MUX2x1 (string name, bool sign)
{
    this->numOfInputs = 3;
    this->numOfOutputs = 1;
    this->sign = sign;
    this->name = name;
}

string
MUX2x1 :: print()
{
    string output = "";
    
    if( this->sign) output = "S";
    
    output = "MUX2x1 #(" + this->sizeOfWires + ") " + this->name + " (" + this->inputs[0].getName() + ", " + this->inputs[1].getName() + ", " + this->outputs[0].getName() + ");\n";
    
    return output;
}

#endif


