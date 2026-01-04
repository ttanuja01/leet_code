// Last updated: 1/4/2026, 11:43:36 PM
1class Solution {
2private:
3    int factors(int n) {
4        int sum = 0, c = 0;
5        for(int i = 2; i*i <= n; i++) {
6            if(n % i == 0) {
7                int j = n / i;
8                if(j == i || c > 0) return 0;
9                sum += i + j;
10                c++;
11            }
12        }
13        if(c == 0) return 0;
14        return 1 + sum + n;
15    }
16public:
17    int sumFourDivisors(vector<int>& nums) {
18        int sum = 0;
19        for(int i = 0; i < nums.size(); i++) {
20            sum += factors(nums[i]);
21        }
22        return sum;
23    }
24};