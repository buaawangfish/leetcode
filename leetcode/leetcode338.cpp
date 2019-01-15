#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countBits(int num) {
	vector<int> record(num + 1);
	record[0] = 0;
	record[1] = 1;
	for (int i = 2; i <= num; i++)
	{
		if (i % 2 == 0)
		{
			record[i] = record[i / 2];
		}
		else
		{
			record[i] = record[i / 2] + 1;
		}
	}
	return record;
}

int main()
{

}