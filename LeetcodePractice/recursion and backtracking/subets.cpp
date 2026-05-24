class Solution {
public:
    void print(vector<int> &nums,vector<int> &ans,int i,vector<vector<int>> &allsubset){
        if(i==nums.size()){
            allsubset.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        print(nums,ans,i+1,allsubset);
        ans.pop_back();
        print(nums,ans,i+1,allsubset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubset;
        vector<int> ans;
        print(nums,ans,0,allsubset);
        return allsubset;
    }
};