#include<iostream>
#include <vector>
#include <limits.h>
#include <deque>

using namespace std;

vector<vector<int>> horizonWindow(vector<vector<int>>& maps, int w)
{
	vector<vector<int>> temp = maps;

    int my = temp.size();
    int mx = temp[0].size();

    for (int i = 0; i < my; i++)
    {
        deque<int> vd;

        for (int j = 0; j < mx; j++)
        {
            if (vd.empty() == false &&
                vd.front() < j - w + 1)
            {
                vd.pop_front();
            }

            int v = maps[i][j];

            while (vd.empty() == false &&
                maps[i][vd.back()] > v)
            {
                vd.pop_back();
            }

            vd.push_back(j);

            if (j >= w - 1)
            {
                temp[i][j] = maps[i][vd.front()];
            }
        }
    }
    
	return temp;
}

vector<vector<int>> verticalWindow(vector<vector<int>>& maps, int h)
{
    vector<vector<int>> temp = maps;

    int my = temp.size();
    int mx = temp[0].size();

    for (int i = 0; i < mx; i++)
    {
        deque<int> vd;

        for (int j = 0; j < my; j++)
        {
            if (vd.empty() == false &&
                vd.front() < j - h + 1)
            {
                vd.pop_front();
            }

            int v = maps[j][i];

            while (vd.empty() == false &&
                maps[vd.back()][i] > v)
            {
                vd.pop_back();
            }

            vd.push_back(j);

            if (j >= h - 1)
            {
                temp[j][i] = maps[vd.front()][i];
            }
        }
    }

    return temp;
}


vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int> answer;
    vector<vector<int>> maps(m, vector<int>(n, INT_MAX));

    int idx = 1;
    for (const auto& p : drops)
    {
        int y = p[0];
        int x = p[1];

        maps[y][x] = idx;
        idx++;
    }

    vector<vector<int>> temp = horizonWindow(maps, w);
    vector<vector<int>> finalV = verticalWindow(temp, h);

    int maxV = 0;
    int y = 0, x = 0;

    for (int i = h - 1; i < m; i++) 
    {
        for (int j = w - 1; j < n; j++) 
        {
            int val = finalV[i][j];

            if (val == INT_MAX) 
            {
                return { i - h + 1, j - w + 1 };
            }

            if (val > maxV) 
            {
                maxV = val;
                y = i - h + 1;
                x = j - w + 1;
            }
        }
    }

    answer.push_back(y);
    answer.push_back(x);

    return answer;
}