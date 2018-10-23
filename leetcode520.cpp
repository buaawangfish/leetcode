#include <iostream>
#include <string>

using namespace std;

bool detectCapitalUse(string word) {
	if (word.size() == 1) return true;
	else
	{
		if (word[0] >= 'a')
		{
			for (int i = 1; i < word.size(); i++)
			{
				if (word[i] <= 'Z') return false;
			}
			return true;
		}
		else
		{
			bool flag = (word[1] >= 'a');
			for (int i = 1; i < word.size(); i++)
			{
				if ((word[i] >= 'a') != flag) return false;
			}
			return true;
		}
	}
}

int main()
{
	cout << detectCapitalUse("USA");
	getchar();
	return 0;
}