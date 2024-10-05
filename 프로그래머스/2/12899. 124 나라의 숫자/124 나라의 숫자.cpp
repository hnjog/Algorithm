#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	const char values[3] = { '4','1','2' };

	if (n <= 2)
	{
		answer += values[n];
		return answer;
	}

	vector<char> v;

	while (n > 0)
	{
		int temp = n % 3;
		n /= 3;
		if (temp == 0)
			n--;

		v.push_back(values[temp]);

	}

	for (int i = v.size() - 1; i >=0;i--)
	{
		answer += v[i];
	}

	return answer;
}