#include <string>
#include <vector>
#include <math.h>
#include<algorithm>

using namespace std;

string solution(string bin1, string bin2) {
	string answer = "";

	int b1 = 0, b2 = 0;
	int s1 = bin1.size(), s2 = bin2.size();

	for (int i = s1 - 1; i >= 0; i--)
	{
		b1 += (pow(2,i) * static_cast<int>(bin1[s1 - i - 1] - '0'));
	}

	for (int i = s2 - 1; i >= 0; i--)
	{
		b2 += (pow(2, i) * static_cast<int>(bin2[s2 - i - 1] - '0'));
	}

	int rb = b1 + b2;

	while (true)
	{
		if (rb % 2 == 1)
		{
			answer += "1";
			rb--;
		}
		else
		{
			answer += "0";
		}

		rb /= 2;

		if (rb == 0)
		{
			break;
		}
	}

	reverse(answer.begin(), answer.end());

	return answer;
}