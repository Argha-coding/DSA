class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

    unordered_map<int,int>mpp;
    mpp[0] = 1;
    int presum = 0; 
    int cnt = 0;
 
    for(int i  = 0 ; i< nums.size(); i++){
        presum = (presum + nums[i]%k + k)% k;
      
         cnt +=mpp[presum];
         mpp[presum] += 1;
    }



    return cnt;
        
    }
};