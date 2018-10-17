#include <iostream>
#include <vector>
#include <map>

using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums) {
		sum = vector<int>(nums.size());
		if (!nums.empty()) {
			sum[0] = nums[0];
			for (int i = 1; i < nums.size(); i++){
				sum[i] = sum[i - 1] + nums[i];
			}
		}
	};

	int sumRange(int i, int j) {
		if (i == 0) return sum[j];
		else return sum[j] - sum[i - 1];
	}

private:
	vector<int> sum;
};

int main(){
	vector<int> nums = { -2, 0, 3, -5, 2, -1 };
	NumArray arr(nums);
	cout << arr.sumRange(0, 2);
	cout << arr.sumRange(2, 5);
	cout << arr.sumRange(0, 5);
	getchar();
	return 0;
}