class Solution {
public:
    bool is_okayatdis(int mid, vector<int>& position, int m) {

        int countofballsplaced = 1 , previd = 0;
        for (int  i = 1 ; i < position.size(); i++){
            if(position[i] - position[previd] >= mid){
                countofballsplaced++;
                previd = i;
            }

        }
        return countofballsplaced >= m;


    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 0;
        int r = *max_element(position.begin(), position.end());

        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (is_okayatdis(mid,position,m)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};