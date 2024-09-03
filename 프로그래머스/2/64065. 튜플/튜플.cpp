#include <string>
#include <vector>
#include<map>
#include<algorithm>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	map<int, int> m;

	int beforeNum = -1;

	for (char c : s)
	{
		switch (c)
		{
		case '{':
		case ',':
		{
			if (beforeNum != -1)
				m[beforeNum]++;

			beforeNum = -1;
		}
		break;
		case '}':
		{
			if (beforeNum != -1)
			{
				m[beforeNum]++;
			}
			beforeNum = -1;
		}
		break;
		default: // 숫자
		{
			int v = int(c - '0');

			if (beforeNum != -1)
			{
				beforeNum *= 10;
                beforeNum += v;
			}
			else
			{
				beforeNum = v;
			}
		}
		break;
		}
	}

	vector<pair<int, int>> pv(m.begin(), m.end());

	sort(pv.begin(), pv.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.second == b.second)
			return a.first > b.first;

		return a.second > b.second;
		});

	for (const auto& p : pv)
	{
		answer.push_back(p.first);
	}

	return answer;
}