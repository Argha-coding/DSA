class Solution {
public:

    int findPivot(vector<int>& nums, int l, int r) {

        while (l < r) {

            while (l < r && nums[l] == nums[l + 1])
                l++;

            while (l < r && nums[r] == nums[r - 1])
                r--;

            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }

        return r;
    }

    int binarySearch(int l, int r, vector<int>& nums, int target) {

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }

    bool search(vector<int>& nums, int target) {

        int n = nums.size();

        int pivot_index = findPivot(nums, 0, n - 1);

        if (binarySearch(0, pivot_index - 1, nums, target) != -1)
            return true;

        return binarySearch(pivot_index, n - 1, nums, target) != -1;
    }
};