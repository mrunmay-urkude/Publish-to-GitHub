class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted;

        for (int k : nums1) {
            sorted.push_back(k);
        }
        for (int k : nums2) {
            sorted.push_back(k);
        }

        sort(sorted.begin(), sorted.end());

        int n = nums1.size() + nums2.size();
        double median;

        if (n % 2 != 0) {
            median = sorted[n / 2];
        } else {
            median = (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
        }

        return median;
    }
};


