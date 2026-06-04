class Solution {
public:

    bool is_possible( int k , vector<int> &piles, int h){

        int hours_req = 0;
        for(int bananas : piles ){
            hours_req += ceil((bananas *1.0)/k);

        }
        return (hours_req <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        while( l < r ) {
            int mid = l + (r-l) /2 ;
            if(is_possible(mid,piles,h)){
                r = mid;
            }
            else l = mid + 1 ;
        }
        return l;
    }
};