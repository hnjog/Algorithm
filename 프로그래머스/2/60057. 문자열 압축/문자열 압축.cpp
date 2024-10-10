#include <string>
#include<vector>

using namespace std;

int solution(string s) {
	int sSize = s.size();
	int answer = sSize;

	for (int numSize = 1; numSize <= sSize / 2; numSize++)
	{
		vector<pair<string, int>> sVec;
		string temp = "";
		int count = 0;

		for (int i = 0; i < sSize; i++)
		{
			temp += s[i];
			count++;

			if (count == numSize)
			{
				if (sVec.empty() == false &&
					sVec.back().first == temp)
				{
					sVec.back().second++;
				}
				else
				{
					sVec.push_back({ temp,1 });
				}
				count = 0;
				temp = "";
			}
		}

		int stringSize = count;

		for (const auto& data : sVec)
		{
			stringSize += numSize;
			
			if (data.second != 1)
			{
				int idx = 1;
				int len = 1;

				while (idx * 10 <= data.second)
				{
					idx *= 10;
					len++;
				}

				stringSize+= (len);
			}
		}

		if (stringSize < answer)
		{
			answer = stringSize;
		}
	}

	return answer;
}