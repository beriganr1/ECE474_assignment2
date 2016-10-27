#include<iostream>

#include "printer.h"

using namespace std;

int main (int argc, char *argv[]){

	if (argc != 3)
	{
		cout << "Error: Usage dpgen <input_file> <output_file>\n\n";
		return -1;
	}

  if (parseFile(argv[1], argv[2])) return 0;

  return -1;
}
