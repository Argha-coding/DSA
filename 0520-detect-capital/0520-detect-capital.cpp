class Solution {
public:
    bool detectCapitalUse(string word) {
        int  capitalcounts = 0; 

        for( char &ch : word){
            if(isupper(ch))
                capitalcounts++;


        }
        if( capitalcounts == 0 || capitalcounts == word.length() || capitalcounts ==1 && isupper(word[0])){
            return true;
        }
        return false;
    }
};