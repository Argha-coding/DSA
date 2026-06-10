class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int> charToindex;
        unordered_map<string,int> wordTotext;

        stringstream ss(s);
        string token;
        int counttokens = 0;
        int i = 0 ;
        int n = pattern.size();

        while( ss >> token){

            counttokens++;
            if(i==n || charToindex[pattern[i]] != wordTotext[token] )
                return false;
            charToindex[pattern[i]] = i+1;
            wordTotext[token] = i+1;
            i++;     
        }
        if(counttokens != n || i!=n)
          return false;

          return true;

    }
};