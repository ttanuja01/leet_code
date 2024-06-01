class Solution {
public:
    void dfs(vector<vector<int>>& arr,int n,vector<int>& v,int curr){
        v[curr]=1;
        for(int i=0;i<n;i++){
            if(i!=curr && arr[curr][i]!=0 && v[i]==0){
                dfs(arr,n,v,i);
                
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& arr) {
        int ans=0;
        int n=arr.size();
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            if(v[i]!=1 ){
                ans+=1;
                dfs(arr,n,v,i);
                
            }
        }
        return ans;
        
    }
    
};