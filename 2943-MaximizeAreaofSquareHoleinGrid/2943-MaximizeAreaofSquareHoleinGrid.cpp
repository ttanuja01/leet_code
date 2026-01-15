// Last updated: 1/15/2026, 8:43:40 PM
1class Solution {
2public:
3    int getlongestconsecarraylen(int n,vector<int>&bars){
4        int ans=1;
5        int l=1;
6        int fe=bars[0];
7        for(int i=1;i<bars.size();i++){
8            if(bars[i]-bars[i-1]==1){
9               l++;
10            }else{
11                l=1;
12            }
13            ans=max(ans,l);
14        }
15        return ans;
16    }
17    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
18        sort(hBars.begin(),hBars.end());
19         sort(vBars.begin(),vBars.end());
20        int a = getlongestconsecarraylen(n,hBars);
21        int b = getlongestconsecarraylen(m,vBars);
22        int ans= min(a,b);
23        return (ans+1)*(ans+1);
24    }
25};