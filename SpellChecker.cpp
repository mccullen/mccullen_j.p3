#include <string>
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
int SpellChecker::editDistance(std::string str1,
	std::string str2)
{
	const int m = str1.length();
	const int n = str2.length();

	// Create a table to store results of subproblems
	int dp[m+1][n+1];
 
	// Fill d[][] in bottom up manner
	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=n; j++)
		{
			// If first string is empty, only option is to
			// isnert all characters of second string
			if (i==0)
				dp[i][j] = j;  // Min. operations = j

			// If second string is empty, only option is to
			// remove all characters of second string
			else if (j==0)
				dp[i][j] = i; // Min. operations = i

			// If last characters are same, ignore last char
			// and recur for remaining string
			else if (str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1];

			// If last character are different, consider all
			// possibilities and find minimum
			else
				dp[i][j] = 1 + min2(dp[i][j-1],  // Insert
					dp[i-1][j],  // Remove
					dp[i-1][j-1]); // Replace
		}
	}

	return dp[m][n];
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
