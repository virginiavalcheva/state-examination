#include <iostream>

using namespace std;

bool compare(char* str1, char* str2) {
	while (*str1 && *str2) {
		if (*str1 > *str2) {
			return true;
		}
		else if (*str1 < *str2)
		{
			return false;
		}
		str1++;
		str2++;
	}
	if (*str1) {
		return true;
	}
	return false;
}

bool isSorted(char* a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (compare(a[i], a[i + 1])) {
			return false;
		}
	}
	return true;
}

void printWord(char* word) {
	int count = 0;
	while (*word) {
		
		if (word == " ") {
			cout << count << " ";
			count = 0;
		}
		else {
			count++;
		}
		word++;
	}
	cout << count << " ";
}

void revealPassword(char* a[][30], int m, int n) {
	int middle = n / 2;
	for (int i = 0; i < m; i++) {
		if (isSorted(a[i], n)) {
			char* word = a[i][middle];
			printWord(word);
		}
	}
}

//int main() {
//
//	//char* a[3][30] = {
//	//	{"Алгебра", "Аналитична геометрия", "Математически анализ"},
//	//	{"Увод в програмирането", "Обектно-ориентирано програмиране", "Структури от данни и програмиране"},
//	//	{"Бази от данни", "Изкуствен интелек", "Функционално програмиране"}
//	//};
//
//	char* a[3][30] = {
//		{ "al", "an", "ma" },
//		{ "uv", "ov", "st" },
//		{ "b", "isk", "zed" }
//	};
//	revealPassword(a, 3, 3);
//	return 0;
//}