// Last updated: 1/17/2026, 10:08:30 PM
1class Solution {
2public:
3    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tp) {
4        int maxside=0;
5        for(int i=0;i<bl.size();i++){
6            for(int j=i+1;j<bl.size();j++){
7               
8               int tr_x = min (tp[i][0],tp[j][0]);
9               int tr_y = min (tp[i][1],tp[j][1]);
10
11                int bl_x = max (bl[i][0],bl[j][0]);
12               int bl_y = max (bl[i][1],bl[j][1]);
13
14               int width = tr_x-bl_x;
15               int height = tr_y-bl_y;
16               int side = min (width,height);
17                maxside = max(maxside,side);
18
19
20            }
21        }
22        return 1LL* maxside*maxside;
23
24
25
26    }
27};