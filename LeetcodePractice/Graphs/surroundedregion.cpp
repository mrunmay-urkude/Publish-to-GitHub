class Solution {
public:
    void solve(vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();
        vector<vector<char>>ans(m,vector<char>(n,'X'));
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    && board[i][j] == 'O') {
                    q.push({i, j});
                    visited[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            ans[x][y]='O';
            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,-1,1};
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0&&newy>=0&&newx<m&&newy<n&&!visited[newx][newy]&&board[newx][newy]=='O'){
                    q.push({newx,newy});
                    visited[newx][newy]=true;
                }
            }
        }
        board=ans;
    }
};