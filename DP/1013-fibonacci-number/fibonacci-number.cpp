class Solution {
public:
    int fun(vector<int>&v,int n){
        if(v[n]!=-1)return v[n];
        
       v[n]= fun(v,n-1)+fun(v,n-2);
        return v[n];
    }
    
    
    
    int fib(int n) {
        if(n==0)return 0;
       vector<int>v(n+1,-1);
    v[0]=0;
        v[1]=1;
         return fun(v,n);
        
    }
};