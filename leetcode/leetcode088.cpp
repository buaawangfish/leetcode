#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (n == 0)
	{
		nums1 = vector<int>(nums1.begin(), nums1.begin() + m);
		return;
	}
		
	if (m == 0)
	{
		nums1 = vector<int>(nums2.begin(), nums2.end());
		return;
	}
	int i = m - 1;
	int j = n - 1;
	while(i >= 0 && j >= 0)
	{
		if (nums1[i] >= nums2[j])
		{
			nums1[i + j + 1] = nums1[i];
			i--;
		}
		else if (nums1[i] < nums2[j])
		{
			nums1[i + j + 1] = nums2[j];
			j--;
		}
	}
	while (j >= 0)
	{
		nums1[j] = nums2[j];
		j--;
	}
	getchar();
	return;
}

int main()
{
	vector<int> nums1{ 1 };
	vector<int> nums2{ };
	merge(nums1, 1, nums2, 0);
	for (auto x : nums1)
		cout << x << ' ';
	getchar();
	return 0;
}