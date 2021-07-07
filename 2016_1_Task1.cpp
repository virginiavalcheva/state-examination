#include <iostream>
#include <vector>

using namespace std;


bool groupContains(vector<pair<int, int>> group, pair<int, int> pair) {
	for (int i = 0; i < group.size(); i++) {
		if (group[i].first == pair.first && group[i].second == pair.second) {
			return true;
		}
	}
	return false;
}

vector<pair<int, int>> findSymmetricGroup(double arr[][11], int n, int i, int j) {
	vector<pair<int, int>> group;

	group.push_back(pair<int, int>(i, j));

	pair<int, int> p1(j, i);
	pair<int, int> p2(n - i - 1, n - j - 1);
	pair<int, int> p3(n - j - 1, n - i - 1);

	if (!groupContains(group, p1)) {
		group.push_back(p1);
	}
	if (!groupContains(group, p2)) {
		group.push_back(p2);
	}
	if (!groupContains(group, p3)) {
		group.push_back(p3);
	}

	return group;
}

int findAverage(double arr[][11], vector<pair<int, int>> group) {
	int sum = 0;
	for (int i = 0; i < group.size(); i++) {
		sum += arr[group[i].first][group[i].second];
		cout << "i " << group[i].first << " j " << group[i].second << " element " << arr[group[i].first][group[i].second] << " ";
	}
	cout << " SUM " << sum << endl;
	return sum / group.size();
}

void changeMatrix(double arr[][11], int n) {
	for (int i = 0; i < n / 2 + 1; i++) {
		for (int j = i; j < n - i ; j++) {
			vector<pair<int, int>> group = findSymmetricGroup(arr, n, i, j);
			int average = findAverage(arr, group);
			for (int i = 0; i < group.size(); i++) {
				arr[group[i].first][group[i].second] = average;
			}
		}
	}
}

//int main() {
//
//	double arr[][11] = {
//		{1, 2, 3, 4},
//		{5, 6, 7, 8},
//		{9, 10, 11, 12},
//		{13, 14, 15, 16 }
//	};
//
//	changeMatrix(arr, 4);
//
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}