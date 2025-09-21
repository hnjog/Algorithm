#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int answer = 0;
	queue<pair<int, char>> aq, bq, cq;

	for (int i = 0; i < str.size(); i++)
	{
		char c = str[i];

		if (c == 'C')
		{
			cq.push({ i,c });
		}
		else if (c == 'B')
			bq.push({ i,c });
		else
			aq.push({ i,c });
	}

	if (cq.size() > 0 &&
		bq.size() > 0)
	{
		while (cq.empty() == false &&
			bq.empty() == false)
		{
			if (bq.front().first < cq.front().first)
			{
				answer++;
				cq.pop();
				bq.pop();
			}
			else
			{
				cq.pop();
			}
		}
	}

	if (bq.size() > 0 &&
		aq.size() > 0)
	{
		while (aq.empty() == false &&
			bq.empty() == false)
		{
			if (aq.front().first < bq.front().first)
			{
				answer++;
				aq.pop();
				bq.pop();
			}
			else
			{
				bq.pop();
			}
		}
	}

	cout << answer;
}