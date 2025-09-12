class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int ans = 0;

        while (j < fruits.size()) {
            mp[fruits[j]]++; // include fruits[j] in window

            // shrink window if more than 2 distinct fruits
            while (mp.size() > 2) {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }

            // now we have at most 2 types of fruits
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
