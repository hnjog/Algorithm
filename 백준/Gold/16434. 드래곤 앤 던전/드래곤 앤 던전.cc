#include<iostream>
#include<vector>
#include<limits.h>
#include<math.h>

using namespace std;

int n;
long long heroBaseAttack;

bool isSuccess(vector<vector<long long>>& dInfos, long long heroBaseHp)
{
	long long currentHp = heroBaseHp;
	long long currentAttack = heroBaseAttack;

	for (auto& room : dInfos)
	{
		int type = room[0];

		if (type == 1)
		{
			long long eAt = room[1];
			long long eHp = room[2];

			long long t = ceil(eHp / (long double)currentAttack);
			if (currentHp <= (t - 1) * eAt)
				return false;

			currentHp -= (t - 1) * eAt;
		}
		else
		{
			currentAttack += room[1];
			
			if (currentHp < heroBaseHp)
			{
				long long amount = heroBaseHp - currentHp;
				if (room[2] >= amount)
					currentHp = heroBaseHp;
				else
					currentHp += room[2];
			}

		}
	}

	return true;
}

int main()
{
	cin >> n;
	cin >> heroBaseAttack;

	vector<vector<long long>> dInfos(n, vector<long long>(3));

	for (int i = 0; i < n; i++)
	{
		cin >> dInfos[i][0];
		cin >> dInfos[i][1];
		cin >> dInfos[i][2];
	}

	long long left = 1;
	long long right = LLONG_MAX;

	while (left < right)
	{
		long long mid = (left + right) / 2;

		if (isSuccess(dInfos, mid))
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << left;

	return 0;
}