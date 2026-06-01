#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

int GetMaxValue(string& str, int remainCount, unordered_set<string>& us)
{
	string text = str + "_" + to_string(remainCount);

	if (us.find(text) != us.end())
	{
		return -1;
	}

	us.insert(text);

	if (remainCount == 0)
	{
		return stoi(str);
	}

	int ret = -1;
	int n = str.size();
	string origin = str;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			swap(str[i], str[j]);
			ret = max(ret, GetMaxValue(str, remainCount - 1,us));
			swap(str[i], str[j]);
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> str;
		int num;
		cin >> num;

		unordered_set<string> us;

		cout << '#' << test_case << ' ' << GetMaxValue(str, num,us) << '\n';
	}
	return 0;
}