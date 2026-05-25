#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int bestV = 0;
    for(int i=0;i<sizes.size();i++)
    {
        int w = sizes[i][0];
        int h = sizes[i][1];
        if(bestV < w)
            bestV = w;
        if(bestV < h)
            bestV = h;
    }
    
    int mValue = min(sizes[0][0],sizes[0][1]);
    
    for(int i=1; i < sizes.size();i++)
    {
        int lessV = min(sizes[i][0],sizes[i][1]);
        if(mValue < lessV)
            mValue = lessV;
    }
    
    return bestV * mValue;
}