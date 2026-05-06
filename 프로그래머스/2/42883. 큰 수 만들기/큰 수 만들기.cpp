#include <string>
#include <queue>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for (char c : number)
    {
		while (answer.empty() == false &&
			answer.back() < c &&
			k > 0)
		{
			answer.pop_back();
			k--;
		}

		answer.push_back(c);
    }

	while (k > 0)
	{
		answer.pop_back(); 
		k--;
	}

    return answer;
}