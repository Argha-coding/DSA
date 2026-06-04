class Solution {
public:
    bool time_is_suff(vector<int> & ranks, int&cars, long long min_given){
        long long cars_done = 0;
        for(auto  r : ranks ){
            long long c2 = min_given/r;
            long long c = floor(sqrt(c2));
            cars_done += c;
        }
     return (cars_done >= cars);

    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long ans= 0 , l = 1, r = 1e14;
        while( l < r){
            long long mid = l + ( r-l) /2;
            if(time_is_suff(ranks,cars,mid)) {
                r= mid;
            }
            else l = mid +1;

        }
        return l;
    }
};