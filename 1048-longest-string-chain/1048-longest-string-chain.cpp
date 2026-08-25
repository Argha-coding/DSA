class Solution {
public:
    int n;

    bool  ispred( string &prev , string &curr){
        int M =  prev.length();
        int N = curr.length();

        if( M > N || N - M !=1){
            return false;
        }
        int i = 0 , j = 0 ;
        while( i < M && j < N){
            if(prev[i] == curr[j]){
                i++;

               
            }
             j++;
        }
        return i == M;
    }
    static bool Myfunction  (string &word1 , string &word2){
        return word1.length() < word2.length();

    }   


    int longestStrChain(vector<string>& words) {
        n = words.size();

        sort(begin(words) , end(words) , Myfunction);
        vector<int> t( n , 1);
        int maxL= 1;
        for(int i = 0 ; i < n ; i++){
            for(  int j =0 ; j < i; j++){
                if( ispred(words[j] , words[i])){
                    t[i] = max( t[i] , t[j] +1);
                    maxL = max(t[i] , maxL);
                }
            }
        }
        return maxL;
    }
};