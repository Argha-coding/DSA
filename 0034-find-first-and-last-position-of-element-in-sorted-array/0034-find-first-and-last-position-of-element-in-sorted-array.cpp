class Solution {
public:


int findrightmost(vector<int>& nums, int target, int n){
    int l = 0 , r = n-1;
    int rightmost = -1;
    while(l <= r){

        int mid = l +( r- l) / 2;
        if(nums[mid] == target){
            rightmost = mid;
            l= mid+1;

        }
        else if(nums[mid] < target){
            l  = mid+1;
        }
        else r= mid-1;

    }
    return rightmost;
}

int findleftmost(vector<int>& nums, int target, int n){
    int l = 0 , r = n-1;
    int leftmost = -1;
    while(l <= r){

        int mid = l +( r- l) / 2;
        if(nums[mid] == target){
            leftmost = mid;
            r= mid-1;

        }
        else if(nums[mid] < target){
            l  = mid+1;
        }
        else r= mid-1;

    }
    return leftmost;
}


    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left_most = findleftmost(nums,target,n);
        int right_most = findrightmost(nums,target,n);
        return{left_most,right_most};

    }
};