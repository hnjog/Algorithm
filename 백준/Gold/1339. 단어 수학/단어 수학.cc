#include<iostream>
#include<string>
#include<unordered_map>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	unordered_map<char, int> valueMap;
	vector<string> vec;

	int n;
	cin >> n;

	while (n > 0)
	{
		string a;
		cin >> a;
		vec.push_back(a);

		int aSize = a.size();

		for (int i = 0; i < aSize; i++)
		{
			valueMap[a[i]] += pow(10, aSize - i - 1);
		}
		n--;
	}
	
	vector<pair<char, int>> valuev(valueMap.begin(), valueMap.end());
	sort(valuev.begin(), valuev.end(), [](const pair<char, int>& a, const pair<char, int>& b) 
		{
			return a.second > b.second;
		});

	int now = 9;
	unordered_map<char, int> mapping;
	for (auto& a : valuev)
	{
		mapping[a.first] = now;
		now--;
	}

	int sum = 0;

	for (auto& a : vec)
	{
		int v = 0;

		for (char c : a)
		{
			v *= 10;
			v += mapping[c];
		}

		sum += v;
	}

	cout << sum;

	return 0;
}