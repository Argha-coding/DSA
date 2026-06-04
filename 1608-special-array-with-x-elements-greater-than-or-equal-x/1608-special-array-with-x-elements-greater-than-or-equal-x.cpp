class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n  =nums.size();
        int cnt = 0;
        vector<int> freq(n+1,0);
        for(auto  el : nums) freq[min(n , el)]++;

        for(int i = n; i >= 1 ; i--){
            cnt += freq[i];
            if(cnt == i) return i;
        }
        return -1;

    }
};