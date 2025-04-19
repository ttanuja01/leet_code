// Last updated: 4/19/2025, 9:37:30 PM
class Solution {
public:
    long int reverse(int x){
        long int ans=0;
        while(x>0){
            int r=x%10;
            x=x/10;
            ans=ans*10+r;
        }
        return ans;
    }
    bool isPalindrome(int x) {
        if(x<0)return false;
        long int rev = reverse(x);
        return rev==x;
        
    }
};