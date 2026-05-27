#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
	int answer = 2;
	int s1Size = str1.size();
	int s2Size = str2.size();
	bool isFind = true;

	if (s1Size == s2Size)
	{
		for (int i = 0; i < s1Size; i++)
		{
			if (str1[i] != str2[i])
			{
				isFind = false;
				break;
			}

		}

		if (isFind == true)
		{
			answer = 1;
		}
	}
	else
	{
		for (int i = 0; i <= s1Size - s2Size; i++)
		{
			isFind = true;
			if (str1[i] == str2[0])
			{
				for (int j = 1; j < s2Size; j++)
				{
					if (str1[i + j] != str2[j])
					{
						isFind = false;
						break;
					}
				}

				if (isFind == true)
				{
					answer = 1;
					break;
				}
			}
		}
	}


	return answer;
}