#include <string>
#include <algorithm>
#include "SpellChecker.h"
/*Testing!*/

/**
Construct a SpellChecker.
*/
SpellChecker::SpellChecker(std::string lexiconFile)
{
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
  // Make temprary constants
  const int firstLength = firstWord.length();
  const int secondLength = secondWord.length();
  // Create a temporary table to store different editdistances
  int edTable[firstLength + 1][secondLength + 1];
  
  // Fill the table
  for (int i=0; i<=firstLength; i++)
  {
    for (int j=0; j<=secondLength; i++)
      {
	// If the first word is empty,
	// Can only insert all of the second word
	if(i==0)
	  edTable[i][j] = j;
	
	// If the second word is empty,
	// Can only insert all of the first word
	if(j==0)
	  edTable[i][j] = i;

	// If the last two characters are the same,
	// Move on to the rest of the string
	else if(firstWord[i-1] == secondWord[j-1])
	  edTable[i][j] = edTable[i-1][j-1];

	// If the last two characters are different,
	// find the min off all the possible changes
	// Insert
	// Remove
	// Replace
	else
	  edTable[i][j] = 1 + std::min(std::min(edTable[i][j-1],
				      edTable[i-1][j]),
				  edTable[i-1][j-1]);
      }
  }

  return edTable[firstLength][secondLength];
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
