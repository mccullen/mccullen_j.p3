#include <string>
#include <algorithm>
#include "SpellChecker.h"
#include <algorithm>
#include <fstream>

#include <map>
using namespace std;

/**
Construct a SpellChecker.
*/
SpellChecker::SpellChecker(std::string filename)
{
	ifstream lexiconFile(filename.c_str());

	// Insert words into BKTree.

	string word;
	while (getline(lexiconFile, word))
	{
		insert(word);
	}


	lexiconFile.close();
}

/**
Insert word into BKTree.

@param word Word to insert into the BKTree.
@return True if the word was inserted (not a duplicate).
*/
bool SpellChecker::insert(const std::string& word)
{
	// Get the edit distance between the word and the one 
	// contained in pNode.
	return insertAux(word, _pRoot);
}


SpellChecker::BKNode::BKNode(std::string word) : Word(word)
{
}

/**
Helper function for insert in order to do recursive call.

@param word Word to insert into th BKTree.
@param pNode The current node.
@return True if the word was inserted (not a duplicate).
*/
bool SpellChecker::insertAux(const std::string& word, BKNode*& pNode)
{
	// Get the edit distance between the word and the one 
	// contained in pNode.
	int editDistance = SpellChecker::editDistance(word, 
		pNode->Word);
	bool retVal = false;
	// If you didn't find the word
	if (editDistance != 0)
	{
		map<size_t, BKNode*>::iterator iter;
		iter = (pNode->EditDistanceToChild).find(editDistance);
		// If the pNode has the editDistance
		if (iter != (pNode->EditDistanceToChild).end())
		{
			// recursively traverse through the tree.
			retVal = insertAux(word, (*iter).second);
		
		}
		// Else, add it to the map.
		else
		{
			(pNode->EditDistanceToChild)[editDistance] = 
				new BKNode(word);
			retVal = true;
		}
	}
	return retVal;
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
	// TODO: delete allocated memory!!
}
