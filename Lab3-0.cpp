#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
	ifstream input("input.txt");
	string text;
	input >> text;
	int index = 0, length = text.length();
	for (; index < length - 1;) {
		if (text[index] == text[index + 1]) {
			text = text.substr(0, index) + text.substr(index + 2, length - index - 2);
			if(index > 0) index -= 1;
			length -= 2;
		}
		else {
			index++;
		}
	}
	ofstream output("output.txt");
	output << text;
	return 0;
}
