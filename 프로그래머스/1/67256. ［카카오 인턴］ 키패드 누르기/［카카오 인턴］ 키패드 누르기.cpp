#include <string>
#include <vector>
#include<queue>

using namespace std;

const int value[4][3] = 
{
	{1,2,3},
	{4,5,6},
	{7,8,9},
	{-1,0,-1}
};

const int dirX[4] = { 0,-1,0,1 };
const int dirY[4] = { -1,0,1,0 };

struct node
{
	int y, x, cost;
};

node dis(int y, int x, int targetV)
{
	queue<node> q;

	q.push({ y,x,0 });

	while (q.empty() == false)
	{
		node n = q.front();
		q.pop();

		if (n.y < 0 || n.y >= 4 ||
			n.x < 0 || n.x >= 3)
			continue;

		if (value[n.y][n.x] == targetV)
		{
			return n;
		}

		for (int i = 0; i < 4; i++)
		{
			q.push({ n.y + dirY[i],n.x + dirX[i],n.cost + 1 });
		}

	}

	return {- 1, -1, -1};
}

string solution(vector<int> numbers, string hand) {
	string answer = "";

	pair<int, int> left = { 3,0 }, right = { 3,2 };

	bool isHandRight = hand == "right" ? true : false;

	for (int n : numbers)
	{
		node leftN = dis(left.first, left.second, n);
		node rightN = dis(right.first, right.second, n);

		if (n == 1 ||
			n == 4 ||
			n == 7)
		{
			answer += 'L';
			left.first = leftN.y;
			left.second = leftN.x;
			continue;
		}
		
		if (n == 3 ||
			n == 6 ||
			n == 9)
		{
			answer += 'R';
			right.first = rightN.y;
			right.second = rightN.x;
			continue;
		}
		

		if (leftN.cost < rightN.cost ||
			(leftN.cost == rightN.cost && isHandRight == false))
		{
			answer += 'L';
			left.first = leftN.y;
			left.second= leftN.x;
		}
		else
		{
			answer += 'R';
			right.first = rightN.y;
			right.second = rightN.x;
		}
	}

	return answer;
}
