#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
	vector<int> result(deck.size());
	if (deck.empty()) return result;
	vector<int> idx_arr(deck.size());
	for (int i = 0; i < idx_arr.size(); i++)
		idx_arr[i] = i;
	int idx = 0;
	int n = deck.size();
	int cnt = 0;
	sort(deck.begin(), deck.end());
	do
	{
		result[idx] = deck[cnt];
		idx_arr[idx] = -1;
		cnt++;
		int temp = 0;
		if (cnt == n)
			break;
		while (temp < 2)
		{
			idx++;
			idx %= n;
			if (idx_arr[idx] == -1)
				continue;
			else
				temp++;
		}
	} while (cnt <= n);
	return result;
}

int main()
{
	vector<int> input{ 17, 13, 11, 2, 3, 5, 7 };
	vector<int> output = deckRevealedIncreasing(input);
	for (auto x : output)
	{
		cout << x << ' ';
	}
	getchar();
	return 0;
}