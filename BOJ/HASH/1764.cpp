#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, int> m;

int main() {
	
	int N, M; //듣지 못한 사람 수 N, 보지 못한 사람 수 M
	int cnt = 0;
	string temp;
	vector<string> list;
	
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::cin >> temp;
		m[temp]++; //듣지 못한 사람 입력받아서 map에 저장, value값은 자동으로 증가하는 듯?
	}
	for (int j = 0; j < M; j++) {
		std::cin >> temp;
		m[temp]++; //보지 못한 사람 입력받아서 map에 저장
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