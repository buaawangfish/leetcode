#include <iostream>
#include <vector>

using namespace std;

int guess(int);

int guessNumber(int n) {
	int left = 0;
	int right = n;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		int flag = guess(mid);
		if (flag == 0)
			return mid;
		else if (flag == -1)
			right = mid - 1;
		else if (flag == 1)
			left = mid + 1;
	}
}

int main()
{
	return 0;
}