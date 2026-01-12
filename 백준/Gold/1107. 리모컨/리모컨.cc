#include<iostream>
#include<vector>
#include<string>
#include<limits.h>

using namespace std;

void getSeam(int target,const vector<bool>& buttons, int nowV, int nowC,const int baseC, int& ret)
{
	if (nowC == baseC)
	{
		if (nowC != 0)
			ret = min(ret, abs(target - nowV));
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (buttons[i] == false)
			continue;

		getSeam(target, buttons, nowV * 10 + i, nowC + 1, baseC, ret);
	}
}

void getSeam2(int target, const vector<bool>& buttons, int nowV, int nowC, const int baseC, int& ret)
{
	if (nowC == baseC - 1)
	{
		if(nowC != 0)
			ret = min(ret, abs(target - nowV));
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (buttons[i] == false)
			continue;

		getSeam2(target, buttons, nowV * 10 + i, nowC + 1, baseC, ret);
	}
}

void getSeam3(int target, const vector<bool>& buttons, int nowV, int nowC, const int baseC, int& ret)
{
	if (nowC == baseC + 1)
	{
		if (nowC != 0)
			ret = min(ret, abs(target - nowV));
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (buttons[i] == false)
			continue;

		getSeam3(target, buttons, nowV * 10 + i, nowC + 1, baseC, ret);
	}
}

int main()
{
	// 이동방식
	// - 가능한 근처 버튼으로 이동?
	//   (다만 이 때, 사용할 수 있는 버튼을 확인해야 함)
	//   (그 윗값에서 빼는게 더 빠를 수 있음...)
	// 
	// 생각해보기
	// 1. target 보다 한자릿수 위에서 찾기
	// 2. 한자릿수 아래에서 찾기
	// 
	// 3. buttons에서 같은 자릿수에서 가까운 값을 만들어서
	//    target 값에서 뺀 절댓값 찾기
	// 
	// 4. 시작값에서 target 빼준 절댓값
	// 
	// 이중 가장 작은값을 선택

	int nowNum = 100;
	int target;
	cin >> target;

	vector<bool> buttons(10, true);
	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		buttons[t] = false;
	}

	int baseC = to_string(target).size();
	int ret1 = 1e9;
	int ret2 = 1e9;
	int ret3 = 1e9;

	getSeam(target, buttons, 0, 0, baseC, ret1);
	getSeam2(target, buttons, 0, 0, baseC, ret2);
	getSeam3(target, buttons, 0, 0, baseC, ret3);

	int bV = abs(100 - target);
	int sv1 = ret1 + baseC;
	int sv2 = ret2 + baseC - 1;
	int sv3 = ret3 + baseC + 1;

	int v = min(bV, sv1);
	v = min(sv1, v);
	v = min(sv2, v);
	v = min(sv3, v);

	cout << v;

	return 0;
}