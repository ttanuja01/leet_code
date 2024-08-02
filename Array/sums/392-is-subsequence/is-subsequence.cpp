class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i=0,j=s.length(),a=0,b=t.length();
        int c=0;
        while(a<b){
            
            if(s[i]==t[a]){
                i++;
                c++;
            }
            a++;
        }
        if(c==j)return true;
        return false;
        
    }
};