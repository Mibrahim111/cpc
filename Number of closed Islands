#include <bits/stdc++.h>
using namespace std;


class Solution
{
    bool closed{};
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    bool isValid(const vector<vector<int>>& grid, int x,int y)
    {
        return x >= 0 && y >= 0 && x < (int)grid.size() && y < (int)grid[0].size();
    }

    void DFS(const vector<vector<int>> & grid, int x,int y, vector<vector<bool>> &vis)
    {
        if(vis[x][y])
            return;
        vis[x][y] = 1;

        for(int i = 0 ; i<4 ; i++)
        {
            int xc = x +dx[i],
                yc = y +dy[i];
            if(!isValid(grid,xc,yc))
            {
                closed = false;
                continue;
            }
            if(!grid[xc][yc])
                DFS(grid,xc,yc,vis);
        }

    }

public:
    int closedIsland(vector<vector<int>>& grid)
    {
        int M = (int)grid[0].size(), N = (int)grid.size();
        int ans = 0;
        vector<vector<bool>> vis(N,vector<bool>(M,0));

        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < M ; j++)
            {

                if(!vis[i][j]&&!grid[i][j])
                {
                    closed = true;
                    DFS(grid,i,j,vis);
                    if(closed)
                        ans++;
                }
            }
        }
        return ans;
    }
};
