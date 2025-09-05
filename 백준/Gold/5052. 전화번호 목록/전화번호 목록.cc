#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class node
{
public:
	node()
	{
		isEnd = false;
	}

	~node()
	{
		for (auto& p : next)
		{
			delete p.second;
		}
	}

	bool isInsert(string& str, int idx)
	{
		if (isEnd)
			return false;

		char c = str[idx];
		int sSize = str.size();

		if (next.find(c) == next.end())
		{
			next[c] = new node();
			next[c]->now = c;
			if (idx == sSize - 1)
			{
				next[c]->isEnd = true;
				return true;
			}
		}

		return next[c]->isInsert(str, idx + 1);
	}
private:
	bool isEnd;
	char now;
	unordered_map<char, node*> next;
};

int main()
{
	int t;
	cin >> t;

	
	while (t > 0)
	{
		int n;
		cin >> n;
		vector<string> strs(n);
		for (int i = 0; i < n; i++)
			cin >> strs[i];

		sort(strs.begin(), strs.end());

		node root;
		bool isSuccess = true;

		for (int i = 0; i < n;i++)
		{
			if (root.isInsert(strs[i], 0) == false)
			{
				isSuccess = false;
				break;
			}
		}

		if (isSuccess)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

		t--;
	}

	return 0;
}