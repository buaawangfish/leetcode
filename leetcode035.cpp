#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int low = 0, high = nums.size() - 1;
	if (nums.size() == 0) return 0;
	int mid = 0;
	while (low <= high){
		cout << "low: " << low << ' ' << nums[low] << " high: " << high << ' ' << nums[high];
		cout << " mid: " << mid << ' ' << nums[mid] << endl;
		mid = (low + high) / 2;
		if (target < nums[low]) return low;
		if (target > nums[high]) return high + 1;
		if (nums[mid] == target) return mid;
		else if (nums[mid] > target) high = mid-1;
		else if (nums[mid] < target) low = mid+1;
	}
	
	return mid;
}

int main(){
	int input[] = { 0, 1, 2, 3, 4, 5, 7, 8, 9 };
	vector<int> input_vec(input, input + 9);

	cout << searchInsert(input_vec, 10);
	getchar();
	return 0;
}
