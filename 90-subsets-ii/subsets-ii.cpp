class Solution {
public:
    void solve(int idx, vector<int>& arr, vector<int>& temp, vector<vector<int>>& result) {
        result.push_back(temp);
        for (int i = idx; i < arr.size(); i++) {
            if (i > idx && arr[i] == arr[i - 1]) continue; 
            temp.push_back(arr[i]);
            solve(i + 1, arr, temp, result);
            temp.pop_back(); 
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> result;
        vector<int> temp;
        solve(0, nums, temp, result);
        return result;
    }
};