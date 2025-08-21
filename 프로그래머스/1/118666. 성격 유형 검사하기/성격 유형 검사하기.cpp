#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int rtSum = 0;
	int cfSum = 0;
	int jmSum = 0;
	int anSum = 0;

	int cSize = choices.size();
	for (int i = 0; i < cSize; i++)
	{
		int cValue = choices[i] - 4;

		if (cValue == 0)
			continue;

		switch (survey[i][0])
		{
		case 'A':
		{
			anSum += cValue;
		}
		break;
		case 'N':
		{
			anSum += (cValue * -1);
		}
		break;
		case 'R':
		{
			rtSum += cValue;
		}
		break;
		case 'T':
		{
			rtSum += (cValue * -1);
		}
		break;
		case 'C':
		{
			cfSum += cValue;
		}
		break;
		case 'F':
		{
			cfSum += (cValue * -1);
		}
		break;
		case 'J':
		{
			jmSum += cValue;
		}
		break;
		case 'M':
		{
			jmSum += (cValue * -1);
		}
		break;
		}
	}

	if (rtSum > 0)
	{
		answer += 'T';
	}
	else
	{
		answer += 'R';
	}

	if (cfSum > 0)
	{
		answer += 'F';
	}
	else
	{
		answer += 'C';
	}

	if (jmSum > 0)
	{
		answer += 'M';
	}
	else
	{
		answer += 'J';
	}

	if (anSum > 0)
	{
		answer += 'N';
	}
	else
	{
		answer += 'A';
	}
    return answer;
}