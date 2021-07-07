#include <iostream>

using namespace std;

bool member(int x, int a[], int size) {
	if (size == 0) return false;
	
	return a[size / 2] == x || (a[size / 2] < x && member(x, a, size / 2)) || (a[size / 2] > x && member(x, a, size / 2));
}

void selectionSort(int nums[], int n) {
	for(int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
				if (nums[j] < nums[min]) min = j;
			}   
		if (min != i) { 
			int x = nums[i];
			nums[i] = nums[min];
			nums[min] = x;
		}
	}
}

//int main() {
//
//	int x = 3;
//
//	int arr[] = { 1,2,3,4,5,6,7 };
//
//	cout << member(x, arr, 7);
//
//	int arr1[] = { 3,4,6,1,2,8,9 };
//	selectionSort(arr1, 7);
//
//	for (int i = 0; i < 7; i++) {
//		cout << arr1[i] << " ";
//	}
//	return 0;
//}