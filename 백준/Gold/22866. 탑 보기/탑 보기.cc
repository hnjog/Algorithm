#include<iostream>
#include<stack>
#include<vector>
#include<unordered_set>
#include<limits.h>

using namespace std;

struct tInfo
{
	int myIdx = 0;
	int myHeight = 0;
	int bestIdx = 0; // 보이는 것 중 가장 가까운 인덱스
	int bestLength = INT_MAX; // bestIdx를 정하기 위한 길이 abs(비교Idx - myIdx)
	int bestRightHeight = 0; // 만난 최고 높이 건물
	int higherCount = 0;

	/*unordered_set<int> lessIdx;
	unordered_set<int> higherIdx;
	unordered_set<int> sameIdx;*/
};

void check(vector<tInfo>& tInfos, tInfo& now)
{
	if (now.myIdx == 0)
		return;

	int nowIdx = now.myIdx;
	int nowHeight = now.myHeight;

	for (int i = nowIdx - 1; i >= 1; i--)
	{
		tInfo& tempI = tInfos[i];

		if (tempI.bestRightHeight < nowHeight)
		{
			tempI.bestRightHeight = nowHeight;
			tempI.higherCount++;

			int len = nowIdx - i;
			if (tempI.bestLength > len)
			{
				tempI.bestIdx = nowIdx;
				tempI.bestLength = len;
			}

			continue;
		}

		if (tempI.myHeight > nowHeight)
		{
			int len = nowIdx - i;
			if (now.bestLength > len)
			{
				now.bestIdx = i;
				now.bestLength = len;
			}

			now.higherCount += tempI.higherCount;
			now.higherCount++;
			break;
		}
		
		now.higherCount = tempI.higherCount;
		if (tempI.bestIdx != 0)
		{
			now.bestIdx = tempI.bestIdx;
			now.bestLength = tempI.bestLength + (nowIdx - tempI.myIdx);
		}

		break;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<tInfo> tInfos(n+1);

	for (int i = 0; i < n; i++)
	{
		tInfos[i + 1].myIdx = i + 1;
		cin >> tInfos[i + 1].myHeight;
		tInfos[i + 1].bestRightHeight = tInfos[i + 1].myHeight;
	}

	for (int i = 1; i <= n; i++)
	{
		check(tInfos, tInfos[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << tInfos[i].higherCount;

		if (tInfos[i].higherCount != 0)
			cout << " " << tInfos[i].bestIdx;

		cout << '\n';
	}

	return 0;
}