class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.length();
        int m = part.length();

        bool found = true;

        while (found) {
            found = false;
            for (int i = 0; i <= n - m; i++) {
                int j =0;
                while (j < m && s[i + j] == part[j]) {
                    j++;
                }
                if (j == m) {
                    for (int k = i; k < n - m; k++) {
                        s[k] = s[k + m];
                    }
                    n -= m;
                    s.resize(n);
                    found = true;
                    break;  
                }
            }
        }

        return s;
    }
};
