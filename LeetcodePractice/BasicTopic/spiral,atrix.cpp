class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int r=matrix.size();
        int c=matrix[0].size();
        int srow=0,erow=r-1,scol=0,ecol=c-1;
        while(srow<=erow && scol<=ecol){
            for(int i =scol;i<=ecol;i++){
                ans.push_back(matrix[srow][i]);
            }
            for(int i =srow+1;i<=erow;i++){
                ans.push_back(matrix[i][ecol]);
            }for(int i =ecol-1;i>=scol;i--){
                if(erow==srow){
                    break;
                }
                ans.push_back(matrix[erow][i]);
            }for(int i =erow-1;i>srow;i--){
                if(scol==ecol){
                    break;
                }
                ans.push_back(matrix[i][scol]);
            }
            srow++;
            scol++;
            erow--;
            ecol--;
        }
        return ans;
    }
};