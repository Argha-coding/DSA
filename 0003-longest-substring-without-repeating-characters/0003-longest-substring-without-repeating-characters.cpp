class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int ans = 0;

        while (j < s.size()) {
            mp[s[j]]++; // include s[j] in window

            // if there is a duplicate character, shrink from left
            while (mp[s[j]] > 1) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }

            // update max length (all unique now)
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
