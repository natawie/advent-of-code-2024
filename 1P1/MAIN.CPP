#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <ctype.h>
#include "../utils/vector.hpp"

int descSort(const void *a, const void *b) {
	long arg1 = *(const long *)a;
	long arg2 = *(const long *)b;

	return (arg1 < arg2) - (arg1 > arg2);
}


int main(void) {
	ifstream file("input.txt");
	Vector<long> lhs(1024);
	Vector<long> rhs(1024);
	char ch;
	long temp = -1;
	int putWhere = 0; // 0 - left; 1 - right
	while (file.get(ch)) {
		if (isdigit(ch)) {
			if (temp == -1) temp = 0;
			temp *= 10;
			temp += (ch - '0');
			continue;
		}
		if (temp != -1) {
			if (!putWhere) {
				lhs.push(temp);
				putWhere = 1;
			} else {
				rhs.push(temp);
				putWhere = 0;
			}
			temp = -1;
		}
	}
	lhs.quickSort(descSort);
	rhs.quickSort(descSort);
	file.close();
	long sum = 0;
	while (lhs.getSize() > 0 || rhs.getSize() > 0)
		sum += abs(lhs.pop() - rhs.pop());
	cout << "result: " << sum << endl;

	return 0;
}