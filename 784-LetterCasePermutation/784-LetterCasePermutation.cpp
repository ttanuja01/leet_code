// Last updated: 5/15/2025, 12:52:39 PM
class Solution {
public:
    void getAllPS(vector<string>&ans,string &s,int n,int idx,string temp){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        if(tolower(s[idx])-'a' >= 0 && tolower(s[idx])-'a'<=25 ){
            getAllPS(ans,s,n,idx+1,temp+string(1,toupper(s[idx])));
            getAllPS(ans,s,n,idx+1,temp+string(1,tolower(s[idx])));
        }else{
             getAllPS(ans,s,n,idx+1,temp+s[idx]);
        }


    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        if(s.length()==0)return ans;
        string temp="";
        getAllPS(ans,s,s.length(),0,temp);
        return ans;
    }
};