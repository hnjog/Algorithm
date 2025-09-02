#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	string str;
	cin >> str;

	string ret = "";
	ret.push_back(str[0]);

	for (int i = 1; i < n; i++)
	{
		// c를 지워가면서 이전 ret의 back 부분과 비교하기
		char c = str[i];

		while (ret.empty() == false)
		{
			if (k > 0 && c > ret.back())
			{
				k--;
				ret.pop_back();
			}
			else
				break;
		}

		ret.push_back(c);
	}

	while (k > 0)
	{
		k--;
		ret.pop_back();
	}

	cout << ret;
}