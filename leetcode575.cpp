#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int distributeCandies(vector<int>& candies) {
	unordered_set<int> classes;
	for (auto candy : candies)
		classes.insert(candy);
	return (classes.size() >= candies.size() / 2) ? candies.size() / 2 : classes.size();
}

int main()
{
	vector<int> candies{ 1, 1, 2, 3 };
	cout << distributeCandies(candies);
	getchar();
	return 0;
}