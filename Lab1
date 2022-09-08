#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

string decode(string code) {
	string str = code;
	//string new_str;
	for (int i = 0; i < 3; i++) {
		str = str[str.length() - 1] + str.substr(0, str.length() - 1);
	}
	return str;
}

void main() {
	system("chcp 1251");
	ifstream input("text.txt");
	string text(istreambuf_iterator<char>{input}, {});

	istringstream iss(text);
	vector<string> results(istream_iterator<string>{iss}, istream_iterator<string>());

	for (int i = 0; i < results.size(); i++) {
		cout << decode(results[i]) << " ";
	}
	cin >> text;
}
