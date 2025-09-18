#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> crains(n);
	for (int i = 0; i < n; i++)
		cin >> crains[i];

	sort(crains.begin(), crains.end());

	int m;
	cin >> m;
	vector<int> boxs(m);
	for (int i = 0; i < m; i++)
		cin >> boxs[i];

	sort(boxs.begin(), boxs.end());

	if (boxs.back() > crains.back())
	{
		cout << -1;
		return 0;
	}

	vector<int> idxs(n);
	vector<bool> movedBox(m,false);

	int idx = 0;
	for (int i = 0; i < m; i++)
	{
		while(boxs[i] > crains[idx])
		{
			idxs[idx] = i - 1;
			idx++;
		}
	}

	if (idx < n)
	{
		for (int i = idx; i < n; i++)
		{
			idxs[i] = m - 1;
		}
	}

	idxs.back() = m - 1;

	// 무게 무거운 녀석들부터 옮긴다
	int answer = 0;

	while (true)
	{
		bool allComplete = true;

		for (int i = 0; i < n; i++)
		{
			if (idxs[i] == -1)
				continue;

			bool cantMove = false;

			while (movedBox[idxs[i]])
			{
				idxs[i]--;
				if (idxs[i] < 0)
				{
					cantMove = true;
					break;
				}
			}

			if (cantMove)
				continue;

			movedBox[idxs[i]] = true;
			allComplete = false;
		}

		if (allComplete)
			break;

		answer++;
	}

	cout << answer;

	return 0;
}