#include<iostream>
#include<vector>

using namespace std;

enum dir
{
	d_Right = 0,
	d_Left,
	d_Up,
	d_Down,
};

int dirY[4] = { 0,0,-1,1 };
int dirX[4] = { 1,-1,0,0 };

int n, m, x, y, k;

class dice
{
public:
	dice(int nowY, int nowX)
	{
		nowPosY = nowY;
		nowPosX = nowX;
	}

	int GetTop() const { return top; }

	bool Roll(vector<vector<int>>& maps, dir d)
	{
		int di = static_cast<int>(d);
		int ny = nowPosY + dirY[di];
		int nx = nowPosX + dirX[di];

		if (ny < 0 || ny >= n ||
			nx < 0 || nx >= m)
			return false;

		// 원본 값들
		int otop = top;
		int odown = down;
		int oright = right;
		int oleft = left;
		int oforward = forward;
		int oback = back;

		switch (d)
		{
		case d_Right: {
			top = oleft;
			right = otop;
			down = oright;
			left = odown;
		}
					break;
		case d_Left: {
			top = oright;
			left = otop;
			down = oleft;
			right = odown;
		}
				   break;
		case d_Up: {
			top = oback;
			back = odown;
			down = oforward;
			forward = otop;
		}
				 break;
		case d_Down: {
			top = oforward;
			forward = odown;
			down = oback;
			back = otop;
		}
				   break;
		}

		if (maps[ny][nx] != 0)
		{
			down = maps[ny][nx];
			maps[ny][nx] = 0;
		}
		else
		{
			maps[ny][nx] = down;
		}
		
		nowPosY = ny;
		nowPosX = nx;

		return true;
	}

protected:
	int nowPosY, nowPosX;

	int top = 0;
	int down = 0;
	int right = 0;
	int left = 0;
	int forward = 0;
	int back = 0;
};

int main()
{
	cin >> n >> m >> y >> x >> k;

	vector<vector<int>> maps(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> maps[i][j];

	dice dic(y, x);

	for (int i = 0; i < k; i++)
	{
		int ord;
		cin >> ord;
		ord--;
		if (dic.Roll(maps, static_cast<dir>(ord)))
		{
			cout << dic.GetTop() << '\n';
		}
	}

	return 0;
}