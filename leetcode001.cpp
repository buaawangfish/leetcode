#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);
vector<vector<int>> threeSum(vector<int>& nums);
int main(){
	int test[] = { 2,7,11,15 };
	vector<int>input(test, test + 4);
	auto output = twoSum(input, 9);
	for (auto x: output)
	{
		cout << x << endl;
	}

	getchar();
	return 0;
}

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int> > result;
	vector<int> flag(2, 0);
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		vector<int> sub_nums(it + 1, nums.end());
		vector<int> temp = twoSum(sub_nums, -(*it));
		if (temp != vector<int>(0, 0))
	}
}

vector<int> twoSum(vector<int>& nums, int target){
	unordered_map<int, int>hashmap;
	vector<int> result(2);
	for (int i = 0; i < nums.size(); i++)
	{
		int temp = target - nums.at(i);
		auto it = hashmap.find(temp);
		if (it != hashmap.end()){
			result[0] = temp;
			result[1] = target - temp;
			return result;
		}
		else {
			hashmap.insert(make_pair(nums.at(i), i));
		}
	}
	return result;
}
