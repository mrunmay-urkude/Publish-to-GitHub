class Solution {
public:
//Using Xor "^"
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int val :nums ){
            ans = ans^val;
        }
        return ans;
    }
};