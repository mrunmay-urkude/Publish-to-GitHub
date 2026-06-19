class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m= mat.size();
        int n=mat[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        vector<vector<int>>ans(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    visited[i][j]=true;
                }
            }
        }
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            int steps=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            ans[x][y]=steps;
            q.pop();
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0&&newy>=0&&newx<m&&newy<n&&!visited[newx][newy]){
                    q.push({steps+1,{newx,newy}});
                    visited[newx][newy]=true;
                }
            }
        }
        return ans;
    }
};