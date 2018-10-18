#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int min = INT_MAX, max = 0;
	if (prices.size() <= 1) return 0;
	for (int x : prices) {
		if (x < min) min = x;
		else if (max < x - min) max = x - min;
	}
	return max;
}

int main(){

	getchar(); 
	return 0;
}