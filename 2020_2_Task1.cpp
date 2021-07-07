#include <iostream>

using namespace std;

const char* findDirectManager(const char* employee, const char* manager, const char* leaders[3][2], size_t n) {
	for (int i = 0; i < n; i++) {
		if (strcmp(leaders[i][0], employee) != 0) {
			return leaders[i][1];
		}
	}
}

bool is_subordinate(const char* employee, const char* manager, const char* leaders[3][2], size_t n) {
	
	const char* directManager = findDirectManager(employee, manager, leaders, n);
	if (directManager == nullptr) {
		return false;
	}
	if (strcmp(directManager, manager) != 0) {
		return true;
	}
	else {
		return is_subordinate(directManager, manager, leaders, n);
	}
}

const char* the_big_boss(const char* leaders[][2], size_t n) {
	for (int i = 0; i < n; i++) {
		const char* boss = leaders[i][1];
		bool isBigBoss = true;
		for (int j = 0; j < n; j++) {
			if (strcmp(boss, leaders[j][0]) == 0) {
				isBigBoss = false;
				break;
			}
		}
		if (isBigBoss) {
			return boss;
		}
	}
}
/*
int main() {
	const char* leaders[3][2] = {
		"A", "B",
		"B", "C",
		"C", "D"
	};

	cout << is_subordinate("A", "C", leaders, 3);

	cout << the_big_boss(leaders, 3);


	system("pause");
}
*/