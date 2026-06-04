class Solution {
public:
    bool is_okaydays(int mid, vector<int>& bloomDay, int m, int k) {

        int conscnt = 0, numofbouq = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                conscnt++;

            } else
                conscnt = 0;
            if (conscnt == k) {
                numofbouq++;
                conscnt = 0;
            }
        }
        return (numofbouq >= m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long)m * k > n)
            return -1;

        int l = 1;
        int r = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (is_okaydays(mid, bloomDay, m, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};