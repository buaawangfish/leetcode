#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
	if (nums.empty()) return vector<vector<int>>();
	vector< vector<int> > result;
	if (nums.size() == 1) {
		result.push_back(nums);
		return result;
	}
	else {
		vector<int> sub_nums(nums.begin() + 1, nums.end());
		vector<vector<int>> temp = permute(sub_nums);
		for (auto x : temp) {
			for (int i = 0; i < x.size(); i++)
			{
				vector<int> y(x);
				y.insert(y.begin() + i, nums[0]);
				result.push_back(y);
			}
			vector<int> y(x);
			y.push_back(nums[0]);
			result.push_back(y);
		}
	}
	return result;
}

int main(){
	int input[] = { 1, 3, 4, 5 };
	vector<int> input_vec(input, input + 4);
	
	vector<vector<int>> result = permute(input_vec);

	for (auto x : result){
		for (auto y : x){
			cout << y << ' ';
		}
		cout << endl;
	}
	/*
	for (auto x : input_vec) {
		cout << x << ' ';
	}
	input_vec.insert(input_vec.begin() + 3, 237948);
	for (auto x : input_vec) {
		cout << x << ' ';
	}
	*/
	getchar();
	return 0;
}