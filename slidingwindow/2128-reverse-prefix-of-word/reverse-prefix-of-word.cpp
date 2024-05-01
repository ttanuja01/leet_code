class Solution {
public:
    string reversePrefix(string word, char ch) {
        string res="";
        int n= word.length();
        int i=0;
        bool l=false;
        while(i<n){
            
            
            if(!l)res = word[i]+res;
            else res+=word[i];
            if(ch==word[i]){
                l=true;
            }
            i++;
        }
        if(l==true)return res;
        return word;
        
    }
};