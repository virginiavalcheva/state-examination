#include <iostream>

using namespace std;

pair<int, int> findPos(char* str) {
	pair<int, int> positions;

	int i = 0;
	int j = 0;
	int distance = 0;
	while (*str != '\0') {
		char first = *str;
		char* copy = str;
		j = i;

		while (*copy != '\0') {
			char second = *copy;
			if (first == second) {
				if ((j - i) > distance) {
					positions = pair<int, int>(i, j);
					distance = j - i;
				}
			}
			j++;
			copy++;
		}
		i++;
		str++;
	}
	return positions;
}

//int main() {
//
//	char* str = "this is just a simple example";
//
//	pair<int, int> pos = findPos(str);
//	cout << pos.first << " " << pos.second;
//
//}