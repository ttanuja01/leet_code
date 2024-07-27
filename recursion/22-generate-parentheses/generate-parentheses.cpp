class Solution {
public:
    void generate(int o , int c ,string res, vector<string>&v){
        if(o<0 || c<0)return;
        
        if(o==0 && c==0){
            v.push_back(res);    
        }
        // if(o==0){
        // generate(o,c-1,res+')',v);    
        // }
        generate(o-1,c,res+'(',v);
        if(c!=o)
         generate(o,c-1,res+')',v);
        // generate(o,c-1,res+')',v);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        generate(n-1,n,"(",v);
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<endl;
        }
        return v;
        
    }
};