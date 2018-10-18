#include <iostream>
#include <vector>

using namespace std;

bool isMonotonic(vector<int>& A) {
	if (A.size() <= 1) return true;
	bool inc = true, dec = true;
	for (int i = 1; i < A.size(); i++)
	{
		if (A[i] == A[i - 1]) continue;
		if (inc && A[i] > A[i - 1]) {
			dec = false;
			continue;
		}
		else if (dec && A[i] < A[i - 1]) {
			inc = false;
			continue;
		}
		return false;
	}
	return true;
}

int main() {
	vector<int> A = { 1, 1,1};
	bool result = isMonotonic(A);
	cout << ((result == true) ? "true" : "false");
	getchar();
	return 0;
}