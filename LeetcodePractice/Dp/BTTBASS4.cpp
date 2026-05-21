basic recursion
class Solution {
public:
    int best(int k, vector<int>& prices,int buy,int index){
        if(index==prices.size()||k==0)return 0;
        int profit;
        if(buy){
            profit=max(-prices[index]+best(k,prices,0,index+1),best(k,prices,1,index+1));
        }else{
            profit=max(prices[index]+best(k-1,prices,1,index+1),best(k,prices,0,index+1));
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        
        return best(k,prices,1,0);
    }
};

memoization

class Solution {
public:
    int best(int k, vector<int>& prices,int buy,int index,vector<vector<vector<int>>>&dp){
        if(index>=prices.size()||k==0)return 0;
        if(dp[index][buy][k]!=-1)return dp[index][buy][k];
        int profit;
        if(buy){
            profit=max(-prices[index]+best(k,prices,0,index+1,dp),best(k,prices,1,index+1,dp));
        }else{
            profit=max(prices[index]+best(k-1,prices,1,index+1,dp),best(k,prices,0,index+1,dp));
        }
        return dp[index][buy][k]= profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return best(k,prices,1,0,dp);
    }
};

tabulated 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(k + 1, 0))
        );

        for(int index = n - 1; index >= 0; index--) {

            for(int buy = 0; buy <= 1; buy++) {

                for(int cap = 1; cap <= k; cap++) {

                    int profit;

                    if(buy) {

                        profit = max(
                            -prices[index] + dp[index + 1][0][cap],
                            dp[index + 1][1][cap]
                        );

                    } else {

                        profit = max(
                            prices[index] + dp[index + 1][1][cap - 1],
                            dp[index + 1][0][cap]
                        );
                    }

                    dp[index][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][k];
    }
};

2d optimized
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for(int index = n - 1; index >= 0; index--) {

            for(int buy = 0; buy <= 1; buy++) {

                for(int cap = 1; cap <= k; cap++) {

                    int profit;

                    if(buy) {

                        profit = max(
                            -prices[index] + ahead[0][cap],
                            ahead[1][cap]
                        );

                    } else {

                        profit = max(
                            prices[index] + ahead[1][cap - 1],
                            ahead[0][cap]
                        );
                    }

                    curr[buy][cap] = profit;
                }
            }

            ahead = curr;
        }

        return ahead[1][k];
    }
};


//////////////////////////////////////////////////////////////

another logic

class Solution {
public:
    int buy(int k, vector<int>& prices,int transactions,int index){
        if(transactions>2*k||index>=prices.size())return 0;
        int profit;
        if(transactions%2==1){
            profit=max(-prices[index]+buy(k,prices,transactions+1,index+1),buy(k,prices,transactions,index+1));
        }else{
            profit=max(prices[index]+buy(k,prices,transactions+1,index+1),buy(k,prices,transactions,index+1));
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        return buy(k,prices,1,0);
    }
};
memoized

class Solution {
public:
    int buy(int k, vector<int>& prices,int transactions,int index,vector<vector<int>>&dp){
        if(transactions>2*k||index>=prices.size())return 0;
        if(dp[index][transactions]!=-1)return dp[index][transactions];
        int profit;
        if(transactions%2==1){
            profit=max(-prices[index]+buy(k,prices,transactions+1,index+1,dp),buy(k,prices,transactions,index+1,dp));
        }else{
            profit=max(prices[index]+buy(k,prices,transactions+1,index+1,dp),buy(k,prices,transactions,index+1,dp));
        }
        return dp[index][transactions]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2*k+1,-1));
        return buy(k,prices,1,0,dp);
    }
};


tabulated 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) return 0;
        vector<vector<int>>dp(prices.size()+1,vector<int>(2*k+1,0));
        for(int index=prices.size()-1;index>=0;index--){
            for(int transactions=2*k-1;transactions>=0;transactions--){
                if(transactions%2==0){
                    dp[index][transactions]=max(-prices[index]+dp[index+1][transactions+1],dp[index+1][transactions]);
                }else{
                    dp[index][transactions]=max(prices[index]+dp[index+1][transactions+1],dp[index+1][transactions]);
                }
            }
        }
        return dp[0][0];
    }
};

1d array space optimized
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) return 0;
        vector<int>ahead(2*k+1,0);
        for(int index=prices.size()-1;index>=0;index--){
            vector<int>curr(2*k+1,0);
            for(int transactions=2*k-1;transactions>=0;transactions--){
                if(transactions%2==0){
                    curr[transactions]=max(-prices[index]+ahead[transactions+1],ahead[transactions]);
                }else{
                    curr[transactions]=max(prices[index]+ahead[transactions+1],ahead[transactions]);
                }
            }
            ahead=curr;
        }
        return ahead[0];
    }
};