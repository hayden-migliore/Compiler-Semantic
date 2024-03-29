/* Hayden Migliore
   CMSC 430 6980
   July 26th, 2019
   Symbols.h File to create symbol table*/

template <typename T>
class Symbols
{
public:
	void insert(char* lexeme, T entry);
	bool find(char* lexeme, T& entry);
	bool findDuplicate(char* lexeme, T& entry);
private:
	map<string, T> symbols;
};

template <typename T>
void Symbols<T>::insert(char* lexeme, T entry)
{
	string name(lexeme);
	symbols[name] = entry;
}

template <typename T>
bool Symbols<T>::find(char* lexeme, T& entry)
{
	string name(lexeme);
	typedef typename map<string, T>::iterator Iterator;
	Iterator iterator = symbols.find(name);
	bool found = iterator != symbols.end();
	if (found)
	{
		entry = iterator->second;
	}
	return found;
}

template <typename T>
bool Symbols<T>::findDuplicate(char* lexeme, T& entry)
{
	string name(lexeme);
	typedef typename map<string, T>::iterator Iterator;
	Iterator iterator = symbols.find(name);
	bool found = iterator != symbols.end();
	if (found)
	{
		appendError(GENERAL_SEMANTIC, "Duplicate Variable Found");
		entry = iterator->second;
	}
	return found;
}
