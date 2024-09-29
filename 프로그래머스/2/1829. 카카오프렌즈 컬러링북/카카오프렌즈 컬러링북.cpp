#include <vector>
#include<unordered_set>
#include<queue>

using namespace std;

int search(int y, int x, const vector<vector<int>>& picture, vector<vector<bool>>& visited, int& count)
{
	const int dirX[4] = { -1,0,1,0 };
	const int dirY[4] = { 0,-1,0,1 };

	// 0은 영역이 없는 것이다
	if (picture[y][x] == 0)
		return 0;

	// 이미 계산됨
	if (visited[y][x] == true)
		return 0;

	int now = picture[y][x];

	queue<pair<int, int>> q;
	q.push({ y,x });

	const int limitY = picture.size();
	const int limitX = picture[0].size();

	int result = 0;
	count++;

	while (q.empty() == false)
	{
		auto p = q.front();
		q.pop();

		int nowY = p.first;
		int nowX = p.second;

		if (nowY < 0 || nowY >= limitY ||
			nowX < 0 || nowX >= limitX)
			continue;

		if (picture[nowY][nowX] != now)
			continue;
		
		if (visited[nowY][nowX])
			continue;

		visited[nowY][nowX] = true;
		result++;

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dirY[i];
			int nextX = nowX + dirX[i];

			q.push({ nextY,nextX });
		}
	}

	return result;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int pSize = picture.size();
	int pSize2 = picture[0].size();

	vector<vector<bool>> visited(pSize, vector<bool>(pSize2, false));

	int maxV = 0;
	int count = 0;

	for (int i = 0; i < pSize; i++)
	{
		for (int j = 0; j < pSize2; j++)
		{
			int v = search(i, j, picture, visited,count);
			if (maxV < v)
				maxV = v;
		}
	}

	vector<int> answer(2);
	answer[0] = count;
	answer[1] = maxV;

	return answer;
}