#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
	ifstream input("input.txt");
	string str, newstr = "";
	int q = 1;
	input >> str;
	char current = str[0];
	for (int i = 1; i < str.length()+1; i++) {
		if (str[i] != current) {
			newstr += to_string(q) + current;
			current = str[i];
			q = 1;
		}
		else {
			q++;
		}
	}
	ofstream output("output.txt");
	output << newstr;
	return 0;
}
