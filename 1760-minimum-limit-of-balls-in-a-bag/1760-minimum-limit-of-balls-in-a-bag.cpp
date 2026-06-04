class Solution {
public:
    bool is_possible(int maxBallsInBag, vector<int>& nums, int maxOperations) {
        long long totalOperations = 0;

        for (int num : nums) {
            totalOperations += (num - 1) / maxBallsInBag;

            if (totalOperations > maxOperations)
                return false;
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (is_possible(mid, nums, maxOperations)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};