#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
	if (cost.size() <= 1) return 0;
	vector<int> accu_cost(cost.size());
	accu_cost[0] = cost[0];
	accu_cost[1] = cost[1];
	for (int i = 2; i < accu_cost.size(); i++) {
		accu_cost[i] = min(accu_cost[i - 2] + cost[i], accu_cost[i-1] + cost[i]);
	}
	return min(*(accu_cost.end() - 1), *(accu_cost.end() - 2));
}

int main() {
	vector<int> cost = { 10, 15, 20 };
	cout << "result: " << minCostClimbingStairs(cost);

	getchar();
	return 0;
}