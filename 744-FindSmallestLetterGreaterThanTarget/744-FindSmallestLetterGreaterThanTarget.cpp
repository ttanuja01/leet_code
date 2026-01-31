// Last updated: 1/31/2026, 10:06:52 PM
1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& l, char t) {
4    
5        int a=0;
6        int b =l.size()-1;
7        if(l[b]<t)return l[0];
8        int  m = (a+b)/2;
9        while(a<=b){
10             m = (a+b)/2;
11            if(l[m]>t){
12                if(m>0 && l[m-1]<=t){
13                    return l[m];
14                }
15                b=m-1;
16            }else{
17                
18                a= m+1;
19            }
20        }
21        if(l[m]>t)return l[m];
22        return l[0];
23    }
24};