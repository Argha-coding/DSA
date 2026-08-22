class Solution {
public: 
        int n;
    int t[1001][1001];
    int solve(vector< vector <int>>&nums,int i , int P){
        if( i >= n) return 0;
        if(P != -1 && t[i][P] != -1){
            return t[i][P];
        }



        int take = 0;

        if( P ==-1 || nums[i][0] > nums[P][1]){
            take = 1 + solve( nums, i+1, i);
        }
        int skip = solve(nums,i+1,P);
        if(P!=-1) {
            return t[i][P] = max(take,skip);
        }
        return max(take,skip);

    }


    int findLongestChain(vector<vector<int>>& pairs) {
         n = pairs.size();
        memset(t,-1,sizeof(t));
        sort(begin(pairs) , end(pairs));
        return solve(pairs,0,-1);
    }
};