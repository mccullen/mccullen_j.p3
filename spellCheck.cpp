/**
Name: Jeff McCullen and Emma Elliott
Date: March 16, 2016
Description:
*/

#include <iostream>
#include <stdlib.h>
#include "SpellChecker.h"

using namespace std;

int main(int argc, char** argv)
{
	const int MAX_CMD_ARGS = 2;
	// If the user did not enter a valid number of command line arguments,
	// print error and exit.
	if (argc <= MAX_CMD_ARGS)
	{

		cerr << "Error: Must have no more than "
		     << MAX_CMD_ARGS << " command line arguments.\n";
		exit(1);
	}

	const int EDIT_DISTANCE_ARG = 1;
	const int DEFAULT_EDIT_DISTANCE = 2;
	int editDistance = DEFAULT_EDIT_DISTANCE;

	// If the user specified the edit distance in the command line,
	// reset the editDistance.
	if (argc == MAX_CMD_ARGS)
	{
		editDistance = atoi(argv[EDIT_DISTANCE_ARG]);
	}

	SpellChecker tester("lexicon.txt");
	cout << tester.editDistance("boat", "boot") << endl;
	
}
