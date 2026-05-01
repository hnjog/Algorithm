#include <vector>

using namespace std;

bool isYellowTime(vector<int>& signal, int time)
{
	int g = signal[0], y = signal[1], r = signal[2];

	int t = time % (g + y + r);

	if (t <= g)
		return false;

	if (t > y + g)
		return false;

	return true;
}

int solution(vector<vector<int>> signals) {
	int answer = -1;

	int time = 0;
	int mTime = 20 * 20 * 20 * 20 * 20;
	int ss = signals.size();

	while (time < mTime)
	{
		time++;

		bool bAllYellow = true;

		for (vector<int>& s : signals)
		{
			if (isYellowTime(s, time) == false)
			{
				bAllYellow = false;
				break;
			}
		}

		if (bAllYellow)
		{
			answer = time;
			break;
		}
	}
	
	return answer;
}