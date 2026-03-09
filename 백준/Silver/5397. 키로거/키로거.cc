#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;

		int as = a.size();

		string b;

		// 커서 앞/뒤쪽 디큐
		deque<char> fq, bq;

		for (int j = 0; j < as; j++)
		{
			char c = a[j];

			switch (c)
			{
			case '<':
			{
				if (fq.empty())
					continue;

				bq.push_front(fq.back());
				fq.pop_back();
			}
			break;
			case '>':
			{
				if (bq.empty())
					continue;

				fq.push_back(bq.front());
				bq.pop_front();
			}
			break;
			case '-':
			{
				if (fq.empty())
					continue;

				fq.pop_back();
			}
			break;
			default:
			{
				fq.push_back(c);
			}
			break;
			}

		}

		while (fq.empty() == false)
		{
			b.push_back(fq.front());
			fq.pop_front();
		}

		while (bq.empty() == false)
		{
			b.push_back(bq.front());
			bq.pop_front();
		}

		cout << b << '\n';
	}

	return 0;
}