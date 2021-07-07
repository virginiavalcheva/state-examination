#include <iostream>
#include <queue>

using namespace std;

void print(char arr[][100], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int findCount(char arr[][100], int n, int m, int i, int j) {

	int count = 1;

	bool visited[100][100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	queue<pair<int, int>> qu;
	qu.push(pair<int, int>(i, j));
	visited[i][j] = true;

	while (!qu.empty()) {
		pair<int, int> front = qu.front();

		int i = front.first;
		int j = front.second;

		if (i - 1 >= 0 && arr[i - 1][j] == '4' && !visited[i - 1][j]) {
			qu.push(pair<int,int>(i - 1, j));
			count++;
			visited[i - 1][j] = true;
		}
		if (i + 1 < n && arr[i + 1][j] == '4' && !visited[i + 1][j]) {
			qu.push(pair<int, int>(i + 1, j));
			count++;
			visited[i + 1][j] = true;
		}
		if (j - 1 >= 0 && arr[i][j - 1] == '4' && !visited[i][j - 1]) {
			qu.push(pair<int, int>(i, j - 1));
			count++;
			visited[i][j - 1] = true;
		}
		if (j + 1 >= 0 && arr[i][j + 1] == '4' && !visited[i][j + 1]) {
			qu.push(pair<int, int>(i, j + 1));
			count++;
			visited[i][j + 1] = true;
		}
		qu.pop();
	}

	return count;
}

int findArea(char arr[][100], int n, int m) {
	int maxCount = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '4') {
				int count = findCount(arr, n, m, i, j);
				if (count > maxCount) {
					maxCount = count;
				}
			}
		}
	}
	return maxCount;
}
//
//int main() {
//	int n = 4;
//	int m = 6;
//	char arr[][100] = {
//		{'R', 'R', '1', '1', '4', '2'},
//		{ '1', 'R', 'R', 'R', '4', '4' },
//		{ '4', '1', 'R', 'R', '4', '4' },
//		{ '4', '4', 'S', 'S', 'R', 'R' }
//	};
//
//
//	print(arr, n, m);
//	cout << endl;
//
//	cout << findArea(arr, 4, 6);
//
//}