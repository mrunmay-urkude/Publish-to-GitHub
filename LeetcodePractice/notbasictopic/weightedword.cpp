class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto i:words){
            long long temp=0;
            for(int j=0;j<i.size();j++){
                temp+=weights[i[j]-'a'];
            }
            temp%=26;
            ans+=('z'-temp);
        }
        return ans;
    }
};