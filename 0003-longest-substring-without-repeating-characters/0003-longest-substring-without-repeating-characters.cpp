class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);  // frequency of each character (ASCII)
        int i = 0, j = 0;
        int ans = 0;

        while (j < s.size()) {
            freq[s[j]]++; // add current char

            // if duplicate, shrink window from left
            while (freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }

            // update maximum length
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
