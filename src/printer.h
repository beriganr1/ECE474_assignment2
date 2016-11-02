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

bool printFile(string outFile, vector<wire> &inputs, vector<wire> &outputs, vector<wire> &wires, vector<node*> nodes);

int determineSign(vector<wire> inputs,vector<wire> wires, string input1, string input2)
{
    bool checkedSignWire = 0;
    bool checkedSignInput = 0;
    int wireSign1 = 100;
    int wireSign2 = 200;
    
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
        
        checkedSignInput = 1;
    }
    
    if(checkedSignWire == 1 && checkedSignInput == 1 && wireSign1 == 0 && wireSign2 == 0)
        return 0;
    
    else if(checkedSignWire == 1 && checkedSignInput == 1 && wireSign1 == 1 && wireSign2 == 1)
        return 1;
    
    else
    {
        cout << "Cannot Mix Signs. Circuit Not Valid." << endl;
        return -1;
    }
    
}

wire* searchWire(string wireName, vector<wire> &wires)
{
    
    for (int i = 0 ; i < wires.size();i++)
    {
            
        if(wires.at(i).getName() == wireName)
                return &(wires.at(i));
    }
    
        return NULL;
}

bool parseFile(string inputFile, string outputFile)
{
  ifstream inFile(inputFile);
  string line;
  vector<wire> inputs;
  vector<wire> outputs;
  vector<wire> wires;
  vector<node*> nodes;
  int nodeNum = 0;


  if(inFile.is_open())
  {
	  while ( getline (inFile, line))
	  {

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

                  wire wire_temp(name,size,sign);
                  outputs.push_back(wire_temp);
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
		  else if (key == "register")
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
		  else {
          string output1 = key;
          string equals;
          string input1;

          if(ss.good()){
              ss >> equals;
              ss >> input1;

              if(!ss.good())
              {

            	  wire *inputWire = searchWire(input1,inputs);
            	  if(inputWire == NULL) inputWire = searchWire(input1,wires);

            	  wire *outputWire = searchWire(output1, outputs);
            	  if(outputWire == NULL) outputWire = searchWire(output1,wires);

            	  node *reg = new Register("reg"+nodeNum, false);

            	  reg->addInput(*inputWire);
            	  reg->addOutput(*outputWire);

            	  nodes.push_back(reg);

              }

              else{

                  string input2;
                  string operation;

                  ss >> operation;
                  ss >> input2;

                  if (operation == "+")
                  {
                          string addString = "add" + std:: to_string(nodeNum);
                          Adder *add = new Adder(addString, 0);

                          if(searchWire(input1, wires) != NULL)
                              add->addInput(*searchWire(input1, wires));

                          else if(searchWire(input1, inputs) != NULL)
                              add->addInput(*searchWire(input1, inputs));

                          if(searchWire(input2, wires) != NULL)
                              add->addInput(*searchWire(input2, wires));

                          else if(searchWire(input2, inputs) != NULL)
                              add->addInput(*searchWire(input2, inputs));

                          if(searchWire(output1, wires) != NULL)
                              add->addOutput(*searchWire(output1, wires));

                          else if(searchWire(output1, inputs) != NULL)
                              add->addOutput(*searchWire(output1, outputs));

                          nodes.push_back(add);

                  }

                  else if (operation == "-")
                  {
                          string subString = "sub" + std:: to_string(nodeNum);
                          Subtractor *sub = new Subtractor(subString, 0);

                          if(searchWire(input1, wires) != NULL)
                              sub->addInput(*searchWire(input1, wires));

                          else if(searchWire(input1, inputs) != NULL)
                              sub->addInput(*searchWire(input1, inputs));

                          if(searchWire(input2, wires) != NULL)
                              sub->addInput(*searchWire(input2, wires));

                          else if(searchWire(input2, inputs) != NULL)
                              sub->addInput(*searchWire(input2, inputs));

                          if(searchWire(output1, wires) != NULL)
                              sub->addOutput(*searchWire(output1, wires));

                          else if(searchWire(output1, inputs) != NULL)
                              sub->addOutput(*searchWire(output1, outputs));

                          nodes.push_back(sub);

                  }

                  else if (operation == "*")
                  {
                          string mulString = "mul" + std:: to_string(nodeNum);
                          Multiplier *mul = new Multiplier(mulString, 0);

                          if(searchWire(input1, wires) != NULL)
                              mul->addInput(*searchWire(input1, wires));

                          else if(searchWire(input1, inputs) != NULL)
                              mul->addInput(*searchWire(input1, inputs));

                          if(searchWire(input2, wires) != NULL)
                              mul->addInput(*searchWire(input2, wires));

                          else if(searchWire(input2, inputs) != NULL)
                              mul->addInput(*searchWire(input2, inputs));

                          if(searchWire(output1, wires) != NULL)
                              mul->addOutput(*searchWire(output1, wires));

                          else if(searchWire(output1, inputs) != NULL)
                              mul->addOutput(*searchWire(output1, outputs));

                          nodes.push_back(mul);


                  }

                  else if (operation == "<" || operation == ">" || operation == "==")
                  {
                          string compString = "comp" + std:: to_string(nodeNum);
                          Comparator *comp = new Comparator(compString, 1);

                          if(searchWire(input1, wires) != NULL)
                              comp->addInput(*searchWire(input1, wires));

                          else if(searchWire(input1, inputs) != NULL)
                              comp->addInput(*searchWire(input1, inputs));

                          if(searchWire(input2, wires) != NULL)
                              comp->addInput(*searchWire(input2, wires));

                          else if(searchWire(input2, inputs) != NULL)
                              comp->addInput(*searchWire(input2, inputs));

                          if( operation == ">"){
                        	  comp->addOutput(wire("0",1,false));
                          } else if( operation == "=="){
                        	  comp->addOutput(wire("0",1,false));
                        	  comp->addOutput(wire("0",1,false));
                          }


                          if(searchWire(output1, wires) != NULL)
                              comp->addOutput(*searchWire(output1, wires));

                          else if(searchWire(output1, inputs) != NULL)
                              comp->addOutput(*searchWire(output1, outputs));

                          else if (searchWire(output1,outputs) != NULL)
                        	  comp->addOutput(*searchWire(output1, outputs));

                          if( operation == ">"){
							  comp->addOutput(wire("0",1,false));
							} else if( operation == "<"){
							  comp->addOutput(wire("0",1,false));
							  comp->addOutput(wire("0",1,false));
							}

                          nodes.push_back(comp);

                  }

                  else if (operation == "?")
                  {
                      string input3;
                      ss >> input3;
                      ss >> input3;

                          string muxString = "mux" + std:: to_string(nodeNum);
                          MUX2x1 *mux = new MUX2x1(muxString, 1);

                          wire* wire1 = searchWire(input1,inputs);
                          if(wire1==NULL) wire1 = searchWire(input1,wires);

                          wire* wire2 = searchWire(input2,inputs);
                          if(wire2==NULL) wire2 = searchWire(input2,wires);

                          wire* wire3 = searchWire(input3,inputs);
                          if(wire3==NULL) wire3 = searchWire(input3,wires);

                          wire* outWire1 = searchWire(output1,outputs);
                          if(outWire1==NULL) outWire1 = searchWire(output1,wires);

                          mux->addInput(*wire1);
                          mux->addInput(*wire2);
                          mux->addInput(*wire3);
                          mux->addOutput(*outWire1);

                          nodes.push_back(mux);

                  }

                  else if (operation == "<<")
                  {
                      if(determineSign(inputs, wires, input1, input2) == 1)
                      {
                          string shlString = "shl" + std:: to_string(nodeNum);
                          ShiftLeft *shl = new ShiftLeft(shlString, 1);

                          if(searchWire(input1, wires) != NULL)
                              shl->addInput(*searchWire(input1, wires));

                          else if(searchWire(input1, inputs) != NULL)
                              shl->addInput(*searchWire(input1, inputs));

                          if(searchWire(input2, wires) != NULL)
                              shl->addInput(*searchWire(input2, wires));

                          else if(searchWire(input2, inputs) != NULL)
                              shl->addInput(*searchWire(input2, inputs));

                          if(searchWire(output1, wires) != NULL)
                              shl->addOutput(*searchWire(output1, wires));

                          else if(searchWire(output1, inputs) != NULL)
                              shl->addOutput(*searchWire(output1, outputs));

                          nodes.push_back(shl);

                      }

                      else if (determineSign(inputs, wires, input1, input2) == 0)
                      {
                          string shlString = "shl" + std:: to_string(nodeNum);
                          ShiftLeft *shl = new ShiftLeft(shlString, 0);

                          if(searchWire(input1, wires) != NULL)
                              shl->addInput(*searchWire(input1, wires));

                          else if(searchWire(input1, inputs) != NULL)
                              shl->addInput(*searchWire(input1, inputs));

                          if(searchWire(input2, wires) != NULL)
                              shl->addInput(*searchWire(input2, wires));

                          else if(searchWire(input2, inputs) != NULL)
                              shl->addInput(*searchWire(input2, inputs));

                          if(searchWire(output1, wires) != NULL)
                              shl->addOutput(*searchWire(output1, wires));

                          else if(searchWire(output1, inputs) != NULL)
                              shl->addOutput(*searchWire(output1, outputs));

                          nodes.push_back(shl);
                      }
                  }

                  else if (operation == ">>")
                  {
                          string shrString = "shr" + std:: to_string(nodeNum);
                          ShiftRight *shr = new ShiftRight(shrString, 1);

                          if(searchWire(input1, wires) != NULL)
                              shr->addInput(*searchWire(input1, wires));

                          else if(searchWire(input1, inputs) != NULL)
                              shr->addInput(*searchWire(input1, inputs));

                          if(searchWire(input2, wires) != NULL)
                              shr->addInput(*searchWire(input2, wires));

                          else if(searchWire(input2, inputs) != NULL)
                              shr->addInput(*searchWire(input2, inputs));

                          if(searchWire(output1, wires) != NULL)
                              shr->addOutput(*searchWire(output1, wires));

                          else if(searchWire(output1, inputs) != NULL)
                              shr->addOutput(*searchWire(output1, outputs));

                          nodes.push_back(shr);

                  }
                  nodeNum++;

              }}
          }
	  }
	  inFile.close();
  }

  else
  {
	  cout << "Error: unable to open input\n";
	  return false;
  }



if (printFile(outputFile,inputs,outputs,wires,nodes)) return true;

  return false;
}

bool printFile(string outFile, vector<wire> &inputs, vector<wire> &outputs, vector<wire> &wires, vector<node*> nodes)
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
	out << ", Clk, Rst);\n";

	out << "\tinput Clk, Rst;\n";

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
