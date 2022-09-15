#include<iostream>
#include<fstream>

using namespace std;

int SUM(int* mas, int N) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += mas[i];
	}
	return sum;
}

void copy(int* M1, int* M2, int N) {
	for (int i = 0; i < N; i++) {
		M1[i] = M2[i];
	}
}

void sochet(int* J, int N, int n, int* q, int* A, int last, int M, int* V) {
	if (n == M) {
		if (SUM(J, M) % N == 0) {
			*q += 1;
			copy(V, J, N);
		}
		//for (int i = 0; i < M; i++) cout << J[i] << " ";
		//cout << endl;
		
		return;
	}
	else {
		for (int i = last; i < N; i++) {
			J[n] = A[i];
			sochet(J, N, n + 1, q, A, i+1, M,V);
			J[n] = -1;
		}
	}
}

int main() {
	ifstream input("input.txt");
	int N;
	int* C;
	input >> N;
	C = new int[N];
	for (int i = 0; i < N; i++) {
		input >> C[i];
	}
	ofstream output("output.txt");
	int* J = new int[N];
	int* V = new int[N];
	int* q = new int;
	*q = 0;
	for(int i = 1; i <= N; i++) sochet(J, N, 0, q, C, 0,i,V);

	if (*q > 0) {
		output << "YES" << endl;
		for (int i = 0; i < N; i++) if (V[i] > 0) output << V[i] << endl;
		output << *q;
	}
	else {
		output << "NO" << endl;
	}
	return 0;
}
