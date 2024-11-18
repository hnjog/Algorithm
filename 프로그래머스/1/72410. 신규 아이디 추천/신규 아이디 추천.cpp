#include <string>

using namespace std;

string solution(string new_id) {
	string answer = "";

	for (int i = 0; i < new_id.size();i++)
	{
		char c = new_id[i];
		c = tolower(c);

		if (c >= 'a' && c <= 'z' ||
			c >= '0' && c <= '9')
		{
			answer += c;
		}

		if (c == '.')
		{
			if (answer.size() == 0)
				continue;

			if (answer.back() != '.')
			{
				answer += c;
			}
		}

		if (c == '-')
		{
			answer += c;
		}

		if (c == '_')
		{
			answer += c;
		}

	}

	if (answer.empty() == false && 
		answer.back() == '.')
	{
		answer.pop_back();
	}

	if (answer.size() == 0)
	{
		answer = "a";
	}
	else if (answer.size() >= 16)
	{
		answer = string(answer.begin(), answer.begin() + 15);
		if (answer.back() == '.')
		{
			answer.pop_back();
		}
	}

	if (answer.size() <= 2)
	{
		while (answer.size() != 3)
		{
			answer += answer.back();
		}
	}

	return answer;
}