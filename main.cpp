#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"

using namespace std;

int main()
{
	system("cls");
	Trie trie; // Create an empty trie
	string word;

	// Load words from dictionary file into trie
	ifstream dict_file("dictionary.txt");
	while (getline(dict_file, word))
		trie.insert(word);
	dict_file.close();

	// Prompt user for prefix and suggest completions
	string prefix;
	while (true)
	{
		cout << "\nEnter a prefix (or '0' to quit): ";
		getline(cin, prefix);
		if (prefix == "0")
			break;

		vector<string> completions = trie.findCompletions(prefix);
		if (completions.empty())
			cout << "\nNo words found that match the prefix.\n";
		else
		{
			cout << "\nMatching words:\n";
			for (string &word : completions)
				cout << " ->" << word << endl;
		}
		cout << "\nEnter a word to select it, or continue typing the prefix to refine the search.\n";
	}

	cout << endl;
	system("pause");
	return 0;
}
