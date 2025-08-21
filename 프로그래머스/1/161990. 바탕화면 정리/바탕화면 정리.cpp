#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int miny = wallpaper.size();
    int maxy = 0;
    int minx = wallpaper[0].size();
    int maxx = 0;

    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[0].size(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                if (i > maxy)
                    maxy = i;
                if (i < miny)
                    miny = i;

                if (j > maxx)
                    maxx = j;
                if (j < minx)
                    minx = j;
            }
        }
    }

    maxy++;
    maxx++;

    answer.push_back(miny);
    answer.push_back(minx);
    answer.push_back(maxy);
    answer.push_back(maxx);

    return answer;
}