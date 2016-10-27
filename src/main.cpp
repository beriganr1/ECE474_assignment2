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
	 inputs.push_back(a);
	 inputs.push_back(wire("b",8,false));
	 wires.push_back(wire("c_reg",8,false));
	 outputs.push_back(wire("c",8,false));


	if (printFile(argv[2], inputs, outputs, wires, nodes)) return 0;

//  return -1;
}
