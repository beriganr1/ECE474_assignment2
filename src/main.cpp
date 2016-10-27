#include<iostream>

#include "printer.h"

using namespace std;

int main (int argc, char *argv[]){

	if (argc != 3)
	{
		cout << "Error: Usage dpgen <input_file> <output_file>\n\n";
		return -1;
	}

//  if (parseFile(argv[1], argv[2])) return 0;

	 vector<wire> inputs;
	 vector<wire> outputs;
	 vector<wire> wires;
	 vector<node> nodes;

	 // wire (string name, int size, bool sign);
	 wire a("a",8,false);
	 wire b("b",8,false);
	 wire c_reg("c_reg",8,false);
	 wire c("c",8,false);

	 inputs.push_back(a);
	 inputs.push_back(b);
	 wires.push_back(c_reg);
	 outputs.push_back(c);

	 Adder node1("Adder1", false);
	 Register reg1("Reg1",false);

	 //  void addInput(wire newWire);
	 //  void addOutput(wire newWire);
	 node1.addInput(a);
	 node1.addInput(b);
	 node1.addOutput(c_reg);
	 reg1.addInput(c_reg);
	 reg1.addOutput(c);

	 nodes.push_back(node1);
	 nodes.push_back(reg1);


	if (printFile(argv[2], inputs, outputs, wires, nodes)) return 0;

//  return -1;
}
