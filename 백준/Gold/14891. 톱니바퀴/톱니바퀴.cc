#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int getValue(vector<vector<int>>& vv, vector<int>& iv)
{
	int res = 0;

	for (int i = 0; i < 4; i++)
	{
		if (vv[i][iv[i]] == 1)
		{
			res += pow(2, i);
		}
	}

	return res;
}

int getRightIndex(int idx, int value)
{
	int ret = idx + value;
	if (ret >= 8)
		ret %= 8;
	else if (ret < 0)
		ret = 8 + ret;

	return ret;
}

int getLeftValue(vector<vector<int>>& vv, int gearNum, int startIdx)
{
	int tIdx = getRightIndex(startIdx, -2);
	return vv[gearNum][tIdx];
}

int getRightValue(vector<vector<int>>& vv, int gearNum, int startIdx)
{
	int tIdx = getRightIndex(startIdx, 2);
	return vv[gearNum][tIdx];
}

void Spin(vector<vector<int>>& vv, vector<int>& iv, int nowGear, int dir, bool bRight)
{
	if (nowGear >= 4 || nowGear < 0)
		return;

	if (bRight)
	{
		if (nowGear < 3 &&
			getRightValue(vv, nowGear, iv[nowGear]) != getLeftValue(vv, nowGear + 1, iv[nowGear + 1]))
		{
			Spin(vv, iv, nowGear + 1, -dir, bRight);
		}
	}
	else
	{
		if (nowGear > 0 &&
			getLeftValue(vv, nowGear, iv[nowGear]) != getRightValue(vv, nowGear - 1, iv[nowGear - 1]))
		{
			Spin(vv, iv, nowGear - 1, -dir, bRight);
		}
	}

	iv[nowGear] = getRightIndex(iv[nowGear], dir);
}

void StartSpin(vector<vector<int>>& vv, vector<int>& iv, int nowGear, int dir)
{
	if (nowGear < 3 &&
		getRightValue(vv, nowGear, iv[nowGear]) != getLeftValue(vv, nowGear + 1, iv[nowGear + 1]))
		Spin(vv, iv, nowGear + 1, -dir, true);

	if (nowGear > 0 &&
		getLeftValue(vv, nowGear, iv[nowGear]) != getRightValue(vv, nowGear - 1, iv[nowGear - 1]))
		Spin(vv, iv, nowGear - 1, -dir, false);

	iv[nowGear] = getRightIndex(iv[nowGear], dir);
}

int main()
{
	// 시작 위치를 가리키는 녀석을 기준으로 순회하는 것을 추천함
	// 그리고 시작 위치만 이동시키면 비교할 수 있음
	vector<vector<int>> valueVec;
	for (int i = 0; i < 4; i++)
	{
		valueVec.push_back(vector<int>());
		string t;
		cin >> t;
		for (int j = 0; j < 8; j++)
		{
			valueVec[i].push_back(t[j] - '0');
		}
	}

	int t;
	cin >> t;
	vector<int> topIdx(4, 0);
	while (t > 0)
	{
		int gearNum, dir;
		cin >> gearNum >> dir;
		gearNum--;
		StartSpin(valueVec, topIdx, gearNum, -dir);

		t--;
	}

	cout << getValue(valueVec, topIdx);

	return 0;
}