class Solution {
public:
    bool isAnagram(string s, string t) {
        int a=s.length();
        int b =t.length();
        
        unordered_map<char,int>m;
        for(int i=0;i<a;i++){
            m[s[i]]++;
        }
        
        for(int i=0;i<b;i++){
            m[t[i]]--;
        }
        for(auto it:m){if(it.second!=0)return false;}
     return true;
        return false;
    }
};