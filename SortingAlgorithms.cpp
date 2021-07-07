#include <iostream>

using namespace std;

template <typename T>
void swapItems(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void bubbleSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		bool isSorted = true;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swapItems(arr[j], arr[j + 1]);
				isSorted = false;
			}
		}
		if (isSorted) {
			break;
		}
	}
}

template <typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		T min = arr[i];
		int k = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < min) {
				k = j;
				min = arr[k];
			}
		}
		arr[k] = arr[i];
		arr[i] = min;
	}
}

int partition(int arr[], int left, int right) {
	int pivot = arr[right];

	int k = left - 1;

	for (int i = left; i <= right; i++) {
		if (arr[i] <= pivot) {
			k++;
			int temp = arr[k];
			arr[k] = arr[i];
			arr[i] = temp;
		}
	}

	//return the position of the pivot
	return k;
}

void quickSort(int arr[], int left, int right) {
	if (left >= right) {
		return;
	}

	int k = partition(arr, left, right);

	quickSort(arr, left, k - 1);
	quickSort(arr, k + 1, right);
}

//int main() {
//	int arr[10] = { 5, 6, 7, 10, 1, 2, 5, 6, 7, 6 };
//
//	for (int i = 0; i < 10; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//
//	quickSort(arr, 0, 9);
//
//	for (int i = 0; i < 10; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}