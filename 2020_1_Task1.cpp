#include <iostream>

using namespace std;

void print_backwards(const char* begin, const char* end);
void print_backwards(const char* string);

void printWord(const char* start) {
	if ((int)*start <= 32) {
		return;
	}
	cout << *start;
	printWord(start + 1);
}
void print_backwards(const char* begin, const char* end) {
	if ((int)*(end - 1) > 32 && (int)*(end - 2) <= 32) {
		printWord(end - 1);
		if (end - 1 != begin) {
			cout << " ";
		}
	}
	if (begin == end - 1) {
		return;
	}
	print_backwards(begin, end - 1);
}

void print_backwards(const char* string) {
	char* begin = (char*)string;
	char* end = begin;
	while (end[0] != '\0') {
		end++;
	}
	print_backwards(begin, end);
}

//int main() {
//
//	int n = 5;
//	const int* ptr = new int[5];
//
//	// cout << *ptr;
//
//	const char* str = "I\tneed a break!";
//	//cout << str;
//	print_backwards(str);
//	return 0;
//}