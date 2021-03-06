/*
*
*  These functions will be used to create verilog file
*
*/

#ifndef PRINTER_H
#define PRINTER_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <vector>

#include "wire.h"
#include "nodes.h"

using namespace std;

bool parseFile(string inputFile, string outputFile)
{
  ifstream inFile(inputFile);
  string line;
  vector<wire> inputs;
  vector<wire> outputs;
  vector<wire> wires;
  vector<node> nodes;


  if(inFile.is_open())
  {
	  while ( getline (inFile, line))
	  {
          cout << line << endl;
		  istringstream ss(line);
		  string key;

		  ss >> key;
		  if (key == "input")
		  {
			  string type;
			  bool sign;
			  int size;
			  string name;

			  ss >> type;
			  if (type == "Int1")
			  {
				  sign = true;
				  size = 1;
			  }
			  else if (type == "UInt1")
			  {
				  sign = false;
				  size = 1;
			  }
			  else if (type == "Int2")
			  {
				  sign = true;
				  size = 2;
			  }
			  else if (type == "UInt2")
			  {
				  sign = false;
				  size = 2;
			  }
			  else if (type == "Int8")
			  {
			  	  sign = true;
			  	  size = 8;
			  }
			  else if (type == "UInt8")
			  {
			  	  sign = false;
			  	  size = 8;
			  }
              else if (type == "Int16")
              {
                  sign = true;
                  size = 16;
              }
              else if (type == "UInt16")
              {
                  sign = false;
                  size = 16;
              }
              else if (type == "Int32")
              {
                  sign = true;
                  size = 32;
              }
              else if (type == "UInt32")
              {
                  sign = false;
                  size = 32;
              }
              else if (type == "Int64")
              {
                  sign = true;
                  size = 64;
              }
              else if (type == "UInt64")
              {
                  sign = false;
                  size = 64;
              }

			  while (ss >> name){
				  if(name.find(',') != string::npos) name.pop_back();

				  inputs.push_back(wire(name, size, sign));
			  }
		  }
		  else if (key == "output")
		  {
			  string type;
			  bool sign;
			  int size;
			  string name;

			  ss >> type;
			  if (type == "Int1")
			  {
				  sign = true;
				  size = 1;
			  }
			  else if (type == "UInt1")
			  {
				  sign = false;
				  size = 1;
			  }
			  else if (type == "Int2")
			  {
				  sign = true;
				  size = 2;
			  }
			  else if (type == "UInt2")
			  {
				  sign = false;
				  size = 2;
			  }
			  else if (type == "Int8")
			  {
				  sign = true;
				  size = 8;
			  }
			  else if (type == "UInt8")
			  {
				  sign = false;
				  size = 8;
			  }
			  else if (type == "Int16")
			  {
				  sign = true;
				  size = 16;
			  }
			  else if (type == "UInt16")
			  {
				  sign = false;
				  size = 16;
			  }
              else if (type == "Int32")
              {
                  sign = true;
                  size = 32;
              }
              else if (type == "UInt32")
              {
                  sign = false;
                  size = 32;
              }
              else if (type == "Int64")
              {
                  sign = true;
                  size = 64;
              }
              else if (type == "UInt64")
              {
                  sign = false;
                  size = 64;
              }

			  while (ss >> name){
				  if(name.find(',') != string::npos) name.pop_back();

                  wire wire_out(name,size,sign);
                  Register reg_temp(name,sign);
                  reg_temp.addOutput(wire_out);
                  outputs.push_back(wire_out);
                  nodes.push_back(reg_temp);
			  }
		  }
		  else if (key == "wire")
		  {
			  string type;
			  bool sign;
			  int size;
			  string name;

			  ss >> type;
			  if (type == "Int1")
			  {
				  sign = true;
				  size = 1;
			  }
			  else if (type == "UInt1")
			  {
				  sign = false;
				  size = 1;
			  }
			  else if (type == "Int2")
			  {
				  sign = true;
				  size = 2;
			  }
			  else if (type == "UInt2")
			  {
				  sign = false;
				  size = 2;
			  }
			  else if (type == "Int8")
			  {
				  sign = true;
				  size = 8;
			  }
			  else if (type == "UInt8")
			  {
				  sign = false;
				  size = 8;
			  }
			  else if (type == "Int16")
			  {
				  sign = true;
				  size = 16;
			  }
			  else if (type == "UInt16")
			  {
				  sign = false;
				  size = 16;
			  }
              else if (type == "Int32")
              {
                  sign = true;
                  size = 32;
              }
              else if (type == "UInt32")
              {
                  sign = false;
                  size = 32;
              }
              else if (type == "Int64")
              {
                  sign = true;
                  size = 64;
              }
              else if (type == "UInt64")
              {
                  sign = false;
                  size = 64;
              }

			  while (ss >> name){
				  if(name.find(',') != string::npos) name.pop_back();

				  wires.push_back(wire(name, size, sign));
			  }
		  }
	  }
	  inFile.close();
  }
  else
  {
	  cout << "Error: unable to open input\n";
	  return false;
  }

    cout << "working here" << endl;


  return true;
}

bool printFile(string outFile, vector<wire> &inputs, vector<wire> &outputs, vector<wire> &wires, vector<node> &nodes)
{
	ofstream out;
	out.open(outFile);

	outFile.pop_back();
	out << "module " << outFile << " ( ";
	vector<wire>::iterator it;
	for (it = inputs.begin();it != inputs.end();it++){
		out << it->getName() << ", ";
	}
	for (it = outputs.begin();it!=outputs.end(); it++){
		out << it->getName();
		if(it != outputs.end()) out << ", ";
	}
	out << ");";


	out.close();
	return true;
}

#endif
