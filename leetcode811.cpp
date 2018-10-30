#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> subdomainVisits(vector<string>& cpdomains) {
	if (cpdomains.empty()) return vector<string>();

	vector<string> res;
	unordered_map<string, int> hash_map;
	for (auto cpdomain : cpdomains)
	{
		vector<string> domain_layer;
		auto idx = find(cpdomain.begin(), cpdomain.end(), ' ');
		int cnt = stoi(string(cpdomain.begin(), idx));
		string domain(idx + 1, cpdomain.end());
		hash_map[domain] += cnt;
		idx = find(domain.begin(), domain.end(), '.');
		while (idx != domain.end())
		{
			domain = string(idx + 1, domain.end());
			idx = find(domain.begin(), domain.end(), '.');
			hash_map[domain] += cnt;
		}
	}
	for (auto pair : hash_map)
	{
		string each = to_string(pair.second) + ' ' + pair.first;
		res.push_back(each);
	}
	return res;
}

int main()
{
	/*
	unordered_map<string, int> hash_map;
	hash_map["haha"] += 1;
	for (auto pair : hash_map)
	{
	cout << pair.first << ' ' << pair.second << endl;
	}*/
	vector<string> input{ "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
	vector<string> output = subdomainVisits(input);
	for (auto x : output)
	{
		cout << x << endl;
	}
	getchar();
	return 0;
}