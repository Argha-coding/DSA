class Solution {
public:

    bool possible(vector<int>& time, long long giventime, int totalTrips){
        long long actualtrips = 0;
        for(int & t : time){
            actualtrips += giventime /t;

        }
        return  actualtrips >= totalTrips;
    }


    long long minimumTime(vector<int>& time, int totalTrips) {
        
        int n = time.size();
         long long l = 1;
         long long r =  (long long)*min_element(begin(time) ,end(time)) * totalTrips;

        while( l < r ){
            long long midtime = l + ( r- l) /2 ;

            if(possible(time,midtime,totalTrips)){
                r = midtime;
            }
            else  l =  midtime + 1 ;
        }

        return l;
    }

};