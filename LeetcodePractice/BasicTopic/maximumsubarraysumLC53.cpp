class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxi = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);

            maxi = max(maxi, currentSum);
        }

        return maxi;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int maxsum=INT_MIN;
        int maxelement=INT_MIN;
        for(int x:nums){
            if(x>maxelement){
                maxelement=x;
            }
            currsum+=x;
            maxsum=max(maxsum,currsum);
            if(currsum<0){
                currsum=0;
            }
        }
        if(maxelement<0){
            return maxelement;
        }
        return maxsum;
    }
};