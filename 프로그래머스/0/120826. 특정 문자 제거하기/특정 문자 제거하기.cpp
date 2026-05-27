#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, string letter) {
	string answer = my_string;

	char ch = letter[0];

	if (answer.find(letter) != string::npos)
	{
		answer.erase(remove(answer.begin(), answer.end(), ch), answer.end());
	}

	return answer;
}