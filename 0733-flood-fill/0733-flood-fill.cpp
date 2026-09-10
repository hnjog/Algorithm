class Solution {

	const int dirY[4] = { 0,-1,0,1 };
	const int dirX[4] = { -1,0,1,0 };

public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		vector<vector<int>> ret = image;
		int maxh = ret.size();
		int maxw = ret[0].size();

		int oColor = ret[sr][sc];

		queue<pair<int, int>> q;
		q.push({ sr,sc });

		while (q.empty() == false)
		{
			int nowy = q.front().first;
			int nowx = q.front().second;
			q.pop();

			if (nowy < 0 || nowy >= maxh ||
				nowx < 0 || nowx >= maxw)
				continue;

            if (ret[nowy][nowx] == color)
	            continue;

			if (ret[nowy][nowx] != oColor)
				continue;

			ret[nowy][nowx] = color;

			for (int i = 0; i < 4; i++)
			{
				q.push({ nowy + dirY[i],nowx + dirX[i] });
			}
		}

		return ret;
	}
};