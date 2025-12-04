#include<iostream>
#include<vector>

using namespace std;

int main()
{
	// dp[i] : i 무게가 가능한가?
	// maxs - i 를 통해 다른 팀의 무게 구할 수 있음
	// 
	// abs(max - 2i)를 체크해
	// i와 max - i를 작은 순서대로 출력하면 됨
	// 
	// 절반이 가능한지 체크하기? - 음...
	// 
	// 두 팀의 사람 수 차이가 1이하 여야 함
	// (같거나 1명 차이)
	// 
	// 이러면 단순 사람 무게 비교로는 힘들듯?
	// 
	// n/2 를 이용해야 할 것 같기도?
	// 
	// dp[i][j] : i명째에 j값이 가능한지?
	// 
	//

	int n;
	cin >> n;

	int maxx = 0;
	vector<int> weis(n);
	for (int i = 0; i < n; i++)
	{
		cin >> weis[i];
		maxx += weis[i];
	}

	vector<vector<bool>> dp(n / 2 + 1, vector<bool>(maxx + 1, false));
	dp[0][0] = true;

	for (int i = 0; i < n; i++)
	{
		int nowW = weis[i];
		for (int count = n / 2; count >= 1; count--)
		{
			for (int j = maxx; j >= nowW; j--)
			{
				if (dp[count - 1][j - nowW] == false)
					continue;

				dp[count][j] = true;
			}
		}
	}

	int minV = 1e9;
	pair<int, int> vv;

	for (int i = 0; i <= maxx; i++)
	{
		if (dp[n / 2][i] == false)
			continue;

		int v = abs(maxx - 2 * i);
		if (v < minV)
		{
			minV = v;

			int a = i;
			int b = maxx - i;

			if (a > b)
				swap(a, b);

			vv.first = a;
			vv.second = b;
		}
	}

	cout << vv.first << ' ' << vv.second;

	return 0;
}