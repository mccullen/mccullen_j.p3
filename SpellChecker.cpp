#include <string>
#include <algorithm>
#include "SpellChecker.h"
#include <algorithm>
/*Testing!*/

/**
Construct a SpellChecker.
*/
SpellChecker::SpellChecker(std::string lexiconFile)
{
}





// Utility function to find minimum of three numbers
int min2(int x, int y, int z) 
{
	return std::min(std::min(x, y), z);
}

/**
Get the edit distance for two words.

@param firstWord The first word to compare.
@param secondWord The second word to compare.
@return The edit distance between firstWord and secondWord.
*/
int SpellChecker::editDistance(std::string firstWord,
	std::string secondWord)
{
	// Store length of the words.
	const int FIRST_LENGTH = firstWord.length();
	const int SECOND_LENGTH = secondWord.length();

	// Create a table to hold the edit distances of subproblems.
	int editDistanceTable[FIRST_LENGTH+1][SECOND_LENGTH+1];
 
	// Fill editDistanceTable from the bottom up

	// For every character in the firstWord
	for (int i=0; i<=FIRST_LENGTH; i++)
	{
		// For every character in the secondWord
		for (int j=0; j<=SECOND_LENGTH; j++)
		{
			// if firstWord is empty (has length of zero)
			if (i==0)
			{
				// the edit distance is the length of firstWord.
				editDistanceTable[i][j] = j;
			}

			// if the secondWord is empty
			else if (j==0)
			{
				// the edit distance is the length of secondWord.
				editDistanceTable[i][j] = i;
			}

			// if the last characters are the same
			else if (firstWord[i-1] == secondWord[j-1])
			{
				// move on to the next character.
				editDistanceTable[i][j] = editDistanceTable[i-1][j-1];
			}

			// if the last characters are different
			else
			{
				// the edit distance is the minimum of inserting, removing, or replacing.
				editDistanceTable[i][j] = 1 + min2(editDistanceTable[i][j-1],  // Insert
					editDistanceTable[i-1][j],  // Remove
					editDistanceTable[i-1][j-1]); // Replace
			}
		}
	}

	return editDistanceTable[FIRST_LENGTH][SECOND_LENGTH];
}

/**
Determine wheater a word is spelled correctly

@param word The word to determine if it is spelled correctly.
@return True if word is spelled correctly.
*/
bool SpellChecker::spelledCorrectly(std::string word)
{
}

/**
Get a list of suggested words for the word given the edit distance.

@param word The word to make suggestions for.
@param givenEditDistance The edit distance which determines which words
can be contained in the returned list.
@return A list of suggested words.
*/
std::list<std::string> SpellChecker::suggestWords(std::string word, 
	int givenEditDistance)
{
}

/**
Destruct a SpellChecker.
*/
SpellChecker::~SpellChecker()
{
}
