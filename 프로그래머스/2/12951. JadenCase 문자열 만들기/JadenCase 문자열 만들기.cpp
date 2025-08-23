#include <string>

using namespace std;

string solution(string s) {
	string answer = "";
	bool isFirst = true;
	for (auto c : s)
	{
		if (isFirst &&
			c >= 'a' &&
            c <= 'z')
		{
			c -= 32;

			isFirst = false;
		}
        else if (isFirst == false &&
            c >= 'A' &&
                 c <= 'Z')
        {
            c += 32;
            isFirst = false;
        }
		else if (c == ' ')
		{
			isFirst = true;
		}
		else
		{
			isFirst = false;
		}

		answer += c;
	}

	return answer;
}