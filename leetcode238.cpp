#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
	if (nums.empty()) return vector<int>();
	if (nums.size() == 1) return vector<int>{0};
	int n = nums.size();
	vector<int> forward(n, 1), backward(n, 1);
	forward[0] = nums[0];
	backward[n - 1] = nums[n - 1];
	for (int i = 1; i < n-1; i++)
	{
		forward[i] = forward[i - 1] * nums[i];
		backward[n - 1 - i] = backward[n - i] * nums[n - 1 - i];
	}
	vector<int> result(n, 1);
	for (int i = 1; i < n - 1; i++)
	{
		result[i] = forward[i - 1] * backward[i + 1];
	}
	result[0] = backward[1];
	result[n - 1] = forward[n - 2];
	return result;
}

int main()
{
	vector <int> input = { 1 };
	vector<int> output = productExceptSelf(input);
	for (auto x : output)
	{
		cout << x << ' ';
	}
	getchar();
	return 0;
}