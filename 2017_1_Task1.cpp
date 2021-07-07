#include <iostream>

using namespace std;

void printMatrix(char arr[][100], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void evolve(char arr[][100], int years, int n, int m) {
	while (years >= 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == '1') {
					arr[i][j] = '2';
				}
				if (arr[i][j] == '2') {
					arr[i][j] = '3';
				}
				if (arr[i][j] == '3') {
					arr[i][j] = '4';
				}
				if (arr[i][j] == '4') {
					int count = 0;
					if (i - 1 >= 0 && arr[i - 1][j] == '4') count++;
					if (arr[i + 1][j] == '4') count++;
					if (arr[i][j - 1] == '4') count++;
					if (arr[i][j + 1] == '4') count++;
					if (arr[i - 1][j - 1] == '4') count++;
					if (arr[i - 1][j + 1] == '4') count++;
					if (arr[i + 1][j - 1] == '4') count++;
					if (arr[i + 1][j + 1] == '4') count++;
					if (count >= 3) {
						arr[i][j] = '3';
					}
				}
			}
		}
		years -= 10;
	}

}

//int main() {
//	int n = 4;
//	int m = 6;
//	char arr[][100] = {
//		{'R', 'R', '1', '1', '2', '2'},
//		{ '1', 'R', 'R', 'R', '1', '2' },
//		{ '4', '1', 'R', 'R', '2', '3' },
//		{ '4', '4', 'S', 'S', 'R', 'R' }
//	};
//
//	printMatrix(arr, n, m);
//	cout << endl;
//
//	evolve(arr, 100, n, m);
//	printMatrix(arr, n, m);
//
//}