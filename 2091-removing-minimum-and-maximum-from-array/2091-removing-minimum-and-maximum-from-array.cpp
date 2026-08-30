class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int  n = nums.size();
        int minidx = min_element(begin(nums) , end(nums)) - begin(nums);
        int maxidx = max_element(begin(nums) , end(nums)) - begin(nums);

        int left = min(minidx,maxidx);
        int right = max(minidx,maxidx);

        return min({left + 1 + n -right, right+1,n-left});
         
    }
};