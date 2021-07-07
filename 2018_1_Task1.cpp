#include <iostream>

using namespace std;

int countDigits(int num) {
	int digits = 0;
	while (num != 0) {
		num = num / 10;
		digits++;
	}
	return digits;
}

int isBigger(int first, int second) {
	int digitsFirst = countDigits(first);
	int digitsSecond = countDigits(second);

	int f, s;
	while (digitsFirst > 0 && digitsSecond > 0) {
		digitsFirst--;
		digitsSecond--;
		f = (int)(first / pow(10, digitsFirst)) % 10;
		s = (int)(second / pow(10, digitsSecond)) % 10;
		if (f > s) {
			return true;
		}
		if (f < s) {
			return false;
		}
	}
	if (digitsFirst > digitsSecond) {
		return true;
	}
	return false;
}

void sortLex(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		bool isSorted = true;
		for (int j = 0; j < n - 1; j++) {
			if (isBigger(arr[j], arr[j + 1])) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				isSorted = false;
			}
		}
		if (isSorted) {
			break;
		}
	}
}
//
//int main() {
//
//	int arr[6] = { 13,14,7,2018,9,0 };
//	sortLex(arr, 6);
//	for (int i = 0; i < 6; i++) {
//		cout << arr[i] << " ";
//	}
//	return 0;
//}