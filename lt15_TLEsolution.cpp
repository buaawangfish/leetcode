#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

vector<vector<int> > twoSum(vector<int>& nums, int target){
	unordered_map<int, int>hashmap;
	vector<int> result(3);
	vector<vector<int> >result_vec;
	set<vector<int> > result_set;
	set<int> nums_set;
	for (int i = 0; i < nums.size(); i++)
	{
		int temp = target - nums.at(i);
//		if (nums_set.find(temp) == nums_set.end()){
			auto it = hashmap.find(temp);
			if (it != hashmap.end()){
				result[0] = temp;
				result[1] = target - temp;
				result[2] = -target;
				sort(result.begin(), result.end());
				result_set.insert(result);
			}
			else {
				hashmap.insert(make_pair(nums.at(i), i));
			}
			nums_set.insert(temp);
//		}
//		else continue;		
	}
	std::copy(result_set.begin(), result_set.end(), back_inserter(result_vec));
	return result_vec;
}

vector<vector<int>> threeSum(vector<int>& nums) {
	set<vector<int> > result_set;
	vector<vector<int> > result;
	set<int> nums_set;

	for (auto it = nums.begin();  it != nums.end()-2;  it++)
	{
		if (nums_set.find(*it) == nums_set.end()){
			vector<int> sub_nums(it + 1, nums.end());
			vector<vector<int> > sub_result = twoSum(sub_nums, -(*it));
			for (auto x : sub_result) result_set.insert(x);
			nums_set.insert(*it);
		}
		else continue;
	}
	std::copy(result_set.begin(), result_set.end(), back_inserter(result));
	return result;
}


int main(){
	int input_raw[] = { -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, 0, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	vector<int> input(input_raw, input_raw + 30);
	vector<int> input_2(100000, 0);
	vector<vector<int> > result = threeSum(input_2);
	for (auto ext: result)
	{
		for (auto in : ext){
			cout << in << ' ';
		}
		cout << endl;
	}
	
	getchar();
	return 0;
}
