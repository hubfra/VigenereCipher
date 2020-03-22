
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string alphabetS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vector<int> alphabetV(91, 0);

	for (int a = 0; a < 36; a++)
		alphabetV[alphabetS[a]] = a;

	string password;
	ifstream input("input.txt");
	ofstream output("output.txt");
	char action = '1';

	cout << "Encrypt - 1\nDecrypt - 2\n";
	cout << "Choose action: ";
	cin >> action;
	cout << "\nEnter password: ";
	cin >> password;
	cout << '\n';


	char c = 'a';
	int pos = 0;

	while (input >> noskipws >> c)
	{
		if (c >= 'a' && c <= 'z')
		{
			c -= 32;
		}

		if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'))
		{
			if (action == '1')
				c = alphabetS[(alphabetV[c] + alphabetV[password[pos]]) % 36];
			else if (action == '2')
				c = alphabetS[(alphabetV[c] + 36 - alphabetV[password[pos]]) % 36];

			pos++;

			if (pos >= password.size())
				pos = 0;
		}

		output << c;
	}

	return 0;
}