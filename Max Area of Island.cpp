class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis,int n,int m,int &c)
    {
       if(i<0||j<0||i>=n||j>=m||grid[i][j]==0||vis[i][j])
           return;
        vis[i][j]=1;
        c++;
        int rowNum[] = {-1, 0, 0, 1};
        int colNum[] = {0, -1, 1, 0};
         for (int k = 0; k < 4; k++)
        {
            int row = i + rowNum[k];
            int col = j + colNum[k];
            dfs(row,col,grid,vis,n,m,c);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 int c=0;
                if(!vis[i][j]&&grid[i][j])
                {dfs(i,j,grid,vis,n,m,c);
                 ans=max(ans,c);}
            }
        }
        return ans;
    }
};
