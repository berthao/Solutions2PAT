#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
	
	int count, p, maxlength = 0;
	long long way2go, temp;
	cin >> count >> p;

	vector<long long> numbers;

	for (int i = 0; i < count; i++){
		cin >> temp;
		numbers.push_back (temp);
	}

	sort (numbers.begin (), numbers.end ());

	for (auto small = numbers.begin(), big = numbers.begin(); big < numbers.end(); small++) {
		way2go = *small * p;
		while (big < numbers.end() && *big <= way2go)
			big++;
		if (big - small > maxlength)
			maxlength = big - small;
	}

	cout << maxlength << endl;

	return 0;
}
