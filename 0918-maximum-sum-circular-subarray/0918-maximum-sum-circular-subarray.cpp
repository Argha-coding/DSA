class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum = 0;
        int maxsum = nums[0];
        int minsum = nums[0];
        int curmax = 0;
        int curmin = 0;

        for (int el : nums) {

            curmax = max(curmax + el, el);
            maxsum = max(maxsum, curmax);

            curmin = min(curmin + el, el);
            minsum = min(minsum, curmin);

            totalsum += el;
        }

        return maxsum > 0  ? max(maxsum, totalsum - minsum): maxsum;
              
    }
};