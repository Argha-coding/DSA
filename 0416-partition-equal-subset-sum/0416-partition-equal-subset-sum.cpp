class Solution {
public:

    int t[201][10001];

    bool solve(vector<int>& arr, int i, int j) {

        if (j == 0) return true;
        if (i == 0) return arr[0] == j;

        if (t[i][j] != -1)
            return t[i][j];

        bool notake = solve(arr, i - 1, j);

        bool take = false;
        if (arr[i] <= j)
            take = solve(arr, i - 1, j - arr[i]);

        return t[i][j] = (take || notake);
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        memset(t, -1, sizeof(t));

        return solve(nums, n - 1, target);
    }
};
