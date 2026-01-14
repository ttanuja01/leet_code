// Last updated: 1/15/2026, 12:40:07 AM
1class Solution {
2public:
3    double getbottomarea(vector<vector<int>>& s,double y){
4        double area=0;
5        for (int i=0;i<s.size();i++){
6            if(s[i][1]+s[i][2] <= y){
7                long double l = s[i][2];
8area += l * l;
9            }
10            else if(s[i][1] < y && s[i][1]+s[i][2] >y){
11                 area+= (y-s[i][1])*s[i][2];
12            }
13        }
14        return area;
15    }
16        int getlowestorhighest(vector<vector<int>>& squares,int x){
17        int s=INT_MAX;
18        int l=INT_MIN;
19        for (int i=0;i<squares.size();i++){
20            s=min(s,squares[i][1]);
21            l=max(l,squares[i][1]+squares[i][2]);
22        }
23        if(x==0)return s;
24        return l; 
25    }
26        long double gettotalarea(vector<vector<int>>& squares){
27        long double area=0;
28        for (int i=0;i<squares.size();i++){
29            long double l = squares[i][2];
30area += l * l;
31        }
32        return area;
33    }
34
35    double separateSquares(vector<vector<int>>& squares) {
36        double low = getlowestorhighest(squares,0);
37        double high = getlowestorhighest(squares,1);
38    // cout<<low<<":"<<high<<endl;
39    long double ta = gettotalarea(squares);
40        // cout<<ta<<":"<<endl;
41        double res= 0.00;
42    while(high-low>1e-5){
43       double  m = (low+high)/(2.0);
44        double ba = getbottomarea(squares,m);
45        res=m;
46        // cout<<ba<<"::::"<<m<<endl;
47        if(ba>=(ta/2)){
48            high=m;
49        }else {
50            low=m;
51        }
52    }
53    return res;
54        
55    }
56};