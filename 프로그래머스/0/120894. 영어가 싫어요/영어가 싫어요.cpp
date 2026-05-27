#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(string numbers) {
	long long answer = 0;

	unordered_map<string, int> m = {
	{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
	{"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
	};
	
	string temp = "";
	int size = numbers.size();

	for (int i = 0; i < size; i++)
	{
		temp.push_back(numbers[i]);
		if (m.find(temp) != m.end())
		{
			answer *= 10;
			answer += m[temp];
			temp.clear();
		}
	}

	return answer;
}