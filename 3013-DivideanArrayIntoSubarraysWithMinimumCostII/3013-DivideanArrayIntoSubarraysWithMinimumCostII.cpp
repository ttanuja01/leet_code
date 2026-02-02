// Last updated: 2/2/2026, 5:32:26 PM
1class Solution {
2public:
3    struct SmartWindow{
4        int K;
5        multiset<int> low, high;
6        long long sumLow = 0;
7
8        SmartWindow(int k) : K(k) {}
9
10        int windowSize() const{
11            return (int)low.size() + (int)high.size();
12        }
13        void rebalance() {
14            int need = min(K, windowSize());
15
16            while((int)low.size() > need){
17                auto it = prev(low.end());
18                int x = *it;
19                low.erase(it);
20                sumLow -= x;
21                high.insert(x);
22            }
23            while((int)low.size() < need && !high.empty()){
24                auto it = high.begin();
25                int x = *it;
26                high.erase(it);
27                low.insert(x);
28                sumLow += x;
29            }
30        }
31        void add(int x){
32            if(low.empty() || x <= *prev(low.end())){
33                low.insert(x);
34                sumLow += x;
35            }
36            else{
37                high.insert(x);
38            }
39            rebalance();
40        }
41        void remove(int x){
42            auto itLow = low.find(x);
43            if(itLow != low.end()){
44                low.erase(itLow);
45                sumLow -= x;
46            }
47            else{
48                auto itHigh = high.find(x);
49                if(itHigh != high.end()){
50                    high.erase(itHigh);
51                }
52            }
53            rebalance();
54        }
55        long long query() const{
56            return sumLow;
57        }
58    };
59    long long minimumCost(vector<int>& nums, int k, int dist) {
60        int n = (int)nums.size();
61        k -= 1;
62        SmartWindow window(k);
63        for(int i = 1; i <= 1 + dist; i ++){
64            window.add(nums[i]);
65        }
66        long long ans = window.query();
67        for(int i = 2; i + dist < n; i ++){
68            window.remove(nums[i - 1]);
69            window.add(nums[i + dist]);
70            ans = min(ans, window.query());
71        }
72        return ans + nums[0];
73    }
74};