#include <iostream>
using namespace std;

int main() {
	int itr, total=0;
	char st[100];
	cin >> itr;
	cin >> st;
	for (int i = 0; i < itr; i++) {
		total += st[i] - '0';
	}
	cout << total;

}