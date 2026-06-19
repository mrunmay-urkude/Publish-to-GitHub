class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||j==0||i==m-1||j==n-1)&&grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int x= q.front().first;
            int y= q.front().second;
            grid[x][y]=0;
            q.pop();
            int dx[4]={0,1,0,-1};
            int dy[4]={1,0,-1,0};
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0&&newy>=0&&newx<m&&newy<n&&grid[newx][newy]==1&&!visited[newx][newy]){
                    q.push({newx,newy});
                    visited[newx][newy]=true;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)count++;
            }
        }
        return count;
    }
};