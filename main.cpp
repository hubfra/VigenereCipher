
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	char alphabetS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int alphabetV[91];

	for (int a = 0; a < 36; a++)
		alphabetV[alphabetS[a]] = a;

	string key;
	ifstream input("input.txt");
	ofstream output("output.txt");
	char action = '1';

	cout << "Encryption - 1\nDecryption - 2\nChoose action(1,2): ";
	cin >> action;
	cout << "\nEnter key: ";
	cin >> key;
	cout << '\n';

	char c = 'a';
	int pos = 0;

	input >> noskipws;
	while (input >> c)
	{
		if (c >= 'a' && c <= 'z')
			c -= 32;

		if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'))
		{
			if (action == '1')
				c = alphabetS[(alphabetV[c] + alphabetV[key[pos]]) % 36];
			else if (action == '2')
				c = alphabetS[(alphabetV[c] + 36 - alphabetV[key[pos]]) % 36];

			pos++;

			if (pos >= key.size())
				pos = 0;
		}

		output << c;
	}

	return 0;
}