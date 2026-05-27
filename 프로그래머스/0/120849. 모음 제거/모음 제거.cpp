#include <string>
#include <vector>

using namespace std;

bool checkAEIOU(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
	{
		return true;
	}

	return false;
}

string solution(string my_string) {
	string answer = my_string;

	int size = answer.size();

	for (int i = 0; i < size; i++)
	{
		if (checkAEIOU(answer[i]) == true)
		{
			answer.replace(i, 1, "");
            i--;
		}
	}

	return answer;
}