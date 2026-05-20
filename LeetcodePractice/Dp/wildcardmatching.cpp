basic recursive

class Solution {
public:
    bool boom(string &s, string &p,int i , int j ){
        if(i<0&&j<0)return true;
        if(j<0&&i>=0)return false;
        if(i<0&&j>=0){
            for(int k=0;k<j;k++){
                if(p[k]!='*')return false;
            }
            return true;
        }

        if(s[i]==p[j]||p[j]=='?')return boom(s,p,i-1,j-1);
        if(p[j]=='*')return boom(s,p,i-1,j)||boom(s,p,i,j-1);
        return false;
    }
    bool isMatch(string s, string p) {
        return boom(s,p,s.size()-1,p.size()-1);
    }
};

memoized

class Solution {
public:
    bool boom(string &s, string &p,int i , int j,vector<vector<bool>>&dp ){
        if(i<0&&j<0)return true;
        if(j<0&&i>=0)return false;
        if(i<0&&j>=0){
            for(int k=0;k<j;k++){
                if(p[k]!='*')return false;
            }
            return true;
        }
        if(dp[i][j])return dp[i][j];
        if(s[i]==p[j]||p[j]=='?')return dp[i][j]= boom(s,p,i-1,j-1,dp);
        if(p[j]=='*')return dp[i][j]= boom(s,p,i-1,j,dp)||boom(s,p,i,j-1,dp);
        return dp[i][j]= false;
    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<bool>>dp(m,vector<bool>(n,false));
        return boom(s,p,s.size()-1,p.size()-1,dp);
    }
};


shifting of index 
class Solution {
public:
    bool boom(string &s, string &p,int i , int j,vector<vector<bool>>&dp ){
        if(i==0&&j==0)return true;
        if(j==0&&i>0)return false;
        if(i==0&&j>0){
            for(int k=0;k<j;k++){
                if(p[k]!='*')return false;
            }
            return true;
        }
        if(dp[i][j])return dp[i][j];
        if(s[i-1]==p[j-1]||p[j-1]=='?')return dp[i][j]= boom(s,p,i-1,j-1,dp);
        if(p[j-1]=='*')return dp[i][j]= boom(s,p,i-1,j,dp)||boom(s,p,i,j-1,dp);
        return dp[i][j]= false;
    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        return boom(s, p, m, n, dp);
    }
};

tabulated

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1,vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int j = 1; j <= n; j++) {
            bool flag = true;
            for(int k = 1; k <= j; k++) {
                if(p[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == p[j-1]||p[j-1] =='?'){
                    dp[i][j] =dp[i-1][j-1];
                }
                else if(p[j-1] =='*'){
                    dp[i][j] =dp[i-1][j]||dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};


two 1d array optimzied
 
    class Solution {
    public:
        bool isMatch(string s, string p) {
            int m = s.size();
            int n = p.size();
            vector<bool> prev(n+1,false);
            prev[0] = true;
            for(int j = 1; j <= n; j++) {
                bool flag = true;
                for(int k = 1; k <= j; k++) {
                    if(p[k-1] != '*') {
                        flag = false;
                        break;
                    }
                }
                prev[j] = flag;
            }
            for(int i = 1; i <= m; i++) {
                vector<bool> curr(n+1,false);
                for(int j = 1; j <= n; j++) {
                    if(s[i-1] == p[j-1]||p[j-1] =='?'){
                        curr[j] =prev[j-1];
                    }
                    else if(p[j-1] =='*'){
                        curr[j] =prev[j]||curr[j-1];
                    }
                    else{
                        curr[j] = false;
                    }
                }
                prev=curr;
            }
            return prev[n];
        }
    };
