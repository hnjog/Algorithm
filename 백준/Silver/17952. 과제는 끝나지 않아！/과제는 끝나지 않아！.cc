#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int sum = 0;
	struct vt
	{
		int value;
		int remainTime;
	};

	vector<vt> remains;
	remains.reserve(n);

	for (int i = 0; i < n; i++)
	{
		int q;
		cin >> q;
		if (q == 1)
		{
			int v, r;
			cin >> v >> r;
			r--;
			if (r == 0)
			{
				sum += v;
			}
			else
			{
				remains.emplace_back(vt{ v,r });
			}
		}
		else
		{
			if (remains.size() > 0)
			{
				remains.back().remainTime--;
				if (remains.back().remainTime == 0)
				{
					sum += remains.back().value;
					remains.pop_back();
				}
			}
		}
	}

	cout << sum;

	return 0;
}