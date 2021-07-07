#include <iostream>

class Interval {
private:
	int a;
	int k;
	int current;
public:
	Interval(int a, int k);
	int operator*();
	Interval& operator++();
	Interval operator++(int x);
	void reset();
	bool last();
	int getK();
};

Interval::Interval(int a, int k) {
	if (a > k || a < 0 || k < 0) {
		this->a = 0;
		this->k = 0;
	}
	this->a = a;
	this->k = k;
	this->current = a;
}

int Interval::operator*() {
	return current;
}

Interval& Interval::operator++() {
	if (!last()) {
		++current;
	}
	return *this;
}

Interval Interval::operator++(int x) {
	Interval old = *this;
	if (!last()) {
		current++;
	}

	return old;
}

void Interval::reset() {
	current = a;
}

bool Interval::last() {
	return current == k;
}

int Interval::getK() {
	return k;
}

class SquaredInterval : public Interval {
private:
public:
	SquaredInterval(int a, int k);
	int operator*();
};

SquaredInterval::SquaredInterval(int a, int k) : Interval(a, k) {
}

int SquaredInterval::operator*() {
	return Interval::operator*() * Interval::operator*();

}

int getMax(SquaredInterval interval) {
	SquaredInterval i = interval;
	do {
		++i;
	} while (!i.last());
	return *i;
}

void sort(SquaredInterval intervals[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (getMax(intervals[j]) > getMax(intervals[j+1])) {
				SquaredInterval i = intervals[j];
				intervals[j] = intervals[j + 1];
				intervals[j + 1] = i;
			}
		}
	}
}

//int main() {
//	//Interval i(0, 10);std::cout << *i << std::endl;do { ++i;std::cout << *i << std::endl; } while (!i.last());
//
//	SquaredInterval i(0, 10);
//	std::cout << *i << std::endl;
//	do { 
//		++i;
//		std::cout << *i << std::endl; 
//	} while (!i.last());
//
//	SquaredInterval i1(0, 10);
//	SquaredInterval i2(0, 12);
//	SquaredInterval i3(0, 11);
//	SquaredInterval i4(0, 15);
//	SquaredInterval i5(0, 20);
//	SquaredInterval intervals[] = { i1, i2, i3, i4, i5 };
//	sort(intervals, 5);
//	for (SquaredInterval i : intervals) {
//		std::cout << i.getK() << " ";
//	}
//
//	return 0;
//
//}