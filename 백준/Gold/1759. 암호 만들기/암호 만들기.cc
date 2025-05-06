#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_set>

using namespace std;

const char cs[5] = { 'a','e','i','o','u' };
unordered_set<char> css = { 'a','e','i','o','u' };

int l, c;

void recur(vector<char>& vec,int nowIdx,string& str,int lCount)
{
	// 오름차순으로 정렬되어 있음
	if (str.size() == l)
	{
		unordered_set<char> s(str.begin(), str.end());

		bool isInCs = false;

		for (int i = 0; i < 5; i++)
		{
			if (s.find(cs[i]) != s.end())
			{
				isInCs = true;
				break;
			}
		}

		if(isInCs && lCount >= 2)
			cout << str << '\n';
		return;
	}
	
	for (int i = nowIdx + 1; i < c; i++)
	{
		str += vec[i];
		int lc = 0;
		if (css.find(vec[i]) == css.end())
			lc = 1;
		recur(vec, i, str,lCount + lc);
		str.pop_back();
	}
	
}

int main()
{
	cin >> l >> c;

	vector<char> vec;
	for (int i = 0; i < c; i++)
	{
		char t;
		cin >> t;
		vec.push_back(t);
	}

	sort(vec.begin(), vec.end());

	string temp = "";

	recur(vec, -1, temp,0);
}