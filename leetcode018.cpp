#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;


vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> result;
	if (nums.size() <= 3) return result;
	sort(nums.begin(), nums.end());
	if (accumulate(nums.begin(), nums.begin() + 4, 0) > target
		&& accumulate(nums.end() - 4, nums.end(), 0) < target) return result;
	// -4 -1 -1 0 1 2
	for (auto ptr1 = nums.begin(); ptr1 != nums.end() - 3; ptr1++)
	{
		if (ptr1 != nums.begin() && (*ptr1 == *(ptr1 - 1))) continue;
		for (auto ptr2 = ptr1 + 1; ptr2 != nums.end() - 2; ptr2++)
		{
			if (ptr2 != ptr1 + 1 && (*ptr2 == *(ptr2 - 1))) continue;
			vector<int>::iterator left = ptr2 + 1;
			vector<int>::iterator right = nums.end() - 1;
			while (left < right) {
				if (left != ptr2 + 1 && *left == *(left - 1)) {
					left++; continue;
				}
				if (right != nums.end() - 1 && *right == *(right + 1)) {
					right--; continue;
				}
				if (*ptr1 + *ptr2 + *left + *right < target) {
					left++; continue;
				}
				else if (*ptr1 + *ptr2 + *left + *right > target) {
					right--; continue;
				}
				else {
					result.push_back(vector<int>{*ptr1, *ptr2, *left, *right});
					left++; right--;
				}
			}
		}
	}

	return result;
}


int main() {
	vector<int> a{ -1, 0, 1, 2, -1, -4 }; // -4 -1 -1 0 1 2
	vector<vector<int>> result = fourSum(a, -1);
	for (auto rows : result) {
		for (auto cols : rows) {
			cout << cols << ' ';
		}
		cout << endl;
	}

	getchar();
	return 0;
}
