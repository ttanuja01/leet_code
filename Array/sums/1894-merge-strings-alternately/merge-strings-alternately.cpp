class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s="";
        int i=0,j=word1.length(),a=0,b=word2.length();
        while(i<j && a<b){
            s=s+word1[i]+word2[a];
            // cout<<s<<"*"<<word1[i]<<endl;
            i++;
            a++;
        }
        while(i<j){s+=word1[i];i++;}
         while(a<b){s+=word2[a];a++;}
        return s;
        
    }
};