class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string path;
        path.reserve(s.size());   // reserve space to avoid reallocations
        backtrack(s, 0, path, ans);
        return ans;
    }

private:
    void backtrack(const string& s, int i, string& path, vector<string>& ans) {
        if (i == s.size()) {
            ans.push_back(path);
            return;
        }

        if (isalpha(s[i])) {
            // lowercase branch
            path.push_back(tolower(s[i]));
            backtrack(s, i + 1, path, ans);
            path.pop_back();

            // uppercase branch
            path.push_back(toupper(s[i]));
            backtrack(s, i + 1, path, ans);
            path.pop_back();
        } else {
            // digit → only one option
            path.push_back(s[i]);
            backtrack(s, i + 1, path, ans);
            path.pop_back();
        }
    }
};
