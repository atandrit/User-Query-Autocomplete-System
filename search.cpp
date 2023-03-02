#include <iostream>
#include <string>
#include <fstream>
#include "trie.cpp"
#include "node.cpp"

using namespace std;

int main()
{
	system("cls");
	string data;
	fstream dictionary;
	Trie complete_query;

	dictionary.open("dictionary.txt", fstream::in); // read dictionary file into trie tree structure
	if (dictionary.is_open())
	{
		while (dictionary)
		{
			dictionary >> data;
			complete_query.insert(data);
		}
	}
	else
	{
		cout << "error: file did not open." << endl;
		return -1;
	}
	dictionary.close();
	data.clear(); // clear string variable used for file input; string variable will read in user input
	cout << "Enter search query:" << endl;
	getline(cin, data);			   // getline used over std::cin to catch spaces
	complete_query.is_space(data); // checks whether there's a space in user query
	cout << "\nPossible search options are:  " << endl;
	if (complete_query.getSpace() == true) // if a space exists, remove prefix and pass prefix only to search method
	{
		complete_query.remove_prefix(data);
		complete_query.search(complete_query.break_string(data));
	}
	else // if no method exists, pass user's query to search method to auto-complete the query
		complete_query.search(data);
	cout << '\n';
	system("pause");
	return 0;
}
