#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums) {
	if (nums.empty()) return 0;
	vector<int> dp;
	for (int i = 0; i < nums.size(); i++) {
		if (i == 0) dp.push_back(nums[i]);
		else if (i == 1) dp.push_back(max(dp[0], nums[i]));
		else dp.push_back(max(dp[i - 2] + nums[i], dp[i - 1]));
	}
	return *(dp.end() - 1);
}

int main() {
	vector<int> input{ 2,7,9,3,1 };
	int result = rob(input);
	cout << result;
	getchar();
	return 0;
}