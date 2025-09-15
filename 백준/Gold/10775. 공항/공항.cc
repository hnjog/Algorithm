#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
	int g, p;
	cin >> g >> p;

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> airports(g + 1);
	unordered_map<int, int> checkMap; // 게이트 번호, 가장 마지막에 탐색한 번호

	int answer = 0;

	for (int i = 1; i <= p; i++)
	{
		int t;
		cin >> t;
		bool isSet = false;

		if (checkMap.find(t) == checkMap.end() &&
			airports[t] == 0)
		{
			answer++;
			airports[t] = t;
			checkMap[t] = t;
		}
		else
		{
			int lastFind = checkMap[t];
			if (lastFind == 0)
				lastFind = t;

			for (int j = lastFind - 1; j >= 1; j--)
			{
				if (airports[j] == 0)
				{
					airports[j] = i;
					checkMap[t] = j;
					isSet = true;
					break;
				}
			}

			if (isSet)
				answer++;
			else
				break;
		}

	}

	cout << answer;

	return 0;
}