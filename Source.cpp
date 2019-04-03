
#include "Header.h"

vector <string> rF()
{
	ifstream input("input.txt");
	string g;
	vector <string> G;
	while (!input.eof())
	{
		input >> g;
		g = g + " ";
		G.push_back(g);
	}
	input.close();
	return G;
}

string summary(vector <string> vS)
{
	int size = vS.size();
	string line;
	for (int i = 0; i < size; i++)
	{
		line += vS[i];
	}
	return line;
}

void cutNum(string line)
{
	/*for (int i = 0; i < line.length(); i++) {	}*/
	while (!line.empty())
	{
		if (isdigit(line[0]))
		{
			int digit = stoi(line);

			string str = to_string(digit);
			str += ".txt";
			ofstream output(str);
			output << digit;
			output.close();
			while (isdigit(line[0]))
			{
				line.erase(0, 1);
			}
		}
		else{line.erase(0, 1);	}
	}

}


int Dec(int digit, string& temp)
{
	int a = digit % 10;
	switch (a)
	{
	case 0: {temp = "zero"; return 0; }
	case 1: {temp = "one"; return 1; }
	case 2: {temp = "two"; return 2; }
	case 3: {temp = "three";  return 3; }
	case 4: {temp = "four"; return 4 ; }
	case 5: {temp = "five"; return 5; }
	case 6: {temp = "six"; return 6; }
	case 7: {temp = "seven"; return 7; }
	case 8: {temp = "eight"; return 8; }
	case 9: {temp = "nine"; return 9; }

	default:cout << "error eoS\n";
		break;
	}

}


string NameIt(int digit)
{
	string name, temp;
	if (digit > 1000)
	{
		int a = digit % 1000000;
		if (Dec(a, temp))
		{
			temp += " thousands";
		}
		else{ temp  = "thousand"
		}

	}
	if (digit < 10)
	{
		Dec(digit, name);
	}


	return name;
}
