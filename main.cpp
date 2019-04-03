#include "Header.h"

int main()
{
	vector <string> My = rF();
	string line = summary(My);
	cout << line << endl;
	cutNum(line);
	string line = NameIt(120034);
	cout << line << endl;

	system("pause");
	return 0;
}
