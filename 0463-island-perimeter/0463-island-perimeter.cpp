class Solution {
    const int dirY[4] = {0,-1,0,1};
    const int dirX[4] = {-1,0,1,0};

    typedef pair<int,int> pii;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pii> q;
        int height = grid.size();
        int width = grid[0].size();

        vector<vector<bool>> visited(height,vector<bool>(width,false));

        int ret =0;

        pii start;
        bool bfind = false;
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(grid[i][j] == 1)
                {
                    start.first = i;
                    start.second = j;
                    bfind = true;
                    break;
                }
            }

            if(bfind)
                break;
        }

        q.push(start);
        while(q.empty() == false)
        {
            int ny = q.front().first;
            int nx = q.front().second;
            q.pop();

            if(visited[ny][nx])
                continue;
            visited[ny][nx] = true;

            int val = 4;

            for(int i=0;i<4;i++)
            {
                int nny = ny + dirY[i];
                int nnx = nx + dirX[i];
                if(nny < 0 || nny >= height ||
                    nnx < 0 || nnx >= width)
                    continue;
                
                if(grid[nny][nnx] == 1)
                {
                    val -= 1;
                    q.push({nny,nnx});
                }
            }

            ret += val;
        }
        return ret;
    }
};