#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	if (nums.empty()) return 0;
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		while (nums[len - 1] == val) {
			if (len > i + 1) len--;
			else break;
		}
		if (nums[i] == val) {
			if (i == len - 1) len--;
			else swap(nums[i], nums[len - 1]);
		}
	}
	return len;
}

int main() {
	vector<int> input{ 2, 3, 2 };
	int val = 2;
	int len = removeElement(input, val);
	cout << "len: " << len << endl;
	for (int i = 0; i < len; i++)
	{
		cout << input[i] << ' ';
	}

	getchar();
	return 0;
}
