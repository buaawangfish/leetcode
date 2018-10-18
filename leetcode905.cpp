#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
	int left = 0, right = A.size() - 1;
	while (left != A.size() && right >= 0) {
		if ((A[left] % 2 == 1) && (A[right] % 2 == 0)/* && left < right*/) {
			swap(A[left], A[right]);
			left++; right--;
		}
		else if (A[left] % 2 == 1) right--;
		else if (A[right] % 2 == 0) left++;
		else { left++; right--; }
		if (left >= right) break;
	}
	/*
	auto left = A.begin(), right = A.end() - 1;
	while (left != A.end() && right != A.begin()-1) {
		if (*left % 2 == 1 && *right % 2 == 0) {
			swap(*left, *right);
			left++; right--;
		} 
		else if (*left % 2 == 1) right--;
		else if (*right % 2 == 0) left++;
	}
	*/
	return A;
}

int main() {
	vector<int> A = { 3,1,2,4 };
	sortArrayByParity(A);
	for (auto x: A)
	{
		cout << x << endl;
	}
	getchar();
	return 0;
}