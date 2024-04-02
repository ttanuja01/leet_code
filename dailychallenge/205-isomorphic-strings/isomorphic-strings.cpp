class Solution {
public:
    bool isIsomorphic(string s, string t) {
      int m=s.length();
        int n=t.length();
        if(m!=n)return false;
        unordered_map<char,int>a;
         unordered_map<char,int>b;
        for(int i=0;i<m;i++){
            if(a[s[i]]==0){
                a[s[i]]=i+1;
            }
                s[i]='0'+a[s[i]]-1;
            cout<<s[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            if(b[t[i]]==0){
                b[t[i]]=i+1;
            }
                t[i]='0'+b[t[i]]-1;
            cout<<t[i]<<" ";
        }
        
        return s==t;
    }
};