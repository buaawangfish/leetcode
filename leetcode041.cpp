#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
	int n = nums.size();
	vector<int> new_vec(n, 0);
	for (int i = 0; i < n; i++) {
		if (nums[i] >= n || nums[i] <= 0 || nums[i] == (i + 1) || nums[i] == nums[nums[i] - 1]) continue;
		else if (nums[i] != i + 1) {
			swap(nums[i], nums[nums[i] - 1]);
			i--;
		}
	}
	for (auto num : nums) cout << num << ' ';
	for (int i = 0; i < n; i++){
		if (nums[i] != i + 1) return (i+1);
	}
	return n + 1;
}

int main() {
	int input_raw[] = { -1, 4, 2, 1, 9, 10 };
	vector<int> input(input_raw, input_raw + 6);
	cout << firstMissingPositive(input);
	getchar();
	return 0;
}
