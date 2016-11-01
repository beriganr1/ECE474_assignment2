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
  ofstream out;
  ifstream inFile(inputFile);
  string line;
  vector<wire> inputs;
  vector<wire> outputs;
  vector<wire> wires;
  vector<node> nodes;
  int nodeNum = 0;

  out.open(outputFile);

  if(inFile.is_open())
  {
	  while ( getline (inFile, line))
	  {
            //cout << line << endl;

		  istringstream ss(line);

		  string key;

          //cout << key << endl;

          ss >> key;


		  if (key == "input")
		  {
              cout << key << endl;
			  string type;
			  bool sign;
			  int size;
			  string name;

              ss >> type;

              cout << type << endl;

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

                  wire wire_temp(name,size,sign);
                  Register reg_temp(name,sign);
                  outputs.push_back(wire_temp);
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
          //cout << line << endl;

          string output1 = key;
          string equals;
          string input1;

          if(ss.good()){
              ss >> equals;
              ss >> input1;

              if(!ss.good())
              {
                  cout << output1 + " = " << endl;
              // create register
              }

              else{

                  string input2;
                  string operation;

                  ss >> operation;
                  ss >> input2;

                  if (operation == "+")
                  {
                      bool checkedSignWire = 0;
                      bool checkedSignInput = 0;
                      bool wireSign1 = 0;
                      bool wireSign2 = 0;
                      bool wireSign3 = 0;
                      bool wireSign4 = 0;

                      for(std::vector<wire> ::iterator it = wires.begin(); it != wires.end(); ++it)
                      {

                          if(it->getName() == input1)
                          {
                              wireSign1 = it->getSign();
                          }

                          if(it->getName() == input2)
                          {
                              wireSign2 = it->getSign();
                          }

                          checkedSignWire = 1;
                      }

                      for(std::vector<wire> ::iterator it = inputs.begin(); it != inputs.end(); ++it)
                      {

                          if(it->getName() == input1)
                          {
                              wireSign1 = it->getSign();
                          }

                          if(it->getName() == input2)
                          {
                              wireSign2 = it->getSign();
                          }
                          checkedSignWire = 1;
                      }


                      if(checkedSignWire == 1 && wireSign1 == wireSign2)
                      {
                          string addString = "add" + std:: to_string(nodeNum);
                          Adder add(addString, wireSign1);
                          nodes.push_back(add);

                      }

                      else if(checkedSignInput == 1 && wireSign3 == wireSign4)
                      {
                          string addString = "add" + std:: to_string(nodeNum);
                          Adder add(addString, wireSign1);
                          nodes.push_back(add);
                      }

                      cout << output1 + " = " + input1 + " + " + input2 << endl;
                  }

                  else if (operation == "-")
                  {
                      cout << output1 + " = " + input1 + " - " + input2 << endl;

                  }

                  else if (operation == "*")
                  {
                      cout << output1 + " = " + input1 + " * " + input2 << endl;

                  }

                  else if (operation == "<" || operation == ">" || operation == "==")
                  {
                      cout << output1 + " = " + input1 + " == " + input2 << endl;

                  }

                  else if (operation == "?")
                  {
                      string input3;
                      ss >> input3;
                      ss >> input3;
                      cout << output1 + " = " + input1 + " ? " + input2 + " : " + input3 << endl;

                  }

                  else if (operation == "<<")
                  {
                      cout << output1 + " = " + input1 + " << " + input2 << endl;
                  }

                  else if (operation == ">>")
                  {
                      cout << output1 + " = " + input1 + " >> " + input2 << endl;
                  }

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

   // cout << "working here" << endl;

  cout << "inputs : " << "\n";
  for(vector<wire>::iterator it = inputs.begin(); it != inputs.end(); it++)
  {
	  cout << it->getName() << " "<< it->getSize() << " " << it->getSign() << "\n";
  }
  cout << "outputs : \n";
  for(vector<wire>::iterator it = outputs.begin(); it != outputs.end(); it++)
  {
    cout << it->getName() << " " << it->getSize() << " " << it->getSign() << "\n";
  }
  cout << "wires : \n";
    for(vector<wire>::iterator it = wires.begin(); it != wires.end(); it++)
    {
      cout << it->getName() << " " << it->getSize() << " " << it->getSign() << "\n";
    }


  out.close();

  return true;
}

bool printFile(string outFile, vector<wire> &inputs, vector<wire> &outputs, vector<wire> &wires, vector<node*> &nodes)
{
	ofstream out;
	out.open(outFile);

	outFile.pop_back();
	outFile.pop_back();

	out << "module " << outFile << " ( ";

	vector<wire>::iterator wireIt;
	vector<node>::iterator nodeIt;

	for (wireIt = inputs.begin();wireIt != inputs.end();wireIt++){
		out << wireIt->getName() << ", ";
	}
	for (wireIt = outputs.begin();wireIt!=outputs.end(); wireIt++){
		out << wireIt->getName();
		if(wireIt != --outputs.end()) out << ", ";
	}
	out << ");\n";

	for (wireIt = inputs.begin();wireIt!=inputs.end();wireIt++){
		out << "\tinput ";

		if(wireIt->getSign()) out << "signed ";

		if(wireIt->getSize() != 1) out << "[" << wireIt->getSize()-1 << ":0] ";

		out << wireIt->getName() << ";\n";
	}

	out << "\n";

	for (wireIt = outputs.begin();wireIt!=outputs.end();wireIt++){
		out << "\toutput ";

		if(wireIt->getSign()) out << "signed ";

		if(wireIt->getSize() != 1) out << "[" << wireIt->getSize()-1 << ":0] ";

		out << wireIt->getName() << ";\n";
	}

	out << "\n";

	for (wireIt = wires.begin();wireIt!=wires.end();wireIt++){
			out << "\twire ";

			if(wireIt->getSign()) out << "signed ";

			if(wireIt->getSize() != 1) out << "[" << wireIt->getSize()-1 << ":0] ";

			out << wireIt->getName() << ";\n";
	}

	out << "\n";

	for (int i = 0;i< nodes.size();i++){
		out << "\t" << nodes.at(i)->print() << endl;
	}

	out << "\nendmodule";
	out.close();
	return true;
}

#endif
