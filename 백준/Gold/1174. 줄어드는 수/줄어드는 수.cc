#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

char vs[10] = { '0','1','2','3','4','5','6','7','8','9' };

struct Compare
{
	bool operator()(string& a, string& b)
	{
		if (a.size() == b.size())
			return a > b;
		return a.size() > b.size();
	}
};

int main()
{
	int n;
	cin >> n;

	string temp = "";
	int nowC = 0;
	int idx = 1;

	priority_queue<string, vector<string>, Compare> pq;
	pq.push(temp);

	while (pq.empty() == false)
	{
		string t = pq.top();
		pq.pop();

		if (nowC == n)
		{
			cout << t;
			return 0;
		}

		nowC++;

		if (t.empty())
		{
			for (int i = 0; i < 10; i++)
			{
				pq.push(std::move(vs[i] + t));
			}
		}
		else
		{
			int b = t[0] - '0';
			for (int i = b + 1; i < 10; i++)
			{
				pq.push(std::move(vs[i] + t));
			}
		}
	}

	cout << -1;

	return 0;
}