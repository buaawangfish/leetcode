#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> helper(vector<int>& candidates, int target)
{
	vector<vector<int>> res;
	if (candidates.size() == 0)
		return res;
	if (target < candidates[0] && candidates[0] > 0)
		return res;
	if (target > candidates.back() && candidates.back() < 0)
		return res;

	for (int i = 0; i < candidates.size(); i++)
	{
		if (candidates[i] == target)
		{
			res.push_back(vector<int>{target});
		}
		else
		{
			vector<int> sub_candidates(candidates.begin() + i, candidates.end());
			vector<vector<int>> sub_res = helper(sub_candidates, target - candidates[i]);
			int t = candidates[i];
			for_each(begin(sub_res), end(sub_res), [t](vector<int> &each_vec){
				each_vec.insert(each_vec.begin(), t);
			});
			res.insert(res.end(), sub_res.begin(), sub_res.end());
		}
	}
	return res;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> res;
	res = helper(candidates, target);
	return res;
}

int main()
{
	vector<int> input{ 2, 3, 6, 7 };
	vector<vector<int>> result = combinationSum(input, 7);
	getchar();
	return 0;
}