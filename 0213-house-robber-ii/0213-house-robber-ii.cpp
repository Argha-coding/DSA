class Solution {
public:
    int solve(vector<int>& nums, int l , int r){

        int prev = 0 ;
        int prevprev = 0;

        for(int i = l ; i <= r;i++){
            int take = nums[i] + prevprev;

            int skip = prev;
            int temp = max(skip,take);

            prevprev = prev;
            prev = temp;
        }
        return prev;
    }



    // Bottom up appproach constant space 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        if( n==2) return  max(nums[0] , nums[1]);

        int takefirsthouse = solve( nums , 0, n-2);
        int skipfirsthouse = solve( nums , 1, n-1);
        return max(takefirsthouse,skipfirsthouse);
 
    }
};