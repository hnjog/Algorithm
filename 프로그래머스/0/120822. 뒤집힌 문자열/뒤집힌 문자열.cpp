#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
	string answer = my_string;
	
	int strSize = my_string.size();

	int j = 0;

	for (int i = strSize - 1; i >= 0; i--)
	{
		answer[j] = my_string[i];
		j++;
	}

	return answer;
}