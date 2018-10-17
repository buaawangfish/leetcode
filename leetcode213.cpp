#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums) {
	if (nums.empty()) return 0;
	vector<int> dp1(nums.size(), 0), dp2(nums.size(), 0);
	if (nums.size() == 1) return nums[0];
	if (nums.size() == 2) return max(nums[0], nums[1]);
	for (int i = 0; i < nums.size(); i++) {
		if (i == 0) {
			dp1[i] = nums[i];
			continue;
		}
		if (i == 1) {
			dp1[i] = max(dp1[i-1], nums[i]);
			dp2[i] = max(dp2[i - 1], nums[i]);
		}
		else if (i == nums.size() - 1) {
			dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
			continue;
		}
		else {
			dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
			dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
		}
	}
	return max(*(dp1.end() - 2), *(dp2.end() - 1));
}

int main() {
	vector<int> nums = { 1, 2, 3, 1 };
	cout << rob(nums);
	getchar();
	return 0;
}