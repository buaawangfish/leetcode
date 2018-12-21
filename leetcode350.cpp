#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.empty() || nums2.empty())
		return vector<int>();

	unordered_map<int, int> m;
	for (int num : nums1)
	{
		if (m[num] == 0)
			m[num] = 1;
		else
			m[num] += 1;
	}

	vector<int> result;
	for (int num : nums2)
	{
		if (m[num] == 0)
			continue;
		else
		{
			m[num] -= 1;
			result.push_back(num);
		}
	}
	return result;
}

int main()
{
	vector<int> input1{ 4, 9, 5 }, input2{ 9, 4, 9, 8, 4 };
	vector<int> output = intersect(input1, input2);
	for (int each : output)
	{
		cout << each << endl;
	}
	getchar();
	return 0;
}