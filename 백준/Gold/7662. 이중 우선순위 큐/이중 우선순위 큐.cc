#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t > 0)
	{
		int n;
		cin >> n;

		map<int, int> ms;

		for (int i = 0; i < n; i++)
		{
			char c;
			int v;
			cin >> c >> v;

			if (c == 'I')
			{
				ms[v]++;
			}
			else if(ms.empty() == false)
			{
				int tar = 0;
				if (v == 1)
				{
					tar = ms.rbegin()->first;
				}
				else
				{
					tar = ms.begin()->first;
				}

				ms[tar]--;
				if (ms[tar] == 0)
					ms.erase(tar);
			}
		}

		if (ms.empty())
			cout << "EMPTY" << '\n';
		else
			cout << ms.rbegin()->first << " " << ms.begin()->first << '\n';

		t--;
	}


	return 0;
}