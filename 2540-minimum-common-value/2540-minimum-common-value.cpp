class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(),nums1.end());
         for(auto el : nums2){
          if(set1.contains(el)) return el;
          }
    
    return -1;
    }
};