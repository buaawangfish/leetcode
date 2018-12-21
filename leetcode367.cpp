#include <iostream>
#include <vector>

using namespace std;

bool isPerfectSquare(int num) {
	if (num < 0) return false;
	int right = 1;
	int temp = num;
	while (temp > 0)
	{
		temp /= 100;
		right *= 10;
	}
	int left = 0;
	int cnt = 0;
	right = right > 46341 ? 46341 : right;
	while (left <= right)
	{
		cout << "cnt: " << cnt << endl;
		cout << "left: " << left << " right: " << right << endl;
		int mid = left + (right - left) / 2;
		cout << "mid: " << mid << endl;
		int mid_square = mid * mid;
		cout << "mid_square: " << mid_square << endl << endl;
		if (mid_square == num)
			return true;
		else if (mid_square < num)
			left = mid + 1;
		else
			right = mid - 1;			
	}
	return false;
}

int main()
{
	cout << isPerfectSquare(2147395600);
	getchar();
	return 0;
}