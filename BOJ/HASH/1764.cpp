#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, int> m;

int main() {
	
	int N, M; //���� ���� ��� �� N, ���� ���� ��� �� M
	int cnt = 0;
	string temp;
	vector<string> list;
	
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::cin >> temp;
		m[temp]++; //���� ���� ��� �Է¹޾Ƽ� map�� ����, value���� �ڵ����� �����ϴ� ��?
	} 
	for (int j = 0; j < M; j++) {
		std::cin >> temp;
		m[temp]++; //���� ���� ��� �Է¹޾Ƽ� map�� ����
	}

	for (auto k = m.begin(); k != m.end(); k++) {
		if (k->second == 2) {
			cnt++;
			list.push_back(k->first);
		}
	}

	for (auto i = list.begin(); i != list.end(); i++) {
		cout << i->c_str() << endl;
	}


	return 0;
}