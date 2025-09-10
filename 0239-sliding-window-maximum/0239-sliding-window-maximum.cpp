#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;   // stores indices of elements
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Remove elements out of the current window
            if (dq.front() <= i - k) {
                dq.pop_front();
            }

            // First valid window starts at index k-1
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
