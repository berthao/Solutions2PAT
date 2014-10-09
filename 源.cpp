#include <iostream>
#include <algorithm>
using namespace std;

#define LENGTH 200 // suppose 200 digits in all
#define MAX 100    // 100! = 1*2*3*...*100
#define FIRST 100  // first 100 digits of the result of 100!

int main() {

	int first[LENGTH] = {1}, current = 1;

	for (int i = 2; i <= MAX; i++){
		for (int j = 0; j < current; j++)
			first[j] *= i;
		for (int j = 0; j < current; j++) {
			while (first[j] >= 10) {
				first[j + 1] += first[j] / 10;
				first[j++] %= 10;
			}
			current = max(current, j + 1);
		}
	}

	for (int i = current; i > (current - FIRST); i--)
		cout << first[i - 1];
	cout << endl;

	return 0;

}