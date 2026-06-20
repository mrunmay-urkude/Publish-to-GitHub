class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int flag=0;//0 mean right 1 mean down 2 mean left 3 means up 
        int count=1;
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        while(count<=n*n){
            if(flag==0){
                for(int i=left;i<=right;i++){
                    ans[top][i]=count++;
                }
                top++;
            }
            if(flag==1){
                for(int i=top;i<=bottom;i++){
                    ans[i][right]=count++;
                }
                right--;
            }
            if(flag==2){
                for(int i=right;i>=left;i--){
                    ans[bottom][i]=count++;
                }
                bottom--;
            }
            if(flag==3){
                for(int i=bottom;i>=top;i--){
                    ans[i][left]=count++;
                }
                left++;
            }
            flag=(flag+1)%4;
        }
        return ans;
    }
};