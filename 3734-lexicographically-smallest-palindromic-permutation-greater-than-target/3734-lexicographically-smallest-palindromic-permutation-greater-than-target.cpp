class Solution {
public:
    char midchar = '$';
    int halflen = 0;
    string result = "";



  bool solve(string& curr, vector<int>& count, string& target, int i,
               bool greater) {
         if(curr.length() == halflen) {
            string candidate = curr;
            string righthalf = curr;
            reverse(begin(righthalf) , end(righthalf));
            if(midchar != '$'){
                candidate += midchar;

            }
            candidate += righthalf;
            if(candidate > target){
                result = candidate;
                return true;
            }
            return false;
         } 
         for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] == 0)
                continue;
            if (!greater && ch < target[i])
                continue;

            curr.push_back(ch);
            count[ch - 'a']--;
            bool isgreater = greater || ch > target[i];
            if (solve(curr, count, target, i + 1, isgreater)) {
                return true;
            }
            curr.pop_back();
            count[ch - 'a']++;
        }
        return false;     

        
    
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count( 26,0);
        for( char &ch : s){
            count[ch-'a']++;

        }
        int oddcount = 0;
        for(int  c= 0 ; c <26 ; c++){
            if(count[c] % 2 ==1 ){
                oddcount++;
                midchar  = c + 'a';

            }
        }
        if(oddcount >1 )
            return "";
         for(int  c= 0 ; c <26 ; c++){
            count[c] /=2 ;

         }
         halflen = n /2;
         string curr = "";
         solve(curr,count,target,0,false);
         return result;


    }
};