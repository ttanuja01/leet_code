class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0; // Any number to the power of 0 is 1
        if (x == 0) return 0;   // Edge case: 0 to any power is 0
        
        long long N = n;         // Use long long to handle the case where n is INT_MIN
        if (N < 0) {
            x = 1 / x;          // If n is negative, take reciprocal of x
            N = -N;             // Convert n to positive
        }
        
        double result = 1.0;
        double power = x;
        
        while (N > 0) {
            if (N % 2 == 1) {
                result *= power;   // If N is odd, multiply the result by current power
            }
            power *= power;         // Square the power
            N /= 2;                 // Divide N by 2
        }
        
        return result;
    }
};
