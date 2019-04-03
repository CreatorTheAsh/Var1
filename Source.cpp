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
			output << NameIt(digit);
			output.close();
			while (isdigit(line[0]))
			{
				line.erase(0, 1);
			}
		}
		else{line.erase(0, 1);	}
	}

}


int simple(int digit, string& temp)
{
	switch (digit)
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

	default://cout << "error simple\n";
		break;
	}

}

bool Hun(int digit, string &a)
{
	if (digit >= 1000) { return false; }
	if (digit < 100) { Dec(digit, a); return true; }
	string temp; a.clear();
	int t = digit / 100;
	temp = a;
	simple(t, temp);
	a += temp + " hundred";
	digit -= t * 100;
	Dec(digit, temp);
	a += " " + temp;
	return true;



}

bool Dec(int digit, string& a)
{
	string temp; a.clear();
	if (digit >= 100) { return false; }
	if (digit < 10) { if (simple(digit, a)); else { a.clear(); } return false; }
	if (digit <= 20) { a = teen(digit); return true; }
	else {
		int b = digit / 10;
		int c = digit - b * 10;
		if (simple(b, temp))
		{

			int u = simple(b, temp);
			a += temp;
			a += "ty";
			if (u == 5) { a = "fifty"; }
			if (u == 3) { a = "thirty"; }
			if (u == 2) { a = "twenty"; }
		}
		if (simple(c, temp)) { a = a + " " + temp; }
	}
	return true;
}

string teen(int digit)
{
	string teen;
	if (digit == 0) {  return teen; }
	if (digit == 20) { teen = "twenty"; return teen; }
	int f = digit % 10;
	if (simple(f, teen) > 3) {
		teen += "teen";
	}
	else
	{
		if (simple(f, teen) == 0) { teen = "ten";	return teen;		}
		if (simple(f, teen) == 1) { teen = "eleven"; 	return teen;		}
		if (simple(f, teen) == 2) { teen = "twelve";	return teen;		}
		if (simple(f, teen) == 3) { teen = "thirteen";	return teen;		}

	}
	return teen;
}
string NameIt(int digit)
{
	string name = "", temp;
	digit = digit % 1000000;
	int a = digit;


	if (digit >= 1000)
	{
		a /= 1000;
		Hun(a, temp);
		temp += " thousand";
		name += temp;
		temp.clear();
		int b = digit - a * 1000;
		if(Hun(b,temp)){ name = name + " " + temp; }
		else { temp.clear(); }
	}
	else
	{
		if (digit < 10) { simple(digit, name); return name; }
		if (Hun(digit, temp)) { name += temp; return name; }
		cout << "error in NameIt\n";
	}
	return name;
}
