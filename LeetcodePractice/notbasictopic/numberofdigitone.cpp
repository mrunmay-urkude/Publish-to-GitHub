class Solution {
public:
    int countDigitOne(int n) {
        long long ans = 0;

        for (long long factor = 1; factor <= n; factor *= 10) {
            long long lower = n % factor;
            long long curr = (n / factor) % 10;
            long long higher = n / (factor * 10);
            if (curr == 0)
                ans += higher * factor;
            else if (curr == 1)
                ans += higher * factor + lower + 1;
            else
                ans += (higher + 1) * factor;
        }

        return (int)ans;
    }
};