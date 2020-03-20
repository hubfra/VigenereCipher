
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string alphabetS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	vector<int> alphabetV(91, 0);
	alphabetV['0'] = 0;
	alphabetV['1'] = 1;
	alphabetV['2'] = 2;
	alphabetV['3'] = 3;
	alphabetV['4'] = 4;
	alphabetV['5'] = 5;
	alphabetV['6'] = 6;
	alphabetV['7'] = 7;
	alphabetV['8'] = 8;
	alphabetV['9'] = 9;
	alphabetV['A'] = 10;
	alphabetV['B'] = 11;
	alphabetV['C'] = 12;
	alphabetV['D'] = 13;
	alphabetV['E'] = 14;
	alphabetV['F'] = 15;
	alphabetV['G'] = 16;
	alphabetV['H'] = 17;
	alphabetV['I'] = 18;
	alphabetV['J'] = 19;
	alphabetV['K'] = 20;
	alphabetV['L'] = 21;
	alphabetV['M'] = 22;
	alphabetV['N'] = 23;
	alphabetV['O'] = 24;
	alphabetV['P'] = 25;
	alphabetV['Q'] = 26;
	alphabetV['R'] = 27;
	alphabetV['S'] = 28;
	alphabetV['T'] = 29;
	alphabetV['U'] = 30;
	alphabetV['V'] = 31;
	alphabetV['W'] = 32;
	alphabetV['X'] = 33;
	alphabetV['Y'] = 34;
	alphabetV['Z'] = 35;

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
			c -= 32;

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
