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
	const int MAX_CMD_ARGS = 1;

	// If the user did not enter a valid number of command line arguments,
	// print error and exit.
	if (argc - 1 > MAX_CMD_ARGS)
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
	if (argc - 1 == MAX_CMD_ARGS)
	{
		editDistance = atoi(argv[EDIT_DISTANCE_ARG]);
	}

	SpellChecker spellChecker("lexicon.txt");

	string word;
	string exitWord = "-1";
	do
	{
		// Read in word from console
		//cout << "Enter a word or " << exitWord << " to exit: ";
		cin >> word;

		if (word != exitWord)
		{
			cout << word << endl;
			// if word is spelled correctly, print spelled correctly.
			if (spellChecker.spelledCorrectly(word))
			{
				cout << "Correctly Spelled" << endl;
			}
			// Else the word is not spelled correctly
			else
			{
				// Get a list of suggested word.
				list<string> suggestedWords = 
					spellChecker.suggestWords(word,
					editDistance);

				if (suggestedWords.size() == 0)
				{
					cout << "No suggestions" << endl;
				}
				else
				{
					// Print the suggested words
					for (list<string>::iterator iter = suggestedWords.begin();
						iter != suggestedWords.end(); ++iter)
					{
						cout << *iter << endl;
					}
				}

			}

		}

	} while (word != exitWord);

}
