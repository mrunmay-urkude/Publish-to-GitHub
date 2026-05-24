class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        vector<int> freq1(26, 0);
        vector<int> window(26, 0);
        for(char ch : s1){
            freq1[ch - 'a']++;
        }
        int left = 0;
        for(int right = 0; right < m; right++){
            window[s2[right] - 'a']++;
            if(right - left + 1 > n){
                window[s2[left] - 'a']--;
                left++;
            }
            if(window == freq1){
                return true;
            }
        }

        return false;
    }
};