class Solution {
public:
//Kadane algo//
    int maxArraySum(vector<int>& nums){
        int curr = 0;
        int maxSum = INT_MIN;
        int maxElement = INT_MIN;

        for(int x : nums){
            maxElement = max(maxElement, x);

            curr += x;
            maxSum = max(maxSum, curr);

            if(curr < 0) curr = 0;
        }

        if(maxElement < 0) return maxElement; 
        return maxSum;
    }

    int minArraySum(vector<int>& nums){
        int curr = 0;
        int minSum = INT_MAX;

        for(int x : nums){
            curr += x;
            minSum = min(minSum, curr);

            if(curr > 0) curr = 0;
        }

        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        for(int x : nums) totalSum += x;
        int maxNormal = maxArraySum(nums);
        int minSub = minArraySum(nums);
        if(maxNormal < 0) return maxNormal;

        int maxCircular = totalSum - minSub;

        return max(maxNormal, maxCircular);
    }
};
