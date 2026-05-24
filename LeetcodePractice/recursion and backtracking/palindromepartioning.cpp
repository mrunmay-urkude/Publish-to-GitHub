// class Solution {
// public:
//     // check if s[l..r] is palindrome
//     bool ispal(string &s, int l, int r) {
//         while (l < r) {
//             if (s[l] != s[r]) return false;
//             l++;
//             r--;
//         }
//         return true;
//     }

//     void solve(string &s, int i, vector<string> &combi,
//                vector<vector<string>> &ans) {

//         if (i == s.size()) {
//             ans.push_back(combi);
//             return;
//         }

//         for (int j = i; j < s.size(); j++) {
//             if (ispal(s, i, j)) {
//                 combi.push_back(s.substr(i, j - i + 1));
//                 solve(s, j + 1, combi, ans);
//                 combi.pop_back();   // backtrack
//             }
//         }
//     }

//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> ans;
//         vector<string> combi;
//         solve(s, 0, combi, ans);
//         return ans;
//     }
// };
class Solution{
    public:
    
    bool ispal(string s){
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s2==s;
    }
    void solve(string s,vector<string>&parti,vector<vector<string>>&ans){
        if(s.size()==0){
            ans.push_back(parti);
            return;
        }
        for(int i =0;i<s.size();i++){
            string part=s.substr(0,i+1);
            if(ispal(part)){
                parti.push_back(part);
                solve(s.substr(i+1),parti,ans);
                parti.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parti;
        solve(s,parti, ans);
        return ans;
    }
};