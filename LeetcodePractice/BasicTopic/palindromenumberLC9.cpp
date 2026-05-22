class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        vector<int> digits;
        int temp = x;

        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        int start = 0, end = digits.size() - 1;
        while (start < end) {
            if (digits[start] != digits[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};



