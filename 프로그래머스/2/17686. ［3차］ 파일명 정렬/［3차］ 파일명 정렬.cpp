#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<string> solution(vector<string> files) {
	stable_sort(files.begin(), files.end(), [](const string& a, const string& b)
		{
			string headA = "", numberA = "", headB = "", numberB = "";

			bool isHeadCheck = true;
			for (const char c : a)
			{
				if (c >= '0' && c <= '9')
				{
					isHeadCheck = false;
					numberA += c;
					if (numberA.size() >= 5)
						break;
				}
				else if (isHeadCheck == true)
				{
					headA += toupper(c);
				}
				else
				{
					break;
				}
			}

			isHeadCheck = true;
			for (const char c : b)
			{
				if (c >= '0' && c <= '9')
				{
					isHeadCheck = false;
					numberB += c;
					if (numberB.size() >= 5)
						break;
				}
				else if (isHeadCheck == true)
				{
					headB += toupper(c);
				}
				else
				{
					break;
				}
			}

			if (headA != headB)
			{
				int shortLen = min(headA.size(), headB.size());

				for (int i = 0; i < shortLen; i++)
				{
					if (headA[i] == headB[i])
						continue;

					return headA[i] < headB[i];
				}

				return headA.size() < headB.size();
			}

			int nA = stoi(numberA);
			int nB = stoi(numberB);

			if (nA != nB)
			{
				return nA < nB;
			}

			return false;
		});


    return files;
}