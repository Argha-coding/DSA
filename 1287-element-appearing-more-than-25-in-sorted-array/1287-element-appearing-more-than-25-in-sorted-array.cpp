class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        vector<int> candidates = {arr[n / 2] ,arr[n / 4] , arr[ 3 * n / 4]};
        int target = n / 4;
        for(int candidate : candidates){
            cout << candidate << endl;
            int left = lower_bound(arr.begin(),arr.end(),candidate)  - arr.begin();
            int right =upper_bound(arr.begin(),arr.end(),candidate)  - arr.begin() - 1;
            if (right - left + 1 >target){
                return candidate;
            }
        }
        return -1;
    }
};