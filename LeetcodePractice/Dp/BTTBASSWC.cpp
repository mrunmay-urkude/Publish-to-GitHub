class Solution {
public:
    int profits(vector<int>& prices,int index, int buy,int cooldown,vector<vector<vector<int>>>&dp){
        if(index==prices.size())return 0;
        if(cooldown==1){
            return profits(prices,index+1,buy,0,dp);
        }
        if(dp[index][buy][cooldown]!=-1)return dp[index][buy][cooldown];
        
        int profit;
        if(buy){
            profit = max(-prices[index]+profits(prices,index+1,0,0,dp),0+profits(prices,index+1,1,0,dp));
        }else{
            profit = max(prices[index]+profits(prices,index+1,1,1,dp),profits(prices,index+1,0,0,dp));
        }
        return dp[index][buy][cooldown]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return profits(prices,0,1,0,dp);      
    }
};
class Solution {
public:
    int profits(vector<int>& prices, int index, int buy, vector<vector<int>>& dp) {
        if (index >= prices.size()) return 0;
        if (dp[index][buy] != -1) return dp[index][buy];
        int profit;
        if (buy) {
            profit = max(-prices[index] + profits(prices, index + 1, 0, dp), profits(prices, index + 1, 1, dp));
        } else {
            profit = max(prices[index] + profits(prices, index + 2, 1, dp),profits(prices, index + 1, 0, dp));
        }
        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return profits(prices, 0, 1, dp);      
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 1) {
                    dp[index][buy] = max(-prices[index] + dp[index + 1][0],dp[index + 1][1]);
                } else dp[index][buy] = max(prices[index] + dp[index + 2][1], dp[index + 1][0]);
            }
        }
        return dp[0][1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> front2(2, 0); 
        vector<int> front1(2, 0);
        vector<int> curr(2, 0);
        for (int index = n - 1; index >= 0; index--) {
            curr[1] = max(-prices[index] + front1[0], front1[1]);
            curr[0] = max(prices[index] + front2[1], front1[0]);
            front2 = front1;
            front1 = curr;
        }
        return front1[1]; 
    }
};


