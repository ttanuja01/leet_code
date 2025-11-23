// Last updated: 11/23/2025, 8:04:12 AM
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        int sum = 0;

        // Extract digits from left to right
        string s = to_string(n);
        for(char c : s) {
            if(c != '0') {
                int digit = c - '0';
                x = x * 10 + digit;
                sum += digit;
            }
        }

        // If no non-zero digits found
        if (x == 0) return 0;
        // std::cout<<x*sum<<endl;
        return x * sum;
        
    }
};