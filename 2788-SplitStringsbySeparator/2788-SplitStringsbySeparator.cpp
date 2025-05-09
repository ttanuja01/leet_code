// Last updated: 5/9/2025, 9:44:36 PM
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        string s="";
        string r="";
        vector<string>res;
        for(int i=0;i<words.size();i++){
            s=words[i];
            int n=s.length();
            int idx=0;
            while(idx<n){
                if(s[idx]==separator){
                    if(r.length()>0)res.push_back(r);
                    r="";
                }else{
                    r+=s[idx];
                }
                idx++;
            }
            if(r.length()>0)res.push_back(r);
            r="";
        }
        return res;
        
    }
};