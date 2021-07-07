#include <iostream>

using namespace std;

float findAvg(float img[][10], int m, int n, int i, int j) {
	float sum = 0;
	int count = 0;
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (i * 2 <= y && y <= i * 2 + 1  && j * 2 <= x && x <= j * 2 + 1) {
				sum += img[y][x];
				count++;
			}
		}
	}
	return count == 0 ? 0.0 : sum / count;
}
 
void subsample(int m, int n, float img[][10]) {
	int sM = (m + 1) / 2;
	int sN = (n + 1) / 2;
	float** s = new float*[sM];
	for (int i = 0; i < sM; i++) {
		s[i] = new float[sN];
	}
	for (int i = 0; i < sM; i++) {
		for (int j = 0; j < sN; j++) {
			s[i][j] = findAvg(img, m, n, i, j);
		}
	}

	for (int i = 0; i < sM; i++) {
		for (int j = 0; j < sN; j++) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < sM; i++) {
		delete[] s[i];
	}
	delete[] s;
}

//int main() {
//
//	float img[10][10] = {
//		{1.0, 2.0, 3.0},
//		{4.5, 6.5, 7.5}
//	};
//
//	subsample(2, 3, img);
//
//	return 0;
//}