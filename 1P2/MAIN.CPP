#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <ctype.h>
#include "../utils/vector.hpp"
#include "../utils/map.hpp"


int main(void) {
	ifstream file("input.txt");
	unsigned long long sum = 0;
	Vector<long> lhs(1024);
	Map<long, long> rhs(1024);
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
				long *mapValue = rhs.get(temp);
				if(mapValue != NULL) {
					*mapValue += 1;
				} else {
					rhs.put(temp, 1);
				}
				putWhere = 0;
			}
			temp = -1;
		}
	}

	file.close();

	for (size_t i = 0; i < lhs.getSize(); ++i) {
		long *occurances = rhs.get(lhs[i]);
		if (occurances == NULL) continue;
		sum += lhs[i] * (*occurances);
	}
	cout << "result: " << sum << endl;

	return 0;
}