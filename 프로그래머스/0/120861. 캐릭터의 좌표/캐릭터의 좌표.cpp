#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
	vector<int> answer = { 0,0 };

	int limitX = board[0] / 2;
	int limitY = board[1] / 2;

	int operSize = keyinput.size();
	for (int i = 0; i < operSize; i++)
	{
		if (keyinput[i] == "left" && answer[0] > -limitX)
			answer[0] -= 1;
		else if (keyinput[i] == "right" && answer[0] < limitX)
			answer[0] += 1;

		if (keyinput[i] == "down" && answer[1] > -limitY)
			answer[1] -= 1;
		else if (keyinput[i] == "up" && answer[1] < limitY)
			answer[1] += 1;

	}

	return answer;
}