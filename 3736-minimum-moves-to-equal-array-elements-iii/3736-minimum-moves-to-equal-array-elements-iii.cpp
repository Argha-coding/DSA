class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEl = *max_element(begin(nums), end(nums));
        
        int moves = 0;
        for (int& num : nums) {
            moves += maxEl - num;
        }
        
        return moves;
    }
};