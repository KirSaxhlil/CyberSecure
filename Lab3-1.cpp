#include<iostream>
#include<fstream>
#include<bitset>
#include<cmath>

using namespace std;

unsigned int grey(unsigned int n) {
	return n ^ (n >> 1);
}

int main() {
	int N;
	cin >> N;
	ofstream output("output.txt");
	for (int i = 0; i < pow(2,N); i++) {
		bitset<16> x(grey(i));
		output << x.to_string().substr(16 - N, N) << endl;
	}
	return 0;
}
