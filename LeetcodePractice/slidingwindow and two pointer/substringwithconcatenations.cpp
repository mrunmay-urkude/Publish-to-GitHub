class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        unordered_map<string,int>mp;
        for(auto i:words){
            mp[i]++;
        }
        int wordLen = words[0].size();
        int totalLen = wordLen * words.size();  
        for(int i=0;i+totalLen<=s.size();i++){
            unordered_map<string,int>seen;
            for(int j=0;j<words.size();j++){
                string word=s.substr(i+j*wordLen,wordLen);
                seen[word]++;
            }
            if(seen==mp){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};