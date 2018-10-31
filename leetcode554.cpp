#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>


using namespace std;

int leastBricks(vector<vector<int>>& wall) {
	if (wall.empty())
		return 0;
	
	unordered_map<int, int> layers;

	for (int i = 0; i < wall.size(); i++)
	{
		for (int j = 1; j < wall[i].size(); j++)
		{
			wall[i][j] += wall[i][j - 1];
			layers[wall[i][j-1]]++;
		}
	}
	int max_val = 0;
	for (auto each : layers)
	{
		if (each.second > max_val)
			max_val = each.second;
	}
	return wall.size()-max_val;
}

int main()
{
	vector<vector<int>> input{
		{ 1, 2, 2, 1 },
		{3, 1, 2},
		{1, 3, 2},
		{2, 4},
		{3, 1, 2},
		{1, 3, 1, 1}
};
	leastBricks(input);
	for (auto x : input[0])
		cout << x << ' ';
	getchar();
	return 0;
}