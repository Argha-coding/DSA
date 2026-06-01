class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        int prevnotdeleted = arr[0];
        int prevwithdeleted = 0;

        int maxi = arr[0];

        for(int i = 1; i < n; i++) {

            int notdeleted =
                max(prevnotdeleted + arr[i], arr[i]);

            int withdeleted =
                max(prevnotdeleted, prevwithdeleted + arr[i]);

            prevnotdeleted = notdeleted;
            prevwithdeleted = withdeleted;

            maxi = max(maxi, max(notdeleted, withdeleted));
        }

        return maxi;
    }
};