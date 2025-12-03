// Last updated: 12/3/2025, 11:22:21 PM
1constexpr int bias=1<<11;
2class Solution {
3public:
4    using ll=long long;
5
6    // Pack 2 integers into one  key
7    static int pack2(int a, int b) {
8        return ((ll)(a+bias)<<16) | (b+bias);
9    }
10
11    // Pack 3 integers into one 64-bit key, note |c|<=2e6
12    static ll pack3(int a, int b, int c) {
13        return ((ll)(a+bias)<<50)|((ll)(b+bias)<<30)|(c+bias*bias);
14    }
15
16    // Pack 4 integers into one 64-bit key
17    static ll pack4(int a, int b, int c, int d) {
18        return ((ll)(a+bias)<<48)|((ll)(b+bias)<<32)|((ll)(c+bias)<<16)|(d+ bias);
19    }
20
21    static int countTrapezoids(vector<vector<int>>& points) {
22        const int n=points.size();
23        const int nn=n*(n-1);
24
25        unordered_map<ll,int> coeff, midPointWslope;
26        unordered_map<ll,int> slope, midPoint;
27
28        coeff.reserve(nn);
29        slope.reserve(nn);
30        midPointWslope.reserve(nn);
31        midPoint.reserve(nn);
32
33        int cnt=0;
34
35        for(int i=0; i<n-1; i++) {
36            const int x0=points[i][0], y0=points[i][1];
37            for(int j=i+1; j< n; j++) {
38                const int x1=points[j][0], y1=points[j][1];
39                
40                // line : ax+by+c=0
41                int a=y1-y0;
42                int b=x0-x1;
43                int c=y0*x1-y1*x0;
44
45                // the 1st nonzero coeff is positive
46                if(a==0 && b<0) { b=-b; c=-c; }
47                else if(a<0) { a=-a; b=-b; c=-c; }
48
49                // normalize slope and line coefficients
50                int gm=gcd(a, b), gc=gcd(gm, c);
51
52                int ab=pack2(a/gm, b/gm);           // slope key
53                ll abc=pack3(a/gc, b/gc, c/gc);    // line key
54
55                // 2 segments with same midpoint with different slopes
56                // are the cross lines for a parallelgram
57                ll midP=pack2(x0+x1, y0+y1);       // midpoint key 
58                ll midab=pack4(x0+x1, y0+y1, a/gm, b/gm); //midpoint+slope key
59
60                cnt+=(slope[ab]++)
61                    -(coeff[abc]++)
62                    -(midPoint[midP]++)// each parallelgram counts twice
63                    +(midPointWslope[midab]++);
64            }
65        }
66        return cnt;
67    }
68};