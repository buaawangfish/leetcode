#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maximumSwap(int num) {
	vector<int> each_digit;
	int temp = num;
	while (temp >= 10)
	{
		each_digit.push_back(temp % 10);
		temp = temp / 10;
	}
	each_digit.push_back(temp);

	vector<vector<int>::iterator> it_vec(each_digit.size());
	auto digit_begin = each_digit.begin();
	it_vec[0] = digit_begin;

	for (int i = 1; i < it_vec.size(); i++)
	{
		if (*(digit_begin + i) > *it_vec[i - 1])
			it_vec[i] = digit_begin + i;
		else
			it_vec[i] = it_vec[i - 1];
	}
	int n = each_digit.size();
	for (int i = n - 1; i >= 0; i--)
	{
		if (each_digit[i] < *it_vec[i])
		{
			iter_swap(digit_begin + i, it_vec[i]);
			break;
		}
	}
	int result = 0;
	for (int i = n - 1; i > 0; i--)
	{
		result += each_digit[i];
		result *= 10;
	}
	result += each_digit[0];
	return result;
}

int main()
{
	cout << maximumSwap(431223);
	getchar();
	return 0;
}