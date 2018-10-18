#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
	vector<int> result(rowIndex + 1, 1);
	for (int i = 1; i <= rowIndex / 2; i++) {
		result[i] = static_cast<unsigned long>(result[i - 1]) * static_cast<unsigned long>(rowIndex - i + 1) / i;
		result[rowIndex - i] = result[i];
	}
	return result;
}

int main() {
	auto result = getRow(31);
	for (auto x : result) {
		cout << x << ' ';
	}
	getchar();
	return 0;
}