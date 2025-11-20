class Solution {
public:
    int t[21][2001];   // n <= 20, sum range <= 2000 (1000 pos + 1000 neg)

    int solve(vector<int>& nums, int i, int sum, int target) {

        if (i == nums.size()) 
            return (sum == target) ? 1 : 0;

        if (t[i][sum + 1000] != -1)
            return t[i][sum + 1000];

        // Choose +
        int plusWay = solve(nums, i + 1, sum + nums[i], target);

        // Choose -
        int minusWay = solve(nums, i + 1, sum - nums[i], target);

        return t[i][sum + 1000] = plusWay + minusWay;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(t, -1, sizeof(t));

        // Start recursion from index 0 with current sum = 0
        return solve(nums, 0, 0, target);
    }
};
