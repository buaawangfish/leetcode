#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.empty() || nums2.empty()) return vector<int>();

	set<int> set2;
	unordered_set<int> set1;
	for (int num : nums1)
		set1.insert(num);
	for (int num : nums2)
	{
		if (find(set1.begin(), set1.end(), num) != set1.end())
			set2.insert(num);
	}
	return vector<int>(set2.begin(), set2.end());
}

int main()
{
	return 0;
}