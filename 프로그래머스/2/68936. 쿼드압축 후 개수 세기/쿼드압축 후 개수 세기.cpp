#include <vector>

using namespace std;

void quad(const vector<vector<int>>& arr, int startX, int startY, int size, vector<int>& answer)
{
	int startValue = arr[startX][startY];

	if (size == 1)
	{
		answer[startValue]++;
		return;
	}

	bool isSame = true;

	for (int i = startX; i < startX + size; i++)
	{
		for (int j = startY; j < startY + size; j++)
		{
			if (startValue != arr[i][j])
			{
				isSame = false;
				break;
			}
		}

		if (isSame == false)
			break;
	}

	if (isSame)
	{
		answer[startValue]++;
	}
	else
	{
		int qSize = size / 2;
		quad(arr, startX, startY, qSize, answer);
		quad(arr, startX + qSize, startY, qSize, answer);
		quad(arr, startX, startY + qSize, qSize, answer);
		quad(arr, startX + qSize, startY + qSize, qSize, answer);
	}

}

vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer(2, 0);
	quad(arr, 0, 0, arr.size(), answer);
	return answer;
}