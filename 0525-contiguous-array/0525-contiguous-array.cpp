class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    unordered_map<int,int>firstocc{{0,-1}};
    
    int presum = 0; 
    int cnt = 0;
 
    for(int i  = 0 ; i< nums.size(); i++){
        presum += nums[i]==1 ? 1 : -1;

        if(firstocc.count(presum)) cnt = max(cnt, i - firstocc[presum]);
        else firstocc[presum] = i;

    }

    return cnt;
    }
};