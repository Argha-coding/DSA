class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for(  int k = 0 ; k <= 31;k++ ){
            
            int temp = (1<<k);
            int countzeroes = 0;
            int countones = 0;
           

            for(int &num : nums){
                if((num & temp) == 0 ){
                    countzeroes++;

                }
                else countones++;
            }
            if(countones % 3 ==1){
            result = ( result | temp);

        }
        }
        return result;
    }
};