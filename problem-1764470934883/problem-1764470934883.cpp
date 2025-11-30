// Last updated: 11/30/2025, 8:18:54 AM
1class Solution {
2public:
3    int reverse(int n){
4        long int ans=0;
5        while(n>0){
6            ans=ans*10+ (n%10);
7            n=n/10;
8        }
9
10        return ans;
11    }
12    
13    int minMirrorPairDistance(vector<int>& nums) {
14        unordered_map<int,int>m;
15        int ans=INT_MAX;
16        for(int i=0;i<nums.size();i++){
17            if(m[nums[i]]>0){
18                ans=min(ans,abs((i+1)-m[nums[i]]));
19                
20            }else{
21                int r=reverse(nums[i]);
22                m[r] = i+1;
23            }
24        }
25        // cout<<ans<<endl;
26        if(ans==INT_MAX)return -1;
27        return ans;
28    }
29};