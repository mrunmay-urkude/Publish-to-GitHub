class Solution {
public:
    void tovector(TreeNode* root, vector<int>& ans){
        if(!root) return;
        tovector(root->left, ans);
        ans.push_back(root->val);
        tovector(root->right, ans);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        tovector(root, ans);

        int m = INT_MAX;

        for(int i = 1; i < ans.size(); i++){
            m = min(m, ans[i] - ans[i-1]);
        }

        return m;
    }
};
